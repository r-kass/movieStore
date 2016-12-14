//
//  Transaction.cpp
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/12/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//

#include "Transaction.h"

#include "transaction.h"

//-----------------------------------------------------------------------------
// Transaction
// default constructor: initialize data members to default values
Transaction::Transaction()
:theItem(NULL), mediaType(""), transactiontype("Transaction")
{}

//-----------------------------------------------------------------------------
// Transaction
// copy constructor: takes a transaction object as its parameter. Creates a
// deep copy.
Transaction::Transaction(const Transaction& rhs)
{
    transactiontype = rhs.transactiontype;
    mediaType = rhs.mediaType;
    theItem = rhs.theItem;
}

//-----------------------------------------------------------------------------
// ~Transaction
// deconstructor: used to properly delete strings
Transaction::~Transaction()
{}

//-----------------------------------------------------------------------------
// setData
// takes a string, VideoStoreItem and customer as parameters. Sets the media
// and item and return true to signal stored transaction
bool Transaction::setData(string media, Movie* newItem,
                          Customer* theCustomer)
{
    mediaType = media;
    theItem = newItem;
    return true; //return true to indicate stored transaction
}

//--------------------------------------------------------------
//-----------------------------------------------------------------------------
// display
// display the mediaType and transactionType
void Transaction::display() const
{
    cout << mediaType << " " << transactiontype << " ";
}

//-----------------------------------------------------------------------------
// create
// return a new transaction object
Transaction* Transaction::create()
{
    return new Transaction();
}

//-----------------------------------------------------------------------------
// getMediaType
// return the media type
string Transaction::getMediaTye()
{
    return mediaType;
}

//-----------------------------------------------------------------------------
// getTransType
// return the TransTyepe
string Transaction::getTransType()
{
    return transactiontype;
}

//-----------------------------------------------------------------------------
// getItem
// return theItem
Movie* Transaction::getItem() const
{
    return theItem;
}