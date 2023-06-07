/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :February 4, 2023
* File name       :SmartClient.cpp
* Purpose         :Contains the class implementations of smartClient for
*                  part b of the project.
 **************************************************************************/

#include <iostream>
#include "LockBox.h"
#include "ClientFeedback.h"
#include <vector>
#include "SmartClient.h"
#include <time.h>
#include <cstdlib>

using namespace std;

/*
* Constructor method initializes the length and range of the lockbox code. This corresponds to the variables m and
* n for the length and range respectively.
*/
SmartClient::SmartClient(int length, int range) {
	m = range;
	n = length;
	
}

/*
* Constructor method initializes the length and range of the lockbox code to default length 5, range 10
*/
SmartClient::SmartClient() {
	m = 10;
	n = 5;
}


/*
* Function takes client guess and creates a lockbox representing it
* 
*/
LockBox SmartClient::clientGuess(vector<int> guess1) {
	LockBox* obj = new LockBox(n, m);
	obj->setCode(guess1); // sets guess code
	return *obj;
}


/*
* Takes guess and returns client feedback object
*/
ClientFeedback SmartClient::getFeedback(LockBox* guess) {
	ClientFeedback* obj = new ClientFeedback();

	int a, b;
	// checks numbers against lock box
	a = lock->correctLocation(*guess);
	b = lock->incorrectLocation(*guess);
	obj->set_correctLocation(a);
	obj->set_incorrectLocation(b);

	return *obj;
}


/*
* checks if the box is opened
*/
bool SmartClient::isOpened(ClientFeedback *obj) {
	// correct location =  total locations
	if ((obj->get_correctLocation())==n) {
		return true;
	}
	else {
		return false;
	}
}

/*
* iteratively gets guess from user and returns feedback, until the guess is correct or the limit is reached
*/
void SmartClient::openLockBox() {

	// initilizes
	lock = new LockBox(n, m);

	// prints code
	for (int i = 0; i < n; i++) {
		cout << lock->getCode()[i] << " ";
	}
	cout << endl;


	// asks for guess
	vector<int> guess;
	cout << "Enter your first guess, one digit at a time: " << endl;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		guess.push_back(k);
	}

	// creates objects and calls function
	ClientFeedback* p = new ClientFeedback();
	LockBox* q = new LockBox;
	
	// feedback
	*q = clientGuess(guess);
	*p = getFeedback(q);
	cout << *p;
	int num = 0;

	// asks for guess until limit is reached or box is opened
	while (isOpened(p) == false && num < 10) {
		vector<int> guess1;
		cout << "Enter your guess, one digit at a time: " << endl;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			guess1.push_back(k);
		}
		*q = clientGuess(guess1);
		*p = getFeedback(q);
		cout << *p;
		num++;
	}

	if (isOpened(p)) {
		cout << "This is the correct password!";
	}
	else {
		cout << "Lock box has been disabled.";
	}
}