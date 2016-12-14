//
//  movieFactory.cpp
//  Lab4
//
//  Created by Nguyen Nguyen on 12/10/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//
#include <iostream>
#include <fstream>
#include "movieFactory.h"

Movie* MovieFactory::createMovie(const string& entireLine)
{
    Movie* movieType =NULL;
    switch(entireLine[0])
    {
        case Comedy::GENRE:
            movieType =(Movie*) new Comedy(); //created a new comedy objected with
            break;
        case Classic::GENRE:
            movieType =(Movie*) new Classic(); // created new classic movie
            break;
        case Drama::GENRE:
            movieType =(Movie*) new Drama(); //created new drama
            break;
        default:             //error, don't create anything
            movieType=NULL;
            break;
    }
}
