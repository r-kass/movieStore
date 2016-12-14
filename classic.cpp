//
//  classic.cpp
//  Lab4
//
//  Created by Nguyen Nguyen on 12/8/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#include "classic.h"
#include <iostream>
#include <fstream>
using namespace std;

Classic::Classic():Movie()
{
    actorName= "";
    month=0;
    GENRE= "Classic";
}

Classic::~Classic()
{
 //nothing to do here
}

void Classic::setData(istream& input)
{
    input.get();
    getline(input, director, ','); // get director and deliminator comma to stop
    
    input.get();
    getline(input, title, ',');
    
    input.get();
    getline(input, actorName, ',');
    input >> month >> year;
}

void Classic::display()
{
    cout << title << setw(10) << director <<setw(10) << actorName << setw(10) << month << setw(5) << year << endl;
}

/*
virtual bool operator==(const Classic&) const;
virtual bool operator<(const Classic&) const;
virtual MovieFactory* create(); //create new classic movie object
virtual void displayHeader() const; //header for classic movie
*/
