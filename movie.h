
//  movie.h
//  Lab4
//  Created by Ruby Kassala and Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//This class is an abstract parent class that wil be used by the children classes of the differnet movie genres Classic, Drama and Comedy. 

#ifndef movie_h
#define movie_h
#include "bintree.h"
#include <stdio.h>
#include <string>
using namespace std;

class Movie
{
   
/*
 public:
    virtual void display() const;
    bool borrowMovie();
    bool returnMovie();
*/
    
public:
     Movie();
    ~Movie();
    virtual void setData(istream& input);
    bool increment(int stockIncrease);
    bool decrement();
    virtual int getStock();
    virtual bool operator < (const Movie*) const =0;
    virtual bool operator == (const Movie*) const =0;
    
protected:
   
    string director;
    int year;
    int stock;
    string title;
};

#endif /* movie_hpp */
