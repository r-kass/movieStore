/**
 File: History.h
 Author: Ruby Kassala and Ashley Nguyen
 Date Last Modified: 2016.12.14
 
 Description:
 History is a subclass of Transaction. This class will have the basic functions
 to modify and display a History Object; this class will process the transaction
 as a History object specifically.
 
 The following functions create, modify and display a History object.
 **/

#include "History.h"

//**************************** Constructors ********************************\\
//**************************************************************************\\
// Default constructor:  No parameters, sets History as typeTrans
//**************************************************************************\\

History::History() :Transaction() {
    typeTrans = "History"; //type of transaction used for display
}

//**************************************************************************\\
// copy constructor that creates a deep copy of a History object
//**************************************************************************\\

History::History(const History& newHistory){
    typeTrans = newHistory.typeTrans;
    mediaType = newHistory.mediaType;
    theItem = newHistory.theItem;
}

//**************************************************************************\\
// destructor, deletes item if it exists
//**************************************************************************\\

History::~History()
{}


//**************************************************************************\\
// create, History a new History object
//**************************************************************************\\

Transaction* History::create(){
    return new History();
}


//**************************************************************************\\
// setData, takes a string and Movie* as its parameters.
//**************************************************************************\\

bool History::setData(string media, Movie* newMovie, Customer* cust){
    
    cust->getHistory(); //display customers history
    return false; //return false to signal not a stored transaction
    
}
//**************************************************************************\\
// display, displays the movieType and typeTrans which is "History"
//**************************************************************************\\

void History::display() const {
    cout << mediaType << " " << typeTrans << " "; //used for display
}


