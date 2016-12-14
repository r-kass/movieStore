//
//  comedy.hpp
//  Lab4
//
//  Created by Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#ifndef comedy_h
#define comedy_h
#include <stdio.h>
#include "movie.h"

//
class Comedy : public Movie{
public:
    Comedy();
    ~Comedy();
    static const char GENRE= 'F'; //genre set to comedy

    virtual void setData(istream&); //set movie data
    virtual void display() const; //display movie data
    virtual bool operator==(const Movie* otherMovie) const;
    virtual bool operator<(const Movie* otherMovie) const;
    virtual void displayHeader() const; //header for comedy movie

private:
   
};

#endif /*comedy_h*/
