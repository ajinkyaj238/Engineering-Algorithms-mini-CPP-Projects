/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :February 4, 2023
* File name       :LockBox.h
* Purpose         :Contains the class definitions of lockbox
*                  for part a of the project.
 **************************************************************************/


#ifndef LOCKBOX_H
#define LOCKBOX_H
#include <iostream>
#include <vector>

using namespace std;


class LockBox
{

/*
 * Private methods of the lockbox class include the length and the range of numbers of the lockbox code along with
 * the two vectors - the password and the guess.
*/
private:
    int m, n;
    vector<int> password;
    vector<int> guess;

public:

    /* Constructor method initializes the length and range of the lockbox code. This corresponds to the variables m
       and n for the length and range respectively. The constructor then creates generates the random lockbox password
       based on the size of n or the length variable.
     * @pre none
     * @post length and range, both of type int, equal to 0. And the m and n integers are equated to
       length and range. Using a random time seed and a for loop the password is generated.
     * @param the length and range values.
     * @return none
    */
    LockBox(int length = 0, int range = 0);


    /* setCode method takes in the guess vector, clears it of any previous inputs and initializes the size of the vector
     * to n.
     * @pre none
     * @post Initialized guess vector of size n
     * @param guess vector
     * @return none
    */
    void setCode(vector<int> guess);


    /*
     * Returns the password vector.
     * @pre none
     * @post returns the password vector
     * @param guess vector
     * @return the password vector.
    */
    vector<int> getCode();


    /*
     * Generates a single random integer based on the range given by the m private variable
     * @pre none
     * @post length and range, both of type int, equal to 0
     * @param No parameter.
     * @return none
    */
    int CodeGen();


    /*
     * Iteratively compares the two vectors to find if the two numbers are the same in the same location. If found the
       the value of an integer h (initialized to equal 0) increases by 1.
     * @pre none
     * @post compares the two vectors in each place.
     * @param lockbox object that contains the guess vector.
     * @return the integer h.
    */
    int correctLocation(LockBox item);


    /*
     * Returns the number of common digits in incorrect locations.
     * @pre none
     * @post Finds the common digits in the incorrect locations using for loops and a new vector that stores common
             digits.
     * @param LockBox object.
     * @return none
    */
    int incorrectLocation(LockBox item);

    void setLength(int length);
    void setRange(int range);

};

#endif