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
    Customer* del = head;
    while (del != NULL) {
        head = head->next;
        del->info = NULL;
        delete del;
        del = head;
    }
    // Empty vector
    history.clear();
}

// setCustomer()
// Sets Customer id
void Customer::setCustomer(int custID){
    idNumber = custID;
}

// getID()
// Returns Customer  id

int Customer::getID() const {
    return idNumber;
}


// getHistory ()
// Returns Customers transaction history as a vector

const vector<Transaction *> Customer::getHistory() const{
    return history;
}

/*
 DISPLAY HISTORY
 Purpose: Prints customer history of borrowing and returning movies
 Post Conditions: Displays customer history
 */
void Customer::displayHistory(){
    cout << endl;
    cout << "_____________________________________________________________________________" << endl;
    cout << endl;
    cout << getCustomerData() << endl << endl << "Customer History:" << endl;
    CustomerHistory* current = head;
    
    while (current != NULL)         {        // Traverse linkd list and insert info into vector
    
        if (current->transaction == 'B')
            history.push_back("Borrowed a" + current->info->printCustomerInfo());
        else if (current->transaction == 'R')
            history.push_back("Returned a" + current->info->printCustomerInfo());
        current = current->next;
    }
    
    vector<string>::reverse_iterator it;    // Print the history from the earliest to oldest
    for (it = history.rbegin(); it != history.rend(); ++it)
        cout << *it << endl;                // Print history
    cout << "_____________________________________________________________________________" << endl;
    cout << endl;
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
    //history.push_back(Trans); //Add transaction pointer to vector
    
    CustomerHistory* ptr = new CustomerHistory;         // Allocate new ptr
    ptr->transaction = type;                            // Point to transaction type
    ptr->info = movie;                                  // Point to the movie
    ptr->next = NULL;                                   // Next is null
    // First transaction                                // First pointer in the list
    if (head == NULL){
        ptr->next = head;
        head = ptr;
    }
    else{
        CustomerHistory* current = head;
        
        while (current->next != NULL)                   // Loop until the las elemenet in the list
            current = current->next;
        current->next = ptr;                            // Add ptr to a list
    }
    return true;
}
