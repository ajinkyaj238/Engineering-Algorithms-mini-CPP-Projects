/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :February 4, 2023
* File name       :LockBox.cpp
* Purpose         :Contains the class implementations of lockbox for part a
*                  of the project.
 **************************************************************************/


#include <iostream>
#include "LockBox.h"
#include <time.h>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;


/*
* Constructor method initializes the length and range of the lockbox code. This corresponds to the variables m and
* n for the length and range respectively.
*/
LockBox::LockBox(int length, int range)
{

    m = range;
    n = length;

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int p = CodeGen();
        password.push_back(p);
    }

}


/*
 * implementation of a setter method that initializes a vector with the size of n
 */
void LockBox::setCode(vector<int> guess1)
{
    guess.clear();
    for (int i = 0; i < n; i++)
    {
        guess.push_back(guess1[i]);
    }
}


/*
 * Implementation of a simple getter function that returns the password vector.
 */
vector<int> LockBox::getCode()
{
    return password;
}


/*
 * The implementation of the codegen method essentially generates a single random digit each time.
 */
int LockBox::CodeGen()
{
    int a = rand() % m;  // Generating a random number for the variable.
    return a;
}


/*
 * Implementation of the correct location method compares each element of the password vector to each element of the
 * guess vector only in the same position.
 */
int LockBox::correctLocation(LockBox item)
{
    int h = 0;

    for (int i = 0; i < n; i++)
    {
        // comparison only takes place for the elements in the same position - i
        if (password[i] == item.guess[i])
        {
            h++;
        }
    }
    return h;

    // number of correct numbers in the right location, number of correct numbers.
}


/*
 * Implementation of the incorrect location method creates a new arbitrary vector that stores the common digits of the
 * password and the guess vectors and returns the size of the vector - which represents the number of common digits in
 * the incorrect location.
 */
int LockBox::incorrectLocation(LockBox item)
{

    vector<int> digit_memory;  // stores common integers.

    // iterates through the password vector.
    for (int i = 0; i < password.size(); i++)
    {

        // if a common variable exists then the for loop runs. set to false from the start.
        bool exists = false;
        // only execute if there is something stored
        if (digit_memory.size() > 0)
        {
            for (int j = 0; j < digit_memory.size(); j++)
            {
                if (password[i] == digit_memory[j])
                {
                    /*
                     * If a common digit already exists in the vector, the next code block does not need to run.
                     * Code becomes more efficient.
                     */

                    exists = true;
                }
            }
        }

        // runs if the value does not exist in the password vector.
        if(exists == false)
        {

            // for loop runs for at the size of the vector itself.
            for (int t = 0; t < item.guess.size(); t++)
            {
                // the number cannot be counted if the guess position is the same place as the password position.
                if(i != t)
                {
                    if (password[i] == item.guess[t])
                    {
                        // adds the newly found common digit into memory
                        digit_memory.push_back(password[i]);
                    }
                }
            }

        }


    }


    // size of the vector is just the number of common integers.
    return digit_memory.size();

}

void LockBox::setLength(int length) {
    n = length;
}

void LockBox::setRange(int range) {
    m = range;
}