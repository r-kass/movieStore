//
//  Borrow.h
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/12/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//

#ifndef Borrow_h
#define Borrow_h
#include "transaction.h"
#include <stdio.h>
class Borrow: public Transaction {
    
    virtual void doTransaction();
    virtual void setData();
    void display();
    
};


#endif /* Borrow_h */
