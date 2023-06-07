/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :February 4, 2023
* File name       :SmartClient.h
* Purpose         :Contains the class definitions of smartClient for part b
*                  of the project.
 **************************************************************************/

#ifndef SMARTCLIENT_H
#define SMARTCLIENT_H
#include <iostream>
#include "LockBox.h"
#include "ClientFeedback.h"
#include <vector>

using namespace std;

class SmartClient
{

/*
 * Private data members of the smartclient class include the predetermined range and size values of the vectors.
 */
private:
	int m = 10, n = 5;
	LockBox* lock;
public:
    /* Constructors method of Smartclient initializes the range and size values to 5 and 10. And have them equal to the
     * length and range.
     * @pre none
     * @post created objects based on the constructors.
     * @param range and length integers.
     * @return object
    */
	SmartClient(int range, int length);
	SmartClient();


    /* Creates new lockbox object.
     * @pre none
     * @post new lockbox object created
     * @param guess vector
     * @return lockbox object.
    */
	LockBox clientGuess(vector<int> guess1);


    /*creates client feedback object.
     * @pre none
     * @post client feedback object and sets the correct and incorrect integers of client feedback
     * @param lockbox object
     * @return clientfeedback object.
    */
	ClientFeedback getFeedback(LockBox* guess);


    /* checks if lockbox can be opened.
     * @pre none
     * @post none
     * @param clientfeedback pointer object.
     * @return true or false.
    */
	bool isOpened(ClientFeedback* obj);


    /* opens the lockbox with a cout
     * @pre none
     * @post cout displayed on terminal
     * @param none
     * @return none.
    */
	void openLockBox();
};

#endif