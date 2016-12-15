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
    virtual string display() const; //display movie data
    virtual void displayHeader() const; //header for drama movie

protected:
    virtual bool equalTo(const Movie*) const;
    virtual bool greaterThan(const Movie*) const;

};

#endif /* drama_h */
