//
//  classic.hpp
//  Lab4
//
//  Created by Nguyen Nguyen on 12/8/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#ifndef classic_h
#define classic_h
#include "movie.h"
#include <stdio.h>

class Classic : public Movie{
public:
    Classic();
    ~Classic();
    
    virtual void setData(istream&); //set movie data
    virtual void display() const; //display movie data
    virtual bool operator==(const Classic&) const;
    virtual bool operator<(const Classic&) const;
    virtual Movie* create(); //create new classic movie object
    virtual void displayHeader() const; //header for classic movie
    
private:
    const string GENRE; //genre set to classic
    int month;
    string actorFirst;
    string actorLast;
    
};



#endif /* classic_h */
