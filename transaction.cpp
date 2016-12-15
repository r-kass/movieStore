/**
 File: transaction.cpp
 Author: Ruby Kassala and Ashley Nguyen
 Date Last Modified: 2016.12.14
 
 Description:
 This class will have the basic functions to modify and display a Transaction.
 This class is the parent class for Return,Borrow, Inventory and History.
 **/

#include "transaction.h"


//**************************** Constructors ********************************\\
//**************************************************************************\\
// Default constructor:  No parameters, assigns to default values
//**************************************************************************\\

Transaction::Transaction()
:theItem(NULL), mediaType(""), typeTrans("Transaction")
{}


//**************************************************************************\\
// copy constructor that creates a deep copy of a Transaction object
//**************************************************************************\\

Transaction::Transaction(const Transaction& newTransaction){
    typeTrans = newTransaction.typeTrans;
    mediaType = newTransaction.mediaType;
    theItem = newTransaction.theItem;
}

//**************************************************************************\\
// destructor, deletes item if it exists
//**************************************************************************\\

//Transaction::~Transaction()
//{}

//**************************************************************************\\
// create, returns a new Transaction object
//**************************************************************************\\

Transaction* Transaction::create(){
    return new Transaction();
}


//**************************************************************************\\
// setData, takes a string, Movie*, and Customer* as its parameters.
//**************************************************************************\\

bool Transaction::setData(string media, Movie* newItem,
                          Customer* theCustomer){
    mediaType = media;
    theItem = newItem;
    return true; //indicates stored transaction
}

//**************************************************************************\\
// display, displays the movieType and typeTrans
//**************************************************************************\\

void Transaction::display() const{
    cout << mediaType << " " << typeTrans << " ";
}


//**************************************************************************\\
// getMediaType, returns the media type
//**************************************************************************\\

string Transaction::getMediaType(){
    return mediaType;
}


//**************************************************************************\\
// getTransType, returns the media type
//**************************************************************************\\

string Transaction::getTransType(){
    return typeTrans;
}


//**************************************************************************\\
// getItem, returns the current item
//**************************************************************************\\

//Movie* Transaction::getItem() const{
//    return theItem;
//}