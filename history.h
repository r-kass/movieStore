//
//  history.h
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/12/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//

#ifndef history_h
#define history_h
#include "transaction.h"
#include <stdio.h>
class history: public transaction {
    
    
    virtual void doTransaction();
    virtual void setData();

    
    
};


#endif /* history_h */
