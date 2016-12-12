//
//  business.hpp
//  Lab4
//
//  Created by Nguyen Nguyen on 12/10/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#ifndef business_h
#define business_h
#include "movie.h"
#include "bintree.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"
#include "hashtable.h"
#include <stdio.h>
#include <iostream>

class Business{
public:
    Business();
    ~Business();
    void buildMovies(istream& input);
    void buildCustomers(istream& input);
    void processTransactions(istream& input);
    //void display(); //not listed in her example but maybe good to display all movies?
    
private:
    HashTable* allCustomers;
    Transaction* currentTrans;
    BinTree* allComedies;
    BinTree* allDramas;
    BinTree* allClassics;
};
#endif /* business_h */
