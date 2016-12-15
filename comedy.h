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
    static const char mediaType ='D';
    static const char GENRE= 'F'; //genre set to comedy
    
    bool equalTo(const Movie* otherMovie) const;
    bool greaterThan(const Movie* otherMovie) const;
    virtual void displayHeader() const; //header for comedy movie

private:
   
};

#endif /*comedy_h*/
