//  Created by Nguyen Nguyen on 10/20/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//10.22.16
//  bintree.cpp
//  Lab2
//This program creates a inary searcg tree class called Bintree that will be able to read in a data fie
//and build binary search trees with the file input, and no repeat input used as well. The class is able to
//overload and search for a certain data using pointers as well as using the given NodeData class.


#ifndef bintree_h
#define bintree_h

#include "movieFactory.h"
#include "movie.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

class BinTree {
public:
    BinTree();							// constructor
    BinTree(const BinTree &a);			// copy constructor
    ~BinTree();							// destructor, calls makeEmpty
    
    //Functions to change BST
    bool isEmpty() const;				// true if tree is empty, otherwise false
    void makeEmpty();					// make the tree empty so isEmpty returns true
    
    //Overload Operators
    bool operator==(const BinTree &a) const; //Equality Operator, states two trees are exactly the same
    bool operator!=(const BinTree &a) const; //inequality Operator, states two trees aren't the exact same
    
    //Assister functions
    bool insert(Movie* insertData);
    void displayMovies();
    Movie* retrieve(Movie* &a); //Get the nodeDara of a given object in the tree if it exists
    
private:
    struct Node{
        Movie* data;						// pointer to data object
        Node* left;					// left subtree pointer
        Node* right;					// right subtree pointer
    };
    
    Node* root;								// root of the tree
    
    // utility&helper functions
    Movie* retrieveHelper(Node*& node, Movie* find_data);
    void inorderHelper(Node* current) const;
    void deleteTracker(Node*& current); //assist in makeempty()
    bool equalCheck(Node* left, Node* right) const;
    
};

#endif /* bintree_h */
