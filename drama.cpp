//
//  drama.cpp
//  Lab4
//
//  Created by Nguyen Nguyen on 12/8/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#include "drama.h"
#include <iomanip>

Drama::Drama(const string& info){
    setData(info);
}

//********************************equalTo********************************\\
//Check if the movie is the same movie as one already in tree
//**************************************************************************\\

bool Drama::equalTo(const Movie* otherMovie) const
{
    bool isEqual =false;
    const Drama* other =(const Drama*) otherMovie;
    if((title == other->title) &&(director == other->director))
    {
        isEqual =true;
    }
    return isEqual;
}


//********************************greaterThan********************************\\
//If the movie is greater than another for displaying it alphabetically
//**************************************************************************\\

bool Drama::greaterThan(const Movie* otherMovie) const
{
    bool greater =false;
    const Drama* other =(const Drama*) otherMovie;
    if((director > other ->director) || ((title >other->title) && director == other->director))
    {
        greater =true;
    }
    return greater;
}

//********************************Display Header********************************\\
//prints out the movies
//**************************************************************************\\

void Drama::displayHeader() const{ //header for classic movie
    cout << GENRE << endl;
    cout << "DVD    DVD TITLE              DIRECTOR         YEAR" << endl;
}

