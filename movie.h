
//  movie.h
//  Lab4
//  Created by Ruby Kassala and Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//This class is an abstract parent class that wil be used by the children classes of the differnet movie genres Classic, Drama and Comedy. 

#ifndef movie_h
#define movie_h
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

class Movie
{
public:
     Movie();
    virtual ~Movie();
    bool increment(int stockIncrease);
    bool decrement();
    virtual int getStock();
    virtual string display() const =0;
    virtual bool equalTo(const Movie*) const =0;
    virtual bool greaterThan(const Movie*) const =0;
    
protected:
    void setData(const string& input);
    char genre;
    string director;
    int year;
    int stock;
    string title;
};

#endif /* movie_hpp */
