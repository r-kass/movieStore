/**
 File: borrow.h
 Author: Ruby Kassala and Ashley Nguyen
 Date Last Modified: 2016.12.14
 
 Description:
 Borrow is a subclass of Transaction. This class will have the basic functions
 to modify and display a Borrow Object; this class will process the transaction 
 as a Borrow object specifically.
 **/

#ifndef BORROW_H
#define BORROW_H
#include <iostream>
#include "transaction.h"

using namespace std;

class Customer;
class Borrow : public Transaction {
    
public:
    Borrow();
    Borrow(const Borrow&);
    virtual ~Borrow();
    
    //data members inherited from Transaction
    
    virtual bool setData(string, Movie*);
    virtual void display() const; //display movie and transaction types
    virtual Transaction* create(); //Create Borrow object
};

#endif