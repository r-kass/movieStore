//
//  movieFactory.hpp
//  Lab4
//
//  Created by Nguyen Nguyen on 12/10/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#ifndef movieFactory_h
#define movieFactory_h
#include "movie.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MovieFactory{
    
public:
    MovieFactory();
    ~MovieFactory();
    //included in MA
    static Movie* createMovie(const string&); //create pointer to movie object
   /*
    virtual void setData(istream&) = 0;
    
    virtual void display() const;
    virtual void displayHeader() const;
    virtual string getItem() const;
    void setMaxCopies(const int);
    void increaseCopies();
    void decreaseCopies();
    int getAmountIn();
    int getAmountOut();
    
    virtual bool operator==(const MovieFactory&) const = 0;
    virtual bool operator<(const MovieFactory&) const = 0;
   */ 
private:
    int maxCopies;
    int numberOfCopies;
    char genre;
    
};
#endif /* movieFactory_h */
