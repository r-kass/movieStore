//
//  movie.cpp
//  Lab4
//
//  Created by Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#include "movie.h"


//********************************Constructor********************************\\
//Sets al lthe private members to empty strings and 0
//**************************************************************************\\

Movie::Movie()
{
    director="";
    title="";
    year=0;
    stock=0;
    genre=' ';
}

//********************************Deconstructor********************************\\

Movie::~Movie()
{
    //do nothing
}

//********************************SetData********************************\\
//Reads in the file and sets the private data members to the appropriate info
//**************************************************************************\\

void Movie::setData(const string& input)
{
    stringstream movieDetails;
    movieDetails << input;   //put the infile sentence into the                             movie details to be read
    string temp;
   
    getline(movieDetails, temp, ','); //get the  genre type
    genre= temp[0];
   
    getline(movieDetails, temp, ',');     //get the stock
    stringstream(temp) >> stock;
    
    getline(movieDetails, director, ',');   //get the director
    getline(movieDetails, title, ',');     //get the title
  
    getline(movieDetails, temp, ',');
    stringstream(temp) >> year;   //get the year
    
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
