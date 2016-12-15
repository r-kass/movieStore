//
//  classic.hpp
//  Lab4
//
//  Created by Nguyen Nguyen on 12/8/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.

#ifndef classic_h
#define classic_h
#include "movie.h"
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

class Classic : public Movie
{
public:
    Classic(const string& info);
    ~Classic();
    static const char mediaType ='D';
    static const char GENRE ='C'; //genre set to classic
    virtual void display() const; //display movie data
    bool equalTo(const Movie*) const;
    bool greaterThan(const Movie*) const;
    virtual void displayHeader() const; //header for classic movie
    
protected:
    void setData(const string& data); //set movie data
    int month;
    string actorName;
    
};



#endif /* classic_h */
