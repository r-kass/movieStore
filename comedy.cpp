//  comedy.cpp
//  Lab4
//  Created by Nguyen Nguyen and Ruby Kassala on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
////Comedy class is a child class of movie

#include "comedy.h"
#include "movie.h"

Comedy::Comedy(const string& info)
{
    setData(info);
}

//********************************equalTo********************************\\
//Check if the movie is the same movie as one already in tree
//**************************************************************************\\

bool Comedy::equalTo(const Movie* otherMovie) const
{
    bool isEqual =false;
    const Comedy* other =(const Comedy*) otherMovie;
    if((title == other->title) &&(year == other->year))
    {
        isEqual =true;
    }
    return isEqual;
}

//********************************greaterThan********************************\\
//If the movie is greater than another for displaying it alphabetically
//**************************************************************************\\

bool Comedy::greaterThan(const Movie* otherMovie)const
{
    bool greater =false;
    const Comedy* other =(const Comedy*) otherMovie;
    if((title > other ->title) || ((title >other->title) && year == other->year))
    {
        greater =true;
    }
    return greater;
}
