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
#include <string>

class Drama : public Movie
{
public:
    Drama(const string& info);
    ~Drama();
    static const char GENRE='D'; //genre set to comedy
    virtual void display() const; //display movie data
    virtual void displayHeader() const; //header for drama movie
    bool equalTo(const Movie*) const;
    bool greaterThan(const Movie*) const;

protected:
    
};

#endif /* drama_h */
