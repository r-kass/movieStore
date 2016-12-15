/**
 File: History.h
 Author: Ruby Kassala and Ashley Nguyen
 Date Last Modified: 2016.12.14
 
 Description:
 History is a subclass of Transaction. This class will have the basic functions
 to modify and display a History Object; this class will process the transaction
 as a History object specifically.
 **/

#ifndef History_H
#define History_H
#include <iostream>
#include "transaction.h"

using namespace std;

class Customer;
class History : public Transaction {
    
public:
    History();
    History(const History&);
    virtual ~History();
    
    //data members inherited from Transaction
    
    virtual bool setData(string, Movie*, Customer*);
    virtual void display() const; //display movie and transaction types
    virtual Transaction* create(); //Create History object
};

#endif