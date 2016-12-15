/**
 File: customer.cpp
 Author: Ruby Kassala and Ashley Nguyen
 Date Last Modified: 2016.12.14
 
 Description:
 This class will have the basic functions to create and modify a Customer's
 information in the system.

 **/


#include "customer.h"
#include <iostream>


//**************************** Constructor ********************************\\
//**************************************************************************\\
// Default constructor:  No parameters
//**************************************************************************\\

Customer::Customer() {}



//**************************************************************************\\
// Destructor: deletes vector with customer history.
//**************************************************************************\\

Customer:: ~Customer(){
    // Empty vector
    history.clear();
}

Customer::Customer(const Customer& cust){
    idNumber = cust.idNumber;
    firstName = cust.firstName;
    lastName = cust.lastName;
}

/*
 COPY CONSTRUCTOR
 Purpose: Create an instance of a Customer based on another existing Customer
 Post Conditions: An exact copy of Customer
 */
Customer::Customer(int id, string last, string first) {
    idNumber = id;
    firstName = first;
    lastName = last;
}

//**************************************************************************\\
// setCustomer: sets customer ID
//**************************************************************************\\

void Customer::setCustomer(int custID){
    idNumber = custID;
}

//**************************************************************************\\
// getID: returns customer ID
//**************************************************************************\\

int Customer::getID() const {
    return idNumber;
}


//**************************************************************************\\
// getHistory: returns customer transaction history as a vector.
//**************************************************************************\\

const vector<Transaction *> Customer::getHistory() const{
    return history;
}

//**************************************************************************\\
// getFirstName: returns customer's first name
//**************************************************************************\\

const string &Customer::getFirstName() const {
    return firstName;
}

//**************************************************************************\\
// setFirstName: sets Customer's first name
//**************************************************************************\\

void Customer::setFirstName(const string & fname){
    firstName = fname;
}

//**************************************************************************\\
// getLastName: returns Customer's last name
//**************************************************************************\\

const string &Customer::getLastName() const{
    return lastName;
}

//**************************************************************************\\
// setLastName: sets Customer's last name
//**************************************************************************\\

void Customer::setLastName(const string & lname){
    lastName = lname;
}

//**************************************************************************\\
// addTransaction: adds to transactions vector
//**************************************************************************\\

void Customer::addTransaction(Transaction Trans){
    history.push_back(Trans); //Add transaction pointer to vector
}
