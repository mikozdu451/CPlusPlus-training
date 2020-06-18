//
// Created by pumpk on 24.01.2020.
//

#ifndef UNTITLED2_FUNCTIONS_H
#define UNTITLED2_FUNCTIONS_H

#include "structures.h"
/**The functions creates a new ticket singly linked list passed on the input from the txt file
 *
 * @param t pointer to adress of the list of the tickets
 * @param ID input ID of the flight from the txt file
 * @param ori origin of the flight from the txt file
 * @param date date of the flight from the txt file
 * @return next ticket in a list
 */
ticket * addTicket(ticket *&t, const std::string &ID, const std::string &ori, const std::string &dist);

/**The function reads input file and calls addTicket function
 *
 * @param t pointer to address of the list of the tickets
 * @param file_name name of the file to be read
 */
void readTEXTfile(ticket *& t, const std::string & file_name);

/**The function searches for proper ticket and calls isertPassegenr function
 *
 * @param t pointer to address of the list of the tickets
 * @param ID address of the ID of the flight from the pointer towards the list
 * @param ori address of the origin of the flight from the pointer towards the list
 * @param date address of the date of the flight from the pointer towards the list
 * @param p address of the the passenger of the flight from the pointer towards the list
 * @param seat address of the seat of the passenger from the pointer towards the list
 */
void addPassenger(ticket *&t,const std::string &ID,const std::string &ori,const std::string &dist,const std::string &p,const int &seat);

/**The function insets passenger to ticket
 *
 * @param pH pointer to adress to the BTree of the passengers
 * @param p address of the name of the passenger
 * @param seat address of the seat of the passenger
 */
void insertPassenger(passenger *&pH,const std::string &p,const int &seat);
/**The function makes output file using ticket
 *
 * @param t pointer to adress of the list of tickets
 */
void makeTXTfile(ticket * t);

/**The function deletes passengers from BTree
 *
 * @param p pointer to address of passenger in BTree
 */
void deletePassenger(passenger *&p);
/**
 *
 * @param t pointer to address of ticket in a list
 */
void deleteTicket(ticket *&t);



#endif //UNTITLED2_FUNCTIONS_H
