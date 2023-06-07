/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :February 4, 2023
* File name       :ClientFeedback.cpp
* Purpose         :Contains the class implementations of ClientFeedback
*                  class for part b of the project.
 **************************************************************************/



#include "ClientFeedback.h"
#include "LockBox.h"

// all the implementations of the clientfeedback class below. 
ClientFeedback::ClientFeedback(int c_l_n, int inc_l_n):correctlocation_number(c_l_n), incorrectlocation_number(inc_l_n)
{
    correctlocation_number = c_l_n;  // setting to 0
    incorrectlocation_number = inc_l_n;
}

// implementation of set correctLocation
void ClientFeedback::set_correctLocation(int cnl)
{
    correctlocation_number = cnl;
}
void ClientFeedback::set_incorrectLocation(int incnl)
{
    incorrectlocation_number = incnl;
}



int ClientFeedback::get_correctLocation()
{
    return correctlocation_number;
}
int ClientFeedback::get_incorrectLocation()
{
    return incorrectlocation_number;
}


bool ClientFeedback::operator == (ClientFeedback &rhs)
{
    if (correctlocation_number == rhs.correctlocation_number && incorrectlocation_number == rhs.correctlocation_number)
    {
        return true;
    }
    else
    {
        return false;
    }
}


ostream& operator << (ostream &os, ClientFeedback& rhs)
{
    os << "Correct number of numbers in the correct location are: " <<
    rhs.get_correctLocation() << endl << "The Incorrect number of numbers in incorrect locations are: " <<
    rhs.get_incorrectLocation() << endl;

    return os;
}