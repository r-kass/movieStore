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
#include <iomanip>
using namespace std;

//********************************Constructor********************************\\
//Calls setdata function to read in details
//**************************************************************************\\

Classic::Classic(const string& info)
{
    setData(info);
}

//********************************Deconstructor********************************\\

Classic::~Classic()
{
 //nothing to do here
}

//********************************Set Data********************************\\
//SReads in the string like an file and save them to appropriate data members
//**************************************************************************\\

void Classic::setData(const string& input)
{
    stringstream movieDetails;
    movieDetails << input;   //put the infile sentence into the                             movie details to be read
    string temp;
    
    getline(movieDetails, temp, ','); //get the  genre type
    genre= temp[0];
    
    getline(movieDetails, temp, ',');     //get the stock
    stringstream(temp) >> stock;
    
    getline(movieDetails, director, ',');   //get the director
    getline(movieDetails, title, ',');     //get the title
    
    getline(movieDetails, temp, ',');
    stringstream(temp) >> year;   //get the year
    
    movieDetails >> temp;
    actorName =actorName +temp + ' ';  //first name
    movieDetails >>temp; //first plus last
    actorName= actorName+temp;
    
    movieDetails >> month;             // Add month
    movieDetails >> year;             // Add month}
}


//********************************equalTo********************************\\
//Check if the movie is the same movie as one already in tree
//**************************************************************************\\

bool Classic::equalTo(const Movie* otherMovie) const
{
    bool isEqual =false;
    const Classic* other =(const Classic*) otherMovie;
    if((month == other->month)&&(year == other->year) &&(actorName == other->actorName))
    {
        isEqual =true;
    }
    return isEqual;
}

//********************************greaterThan********************************\\
//If the movie is greater than another for displaying it alphabetically
//**************************************************************************\\

bool Classic::greaterThan(const Movie* otherMovie) const
{
    bool greater =false;
    const Classic* other =(const Classic*) otherMovie;
    if((year > other ->year) || ((month >other->month) && (year == other->year)) || ((month ==other->month) && (year == other->year) && (actorName > other->actorName)))
    {
        greater =true;
    }
    return greater;
}

void Classic::display() const
{
    cout << title << setw(10) << director <<setw(10) << actorName << setw(10) << month << setw(5) << year << endl;
}

//********************************Display Header********************************\\
//prints out the movies
//**************************************************************************\\

void Classic::displayHeader() const{ //header for classic movie
    cout << GENRE << endl;
    cout << "DVD    DVD TITLE              DIRECTOR         YEAR" << endl;
}


