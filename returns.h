//
//  Returns.h
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/12/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//

#ifndef returns_h
#define returns_h
#include "transaction.h"
#include <stdio.h>
using namespace std;

class Returns: public Transaction {
    
public:
    virtual void doTransaction();
    virtual void setData();
    void display();
    
};


#endif /* Returns_h */
