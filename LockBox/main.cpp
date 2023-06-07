/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :February 4, 2023
* File name       :main.cpp
* Purpose         :contains the main dialogue options of the program
 **************************************************************************/

#include <iostream>
#include "LockBox.h"
#include <time.h>
#include <string>
#include <vector>
#include <cstdlib>
#include "ClientFeedback.h"
#include "SmartClient.h"
using namespace std;


// part b
int main() {
	int a, b;

	cout << "Enter the length of the password: " << endl;
	cin >> a;

	cout << "Enter the range of numbers used (0 - m): " << endl;
	cin >> b;

	SmartClient* smart = new SmartClient(a, b);

	smart->openLockBox();


}

/*
// part a
int main() {

	int a, b;

	cout << "Enter the length of the password: " << endl;
	cin >> a;

	cout << "Enter the range of numbers used (0 - m): " << endl;
	cin >> b;

	LockBox* box = new LockBox(a, b);
	LockBox* guess = new LockBox(a, b);
	int num = 0;

	vector<int> guess1;
	cout << "Enter your guess, one digit at a time: " << endl;
	for (int i = 0; i < a; i++) {
		int k;
		cin >> k;
		guess1.push_back(k);
	}
	guess->setCode(guess1);
	cout << "Correct number of numbers in the correct location are: " << box->correctLocation(*guess) << endl;
	cout << "The Incorrect number of numbers in incorrect locations are: " << box->incorrectLocation(*guess) << endl;

	
	while (box->correctLocation(*guess) != a && num < 10) {
		vector<int> guess1;
		cout << "Enter your guess, one digit at a time: " << endl;
		for (int i = 0; i < a; i++) {
			int k;
			cin >> k;
			guess1.push_back(k);
		}
		guess->setCode(guess1);
		cout << "Correct number of numbers in the correct location are: " << box->correctLocation(*guess) << endl;
		cout << "The Incorrect number of numbers in incorrect locations are: " << box->incorrectLocation(*guess) << endl;
	}

	if (box->correctLocation(*guess) == a) {
		cout << "The lockbox has been opened!";
	}
	else {
		cout << "The lockbox has been disabled";
	}

}
*/
