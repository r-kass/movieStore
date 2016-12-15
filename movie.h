
//  movie.h
//  Lab4
//  Created by Ruby Kassala and Nguyen Nguyen on 11/30/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//This class is an abstract parent class that wil be used by the children classes of the differnet movie genres Classic, Drama and Comedy. 

#ifndef movie_h
#define movie_h
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

class Movie
{
public:
     Movie();
    virtual ~Movie();
    static const char mediaType ='D'; //stands for DVD
   // static const char GENRE;
    bool increment(int stockIncrease);   //increase stock
    bool decrement();                   //decrease stock
    virtual int getStock();             //return stock amount
    virtual void display() const =0;      //print out movies
    virtual void displayHeader() const =0;
    virtual bool equalTo(const Movie*) const =0;     //check equivalent movies
    virtual bool greaterThan(const Movie*) const =0;   //for alphabetizing
    
    
protected:
    void setData(const string& input);    //setting data
    string director;
    int year;
    int stock;
    string title;
    char genre;
};

#endif /* movie_hpp */
