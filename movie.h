
//  movie.hpp
//  Lab4
//
//  Created by Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#ifndef movie_h
#define movie_h
#include "bintree.h"
#include <stdio.h>
#include <string>
using namespace std;

class Movie
{
   
/*
private:
    string title;
    char genre;
    
    string media= "DVD";  //current data type is only DVD for now

public:
 
    void setData();
    virtual void display() const;
    bool borrowMovie();
    bool returnMovie();
*/
    
public:
    bool increment(int stockIncrease);
    bool decrement();
    virtual int getStock();
    virtual bool operator < (const Movie*) const =0;
    virtual bool operator == (const Movie*) const =0;
    
protected:
    Movie();
    string director;
    int year;
    int stock;
    string title;
};

#endif /* movie_hpp */
