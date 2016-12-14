//
//  movie.cpp
//  Lab4
//
//  Created by Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#include "movie.h"
using namespace std;

Movie::Movie(){
    string director="";
    string title="";
    int year=0;
    int stock=0;
    
}

bool Movie::increment(int stockIncrease)
{
    bool increase;
    if(stockIncrease <=0)
    {
        return false;
    }else{
        stock+=stockIncrease;
        increase =true;
    }
    return increase;
}

bool Movie::decrement()
{
    bool decrease;
    if(stock <=0)
    {
        return false;
    }
    else
    {
        stock--;
        decrease =true;
    }
    return decrease;
}

int Movie::getStock()
{
    return stock;
}
