//
//  business.cpp
//  Lab4
//
//  Created by Nguyen Nguyen on 12/10/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#include "business.h"
#include <iostream>
#include <stdio.h>
#include <ifstream>
using namespace std;

Business::Business()
{
 //nothing to do unless we wnat to include business name
}

Business::~Business()
{
 //nothing to do here
}

void Business::buildMovies(istream& input)
{
    string entireLine;

    for(;;)
    {
        getline(input, entireLine);
        
        if(input.eof())
        {
            break;
        }
        Movie* newMovie = MovieFactory::createMovie(entireLine);
        switch(entireLine[0])
        {
            case Comedy::GENRE:
                allComedies.insert(newMovie);
            case Classic::GENRE:
                allClassics.insert(newMovie);
            case Drama::GENRE:
                allDramas.insert(newMovie);
            default:
                cout >> "error in entry, not a valid movie";
                break;
        }
    }

}

void Business::processTransactions(istream& input)
{
    //*********************************************************
    //*********************************************************
    //*********************************************************
    //*********************************************************
}
