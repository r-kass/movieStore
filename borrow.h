//
//  borrow.h
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/12/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//

#ifndef borrow_h
#define borrow_h
#include "transaction.h"
#include <stdio.h>
class borrow: public transaction {
    
    virtual void doTransaction();
    virtual void setData();
    void display();
    
};


#endif /* borrow_h */
