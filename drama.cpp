//
//  drama.cpp
//  Lab4
//
//  Created by Nguyen Nguyen on 12/8/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#include "drama.h"

bool Drama::operator==(const Movie* otherMovie) const
{
    bool isEqual =false;
    const Drama* other =(const Drama*) otherMovie;
    if((title == other->title) &&(director == other->director))
    {
        isEqual =true;
    }
    return isEqual;
}

bool Drama::operator<(const Movie* otherMovie) const
{
    bool greater =false;
    const Drama* other =(const Drama*) otherMovie;
    if((director > other ->director) || ((title >other->title) && director == other->director))
    {
        greater =true;
    }
    return true;
}
