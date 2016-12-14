//
//  Show.h
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/12/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//

#ifndef Show_h
#define Show_h
#include "transaction.h"
#include <stdio.h>
class Show: public Transaction {
    
    
    virtual void doTransaction();
    virtual void setData();
    
};


#endif /* Show_h */
