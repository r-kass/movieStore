//
//  drama.hpp
//  Lab4
//
//  Created by Nguyen Nguyen on 12/8/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#ifndef drama_h
#define drama_h
#include "movie.h"
#include <stdio.h>

class Drama : public Movie{
public:
    Drama();
    ~Drama();
    
    virtual void setData(istream&); //set movie data
    virtual void display() const; //display movie data
    virtual bool operator==(const Drama&) const;
    virtual bool operator<(const Drama&) const;
    virtual Movie* create(); //create new drama movie object
    virtual void displayHeader() const; //header for drama movie
    
private:
    const string GENRE; //genre set to comedy
};

#endif /* drama_h */
