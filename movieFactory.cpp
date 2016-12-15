//  movieFactory.cpp
//  Lab4
//  Created by Nguyen Nguyen on 12/10/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#include "movieFactory.h"
using namespace std;

Movie* MovieFactory::createMovie(const string& data)
{
    Movie* movieType =NULL;
    switch(data[0])
    {
        case Comedy::GENRE:
            movieType =(Movie*) new Comedy(data); //created a new comedy objected with
            break;
        case Classic::GENRE:
            movieType =(Movie*) new Classic(data); // created new classic movie
            break;
        case Drama::GENRE:
            movieType =(Movie*) new Drama(data); //created new drama
            break;
        default:             //error, don't create anything
            movieType=NULL;
            break;
    }
    return movieType;
}
