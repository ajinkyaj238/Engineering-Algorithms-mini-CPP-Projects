/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :February 4, 2023
* File name       :ClientFeedback.h
* Purpose         :Contains the class definitions of ClientFeedback class
*                  for part b of the project.
 **************************************************************************/



#ifndef CLIENTFEEDBACK_H
#define CLIENTFEEDBACK_H
#include <iostream>
#include <cstring>
#include "LockBox.h"
using namespace std;

class ClientFeedback
{

/*
 * Private methods of the ClientFeedback class include the output of the lockbox methods that return the number of
 * correct and incorrect location numbers in the guess.
*/
private:
    int correctlocation_number, incorrectlocation_number;


public:

    /* Constructor method of ClientFeedback initializes the arbitrary correct length number and incorrect length number
     * to 0.
     * @pre none
     * @post The values are set to 0 and the correct number location and incorrect number locations have been equated
     * to the correct location number and the incorrect locaton number private data members.
     * @param correct locatio number and incorrect locatio number.
     * @return none
    */
    ClientFeedback(int c_l_n = 0, int inc_l_n = 0);


    // setter functions


    /* setter function that sets the correct location private data member to the passed integer from smartclient
     * @pre none
     * @post set correct location is equal to passed integer.
     * @param correct location number (int)
     * @return none
    */
    void set_correctLocation(int cnl);


    /* setter function that sets the incorrect location private data member to the passed integer from smartclient
     * @pre none
     * @post set incorrect location is equal to passed integer. ne
     * @param incorrect location number (int)
     * @return none
    */
    void set_incorrectLocation(int incnl);


    //getter functions

    /* getter function returns the value of the correct location
     * @pre none
     * @post return value
     * @param none
     * @return correctlocation_number
    */
    int get_correctLocation();


    /* getter function returns the value of the incorrect location
     * @pre none
     * @post return value
     * @param none
     * @return correctlocation_number
    */
    int get_incorrectLocation();


    /* Operator overloading function compares the correct number location to see if its equal to the rhs. Likewise to
     * the incorrect number location.
     * to n.
     * @pre none
     * @post compares the two object integers.
     * @param object.
     * @return returns true or false.
    */
    bool operator == (ClientFeedback &rhs);

};

/* Global Operator overload for '<<'
 * @pre none
 * @post
 * @param client feedback object.
 * @return couts the response.
*/
ostream& operator << (ostream& os, ClientFeedback& rhs);

#endif