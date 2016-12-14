/**
 File: Returns.h
 Author: Ruby Kassala and Ashley Nguyen
 Date Last Modified: 2016.12.14
 
 Description:
 Returns is a subclass of Transaction. This class will have the basic functions
 to modify and display a Returns Object; this class will process the transaction
 as a Returns object specifically.
 **/

#ifndef Returns_H
#define Returns_H
#include <iostream>
#include "transaction.h"

using namespace std;

class Customer;
class Returns : public Transaction {
    
public:
    Returns();
    Returns(const Returns&);
    virtual ~Returns();
    
    //data members inherited from Transaction
    
    virtual bool setData(string, Movie*);
    virtual void display() const; //display movie and transaction types
    virtual Transaction* create(); //Create Returns object
};

#endif