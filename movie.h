
//  movie.hpp
//  Lab4
//
//  Created by Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//
#include "bintree.h"
#ifndef movie_h
#define movie_h
#include <stdio.h>

class Movie : BinTree
{
    
protected:
    string dirFirstName;
    string dirLastName;
    int year;
    int stock;
    string title;
    string media= "DVD";  //current data type is only DVD for now

public:
    //bool increment;
    //bool decrement;
    virtual bool operator<(const Movie&) const;
    virtual bool operator ==(const Movie&) const;
    void setData();
    virtual void display() const;
    bool borrowMovie();
    bool returnMovie();

};

#endif /* movie_hpp */
