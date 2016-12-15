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
#include "string.h"
using namespace std;

class MovieFactory{
public:
    static Movie* createMovie(const string&); //create pointer to movie object
};
#endif /* movieFactory_h */
