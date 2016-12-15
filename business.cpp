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
#include "customer.h"
using namespace std;

Business::Business(){
 //nothing to do unless we wnat to include business name
}

//Business::~Business() {
 //nothing to do here
//}

void Business::buildMovies(istream& input){
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
              cout << "error in entry, not a valid movie";
                break;
        }
    }
}

void Business::buildCustomer(istream& input) {
    
    while (!input.eof()){
        
        //read in and store customer id
        string temp;
        int id;
        getline(input, temp, ' ');
        stringstream(temp) >> id;
        
        //read in and store last name of customer
        string lName;
        getline(input, lName, ' ');
        
        // read in and store first name of customer
        string fName;
        getline(input, fName);
        
        //create new customer object
        Customer*  person = new Customer(id, lName, fName);
        
        //insert into hash table and make sure it was valid
        //if not delete person
        bool worked = allCustomers.insertCustomer(id, person);
        if (!worked)
            delete person;
    }
}

        /*
        //get the genre type for movie
        if(genre == 'F'| genre =='D'| genre=='C'){
            MovieFactory* moviePtr=factory.create(genre);
            moviePtr=0;
        }else{
            input.ignore(256,'\n');
        }
        if(moviePtr !=NULL){
            moviePtr ->setData(input);
            insert(moviePtr, amount);
        }
     */  

//void Business::buildCustomers(istream& input){
//    Customer b = *new Customer();
 //   cout << b.getFirstName();
 //   cout << b.getLastName();
 //   cout << b.getHistory();
//}


void Business::processTransactions(istream& input)
{
    //*********************************************************
    //*********************************************************
    //*********************************************************
    //*********************************************************
}
