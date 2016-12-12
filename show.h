//
//  show.h
//  assignment4_implementation
//
//  Created by Ruby Kassala on 12/12/16.
//  Copyright © 2016 Ruby Kassala. All rights reserved.
//

#ifndef show_h
#define show_h
#include "transaction.h"
#include <stdio.h>
class show: public Transaction {
    
    
    virtual void doTransaction();
    virtual void setData();
    
};


#endif /* show_h */
