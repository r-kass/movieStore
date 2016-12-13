//
//  main.cpp
//  Lab4
//
//  Created by Nguyen Nguyen on 11/14/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.


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

