//
//  business.hpp
//  Lab4
//
//  Created by Nguyen Nguyen on 12/10/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//

#ifndef business_h
#define business_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "movie.h"
#include "bintree.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"
#include "movieFactory.h"
#include "hashtable.h"
#include "customer.h"

class Business{
public:
    Business(); //empty
    ~Business(); //empty
    void buildMovies(istream& input);
<<<<<<< HEAD
    void buildCustomer(istream& input);
    void processTransactions(istream& input);
  //void display(); //not listed in her example but maybe good to display all movies?
=======

    //void buildCustomer(istream& input);

   // void processTransactions(istream& input);
    void display(); //not listed in her example but maybe good to display all movies?


>>>>>>> 470437ffcb282d561f1d1a3dd7712f39cc3be3d8
    
private:
    HashTable* allCustomers;
    Transaction* currentTrans;
    
    BinTree allComedies;
    BinTree allDramas;
    BinTree allClassics;
};
#endif /* business_h */
