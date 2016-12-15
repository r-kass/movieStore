//
//  transactionFactory.cpp
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/14/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//

#include "transactionFactory.h"

Transaction* TransactionFactory::createTransaction(const char& type) {
    
    Transaction  * tranPtr= NULL;     // Pointer to Transaction
    switch (type)  {              // Get first character of string array
            
        case 'B':
            tranPtr= new Borrow();        // Allocate Borrow
            break;
        case 'R':
            tranPtr= new Returns();        // Allocate Return
            break;
        case 'H':
            tranPtr= new History();       // Allocate History
            break;
        default:
            tranPtr= NULL;                // Allocate NULL
            break;
    }
    return tranPtr;                    // Return tran
}