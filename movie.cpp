//
//  movie.cpp
//  Lab4
//
//  Created by Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#include "movie.h"
#include "bintree.h"
using namespace std;

//********************************Constructor********************************\\
//Sets al lthe private members to empty strings and 0
//**************************************************************************\\

Movie::Movie()
{
    string director="";
    string title="";
    int year=0;
    int stock=0;
    
}

//********************************Deconstructor********************************\\

Movie::~Movie()
{
    //do nothing
}

//********************************SetData********************************\\
//Reads in the file and sets the private data members to the appropriate info
//**************************************************************************\\

void Movie::setData(istream& input){
    
    input.get();
    input.ignore();   //ignore genre we checked already
    
    input.get();
    input>> stock;     //get the stock
    
    input.get();
    getline(input, director, ','); //get the director
    
    input.get();
    getline(input, title, ',');  //get the title
    
    input.get();
    input >> year;       //get the year
    
}

//********************************Increment Stock****************************\\
//Increases the stock # for a certain movie //in classic it can be incremented by an int not just 1
//**************************************************************************\\

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

//********************************Decrement Stock*****************************\\
//Sdecreases the stock # for a certain movie by 1
//**************************************************************************\\

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

//********************************Getter Fxn********************************\\
//returns stock number from private data
//**************************************************************************\\

int Movie::getStock()
{
    return stock;
}
