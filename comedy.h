//
//  comedy.hpp
//  Lab4
//
//  Created by Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#ifndef comedy_h
#define comedy_h
#include "movie.h"
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Comedy : public Movie
{
public:
    Comedy(const string& info);
    ~Comedy();
    static const char GENRE= 'F'; //genre set to comedy

    virtual void setData(istream&); //set movie data
    virtual string display() const; //display movie data
    bool equalTo(const Movie* otherMovie) const;
    bool greaterThan(const Movie* otherMovie) const;
    virtual void displayHeader() const; //header for comedy movie

private:
   
};

#endif /*comedy_h*/
