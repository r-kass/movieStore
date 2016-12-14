//
//  Customer.hpp
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/8/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//



#include <stdio.h>
#ifndef Customer_h
#define Customer_h

//#include "movie.h"
#include "BinTree.h"
#include "transaction.h"
#include <stdio.h>
#include <iostream>
//include <string>
#include <vector>
//include <list>

using namespace std;

class Transaction;
class Customer {
    
public:
    // constructors
    Customer();
    ~Customer();
  //  Customer(istream &stream);

    
    
    // functions
    
    const vector<Transaction *> getHistory() const;

    int getID() const;
    void setCustomer(int cid);
    void displayCustomer();
    
    const string &getFirstName() const;
    void setFirstName(const string & fname);
    
    const string &getLastName() const;
    void setLastName(const string & lname);
    
    
    //add to transaction
    void addTransaction(Transaction Trans);
//    void borrowMedia(Media *media);
//    bool returnMedia(Media *media);
    
private:
    int idNumber;
    string firstName;
    string lastName;
    vector<Transaction> history;
//    list<Media *> borrowed;
};

#endif /* Customer_h */