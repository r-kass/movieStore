//
//  Customer.cpp
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/8/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//

#include "customer.h"
#include <iostream>

// +Customer ()
// Creates an Customer object

Customer::Customer() {}

// +~Customer
// Destructs Customer object


Customer::~Customer(){
    history.clear();
}

// setCustomer()
// Sets Customer id

void Customer::setCustomer(int custID){
    idNumber = custID;
}

// DisplayCustomer()
// Prints Customer object

/*void Customer::displayCustomer(){
    // set preceding 0 for 4 digit ID
    // for IDs less than 4 digits
    string zeros = "";
    if (idNumber< 10)
        zeros = "000";
    else if (idNumber < 100)
        zeros = "00";
    else if (idNumber < 1000)
        zeros = "0";
    
    // print Customer info
    cout << zeros << idNumber  << "    ";
    cout.width(10);
    cout << left << firstName;
    cout.width(10);
    cout << left << lastName << endl;
}
*/

// getID()
// Returns Customer  id

int Customer::getID() const {
    return idNumber;
}

//addTransaction????????

// getHistory ()
// Returns Customers transaction history as a vector

const vector<Transaction *> Customer::getHistory() const{
    return history;
}



// getFirstName
// Returns Customer's first name

const string &Customer::getFirstName() const {
    return firstName;
}

// setFirstName
// Description: sets Customer first name

void Customer::setFirstName(const string & fname){
    firstName = fname;
}

// getLastName
// Description: returns Customer's last name

const string &Customer::getLastName() const{
    return lastName;
}

// setLastName
// Description: sets Customers last name

void Customer::setLastName(const string & lname){
    lastName = lname;
}



void Customer::addTransaction(Transaction Trans){
    history.push_back(Trans); //Add transaction pointer to vector
}
