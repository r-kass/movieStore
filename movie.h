
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

class Movie
{
/*
private:
    string title;
    char genre;
    
protected:
    string director;
    int year;
    int stock;
   // string title;
    string media= "DVD";  //current data type is only DVD for now

public:
    static Movie getType(char genre);
    //bool increment;
    //bool decrement;
    virtual bool operator<(const Movie&) const;
    virtual bool operator ==(const Movie&) const;
    void setData();
    virtual void display() const;
    bool borrowMovie();
    bool returnMovie();
*/
public:
    virtual bool operator < (const Movie*) const;
    virtual bool operator == (const Movie*) const;
    
    
protected:
    string director;
    int year;
    int stock;
    string title;
};

#endif /* movie_hpp */
