/**
 File: borrow.h
 Author: Ruby Kassala and Ashley Nguyen
 Date Last Modified: 2016.12.14
 
 Description:
 Borrow is a subclass of Transaction. This class will have the basic functions
 to modify and display a Borrow Object; this class will process the transaction
 as a Borrow object specifically.
 
 The following functions create, modify and display a Borrow object.
 **/

#include "borrow.h"

//**************************** Constructors ********************************\\
//**************************************************************************\\
// Default constructor:  No parameters, sets Borrow as typeTrans
//**************************************************************************\\

Borrow::Borrow() :Transaction() {
    typeTrans = "Borrow"; //type of transaction used for display
}

//**************************************************************************\\
// copy constructor that creates a deep copy of a Borrow object
//**************************************************************************\\

Borrow::Borrow(const Borrow& newBorrow){
    typeTrans = newBorrow.typeTrans;
    mediaType = newBorrow.mediaType;
    theItem = newBorrow.theItem;
}

//**************************************************************************\\
// destructor, deletes item if it exists
//**************************************************************************\\

Borrow::~Borrow()
{}


//**************************************************************************\\
// create, returns a new Borrow object
//**************************************************************************\\

Transaction* Borrow::create(){
    return new Borrow();
}


//**************************************************************************\\
// setData, takes a string and Movie* as its parameters.
//**************************************************************************\\

bool Borrow::setData(string media, Movie* newMovie){
    
    if (newMovie != NULL){ //Dont do anything if movie is NULL
    
        mediaType = media; //Set Data
        theItem = newMovie;
    }
    return true;
}
//**************************************************************************\\
// display, displays the movieType and typeTrans which is "Borrow"
//**************************************************************************\\

void Borrow::display() const {
    cout << mediaType << " " << typeTrans << " "; //used for display
}


