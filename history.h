//
//  History.h
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/12/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//

#ifndef History_h
#define History_h
#include "transaction.h"
#include <stdio.h>
class History: public transaction {
    
    
    virtual void doTransaction();
    virtual void setData();

    
    
};


#endif /* History_h */
