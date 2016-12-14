//
//  Transaction.h
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/12/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//

#ifndef Transaction_h
#define Transaction_h

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
    //set data for moie and media type
    virtual bool setData(string, Movie*, Customer*);
    virtual void display() const; //display mediatype and transactiontype
    virtual Transaction* create(); //create new transaction object
    
    string getMediaTye(); //Get type of media
    string getTransType(); //default transType is transaction
    VideoStoreItem* getItem() const; //Pointer to VideoStoreItem
    
protected:
    string transactiontype;
    string mediaType;
    VideoStoreItem* theItem;
};
#endif

#endif /* Transaction_h */
