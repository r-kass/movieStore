//
//  comedy.cpp
//  Lab4
//
//  Created by Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#include "comedy.h"

bool Comedy::operator==(const Movie* otherMovie) const
{
    bool isEqual =false;
    const Comedy* other =(const Comedy*) otherMovie;
    if((title == other->title) &&(year == other->year))
    {
        isEqual =true;
    }
    return isEqual;
}

bool Comedy::operator<(const Movie& otherMovie) const
{
    bool greater =false;
    const Comedy* other =(const Comedy*) otherMovie;
    if((title > other ->title) || ((title >other->title) && year == other->year))
    {
        greater =true;
    }
    return true;
}
