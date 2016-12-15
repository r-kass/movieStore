#ifndef transaction_h
#define transaction_h

/**
 File: Transaction.h
 Author: Ruby Kassala and Ashli Nguyen
 
 Purpose:
 The TransactionFactory class has a factory method to create transactions.
 **/

#include <stdio.h>
#include "transaction.h"
#include "borrow.h"
#include "returns.h"
#include "history.h"
#include "business.h"
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
using namespace std;

class TransactionFactory {
public:
    static Transaction* createTransaction(const char&);   
};
#endif