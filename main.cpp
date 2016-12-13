// Created by Ruby Kassala and  Nguyen Nguyen on 11/14/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//main.cpp
// Lab4: Creates a movie store where there are 3 types of movies (comedy/classic/Drama), customers and transactions that checks out and checks back in movies.
// Read in the three files: customer, movies and transaction files and prcoess accordingly.//
//

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "business.h"
using namespace std;

int main(){
    ifstream movieFile("data4movies.txt");
    ifstream customerFile("data4customers.txt");
    ifstream commandsFile("data4commands.txt");
    
    if (!movieFile|!customerFile |!commandsFile)
    {
        cout << "File could not be opened." << endl;
        return 1;
    }
    
    Business store;
    store.buildMovies(movieFile);
    store.buildCustomers(customerFile);
    store.processTransactions(commandsFile);
    return 0;
}

