//
// Created by pumpk on 24.01.2020.
//

#ifndef UNTITLED2_STRUCTURES_H
#define UNTITLED2_STRUCTURES_H

#include <string>
struct passenger              ///<Passenger structure
{
    std::string name;         ///<Name of the passenger
    int seat;                 ///<Seat of the passenger
    passenger * pRight;       ///<Pointer to the right child in tree
    passenger * pLeft;        ///<Pointer to the left child in tree

};

struct ticket                 ///<Ticket structure
 {
    std::string flightID;     ///<ID of the flight
    std::string origin;       ///<Origin city of the flight
    std::string date;         ///< Date of the flight

    passenger * nPass;        ///<Pointer to the head of the passenger tree

    ticket * next;            ///<Pointer to the next ticket in the list

};





#endif //UNTITLED2_STRUCTURES_H
