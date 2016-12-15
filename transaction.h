/**
 File: transaction.h
 Author: Ruby Kassala and Ashley Nguyen
 Date Last Modified: 2016.12.14
 
 Description:
 This class will have the basic functions to modify and display a Transaction. 
 This class is the parent class for Return,Borrow, Inventory and History.
 **/

#include <stdio.h>

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "movie.h"
using namespace std;
class Customer;
class Transaction
{
    
    
public:
    
    Transaction();
    Transaction(const Transaction&);
    virtual ~Transaction();
    
    virtual bool setData(string, Movie*, Customer*);
    virtual void display() const;      //display mediatype and transactiontype
    virtual Transaction* create();     //create new transaction object
    
    string getMediaType();
    string getTransType();
    
protected:
    string typeTrans;
    string mediaType;
    Movie* theItem;
};

#endif /* Transaction_h */
