/**
 File: Returns.h
 Author: Ruby Kassala and Ashley Nguyen
 Date Last Modified: 2016.12.14
 
 Description:
 Returns is a subclass of Transaction. This class will have the basic functions
 to modify and display a Returns Object; this class will process the transaction
 as a Returns object specifically.
 
 The following functions create, modify and display a Returns object.
 **/

#include "Returns.h"

//**************************** Constructors ********************************\\
//**************************************************************************\\
// Default constructor:  No parameters, sets Returns as typeTrans
//**************************************************************************\\

Returns::Returns() :Transaction() {
    typeTrans = "Returns"; //type of transaction used for display
}

//**************************************************************************\\
// copy constructor that creates a deep copy of a Returns object
//**************************************************************************\\

Returns::Returns(const Returns& newReturns){
    typeTrans = newReturns.typeTrans;
    mediaType = newReturns.mediaType;
    theItem = newReturns.theItem;
}

//**************************************************************************\\
// destructor, deletes item if it exists
//**************************************************************************\\

Returns::~Returns()
{}


//**************************************************************************\\
// create, returns a new Returns object
//**************************************************************************\\

Transaction* Returns::create(){
    return new Returns();
}


//**************************************************************************\\
// setData, takes a string and Movie* as its parameters.
//**************************************************************************\\

bool Returns::setData(string media, Movie* newMovie){
    
    if (newMovie != NULL){ //Dont do anything if movie is NULL
        
        mediaType = media; //Set Data
        theItem = newMovie;
    }
    return true;
}
//**************************************************************************\\
// display, displays the movieType and typeTrans which is "Returns"
//**************************************************************************\\

void Returns::display() const {
    cout << mediaType << " " << typeTrans << " "; //used for display
}


