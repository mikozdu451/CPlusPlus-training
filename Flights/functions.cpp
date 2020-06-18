//
// Created by pumpk on 24.01.2020.
//

#define debug(x)  std::cerr << "(" << __LINE__ << ") " << #x << " == " << (x) << std::endl

#include <list>
#include <ostream>
#include <fstream>
#include <iostream>
#include <string>

#include "functions.h"
#include "structures.h"


using namespace std;
const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const std::string &s) {
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}


string rtrim(const std::string &s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}


string trim(const std::string &s) {
    return rtrim(ltrim(s));
}


ticket *addTicket(ticket *&t, const string &ID, const string &ori, const string &dist) //function for adding new tickets
{
    if (t == nullptr) //if there are no tickets
    {
        t = new ticket{ID, ori, dist, nullptr, nullptr}; //add new ticket
        return t; //return the ticket
    } else {
        ticket *pt = t;    //create a pointer to thde ticket
        while (pt)           //while there is a ticket
        {
            if (pt->flightID == ID) // if the ticket ID matches the ID of currently being read strings ID
                return pt;         //return ticket
            else {
                if (pt->next == nullptr) //if there are no more tickets
                {
                    pt->next = new ticket{ID, ori, dist, nullptr, nullptr};   //add a new ticket
                    return pt->next;                                                     //return the ticket
                }
            }
            pt = pt->next; // go to the next tixket
        }
    }
    return nullptr;
}


void insertPassenger(passenger *&pH, const string &p, const int &seat) //function for adding passengers
{
    if (pH == nullptr)                                               //if there are no passangers in a flight
        pH = new passenger{p, seat, nullptr, nullptr};
    else {
        passenger *tmp = pH;
        if (tmp->seat > seat)                                      //if the seat number is greater than the number
            insertPassenger(tmp->pLeft, p, seat);
        else if (tmp->seat <= seat)                                 //if the seat number is lesser than the number
            insertPassenger(tmp->pRight, p, seat);


    }
}


void addPassenger(ticket *&t, const string &ID, const string &ori, const string &dist, const string &p, const int &seat) //function to start adding new tickets and passangers
{
    ticket *tmp = addTicket(t, ID, ori, dist);     //call function for adding new tickets
    insertPassenger(tmp->nPass, p, seat);             //call function for adding new passengers

}


bool datecheck(int y, int m, int d) {

    if (y > 0 && y <= 9999 && m > 0 && m <= 12) {
        switch (m) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (d > 0 && d <= 31)
                    return true;
            case 4:
            case 6:
            case 9:
            case 11:
                if (d > 0 && d <= 30)
                    return true;
            case 2:
                if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
                    if (d > 0 && d <= 29)
                        return true;
                } else if (d > 0 && d <= 28)
                    return true;

            default:
                return false;


        }
    }
    return false;
}


void readTEXTfile(ticket *&t, const string &file_name) {        //function to read the text files
    string line;
    string f, o, d, dCopy, p, s;
    string Y, M, D;
    int year, month, day;
    ifstream file(file_name);


    // open txt file
    if (file.is_open()) {  //check
        while (getline(file, line)) {
            if(!line.empty()) {
                line = trim(line);


                f = line.substr(0, line.find(' '));  //read the first part of the string the flight ID
                line = ltrim(line.substr(line.find(' ') + 1));     //move to the next part

                o = line.substr(0, line.find(' '));  //read the second part of the string rhe origin of the flight
                line = ltrim(line.substr(line.find(' ') + 1));
                d = line.substr(0, line.find(' '));  //read the date of the flight
                dCopy = d;


                Y = dCopy.substr(0, dCopy.find('-'));
                dCopy = dCopy.substr(dCopy.find('-') + 1);


                M = dCopy.substr(0, dCopy.find('-'));
                dCopy = dCopy.substr(dCopy.find('-') + 1);

                D = dCopy;



                cout<<"1";
                year = stoi(Y);
                month = stoi(M);
                day = stoi(D);
//            cout << year << " ---------------- " << month << " ----------------- " << day << endl;
                if (datecheck(year, month, day)) {

                    line = ltrim(line.substr(line.find(' ') + 1));

                    p = line.substr(0, line.find(' ')); //read the name of the passenger
                    line = ltrim(line.substr(line.find(' ') + 1));

                    s = line.substr(0, line.find(' ')); //read the seat number of the passenger
                    line = ltrim(line.substr(line.find(' ') + 1));

                    int seat = stoi(s);
                    cout<<"2"<<endl;                        //transform the string of the passengers seat into an int

                    addPassenger(t, f, o, d, p, seat);    //start the functiuon for creating the list and trees
                }
            }
        }
    }
    file.close();
}


void printBTree(passenger *pIN, ofstream &filename) {
    if (filename.is_open()) {
        auto p = pIN;
        if (p->pLeft != nullptr)
            printBTree(p->pLeft, filename);

        string s = to_string(p->seat);
        filename << string(p->name) + " " + string(s) << endl;

        if (p->pRight != nullptr)
            printBTree(p->pRight, filename);
    }
}


void makeTXTfile(ticket *t) {
    while (t) {

        ofstream file{t->flightID};

        if (file) {
            file << "Flight number " << t->flightID << " on " << t->date << " from " << t->origin << endl;
            file << "List of passangers ono that filght: " << endl;
            if (t->nPass != nullptr) {
                printBTree(t->nPass, file);
            } else {
                file << "There were no passangers on this flight!";
            }
        } else
            cout << "something's wrong";
        file.close();

        t = t->next;
    }
}

void deletePassenger(passenger *&p) {
    if (p) {
        deletePassenger(p->pLeft);
        deletePassenger(p->pRight);
        delete (p);
    }
}


void deleteTicket(ticket *&t) {
    if (t) {
        deleteTicket(t->next);
        deletePassenger(t->nPass);
        delete (t);
    }
}
