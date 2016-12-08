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

#include "movie.h"
#include <stdio.h>

class BinTree {
public:
    BinTree();								// constructor
    BinTree(const BinTree &a);				// copy constructor
    ~BinTree();								// destructor, calls makeEmpty
    bool isEmpty() const;					// true if tree is empty, otherwise false
    void makeEmpty();						// make the tree empty so isEmpty returns true
    
    //Overload Operators
    BinTree& operator=(const BinTree &compare);    //Assignment Operator,assigns one tree to another
    bool operator==(const BinTree &a) const; //Equality Operator, states two trees are exactly the same
    bool operator!=(const BinTree &a) const; //inequality Operator, states two trees aren't the exact same
   
    //Assister functions
    bool insert(Movie* insertData);
    bool retrieve(const NodeData &a, NodeData* &b) const; //Get the nodeDara of a given object in the tree if it exists
   // void displaySideways() const;			// provided by instructor Chen
  
    //Accessors
    friend ostream& operator<<(ostream& output, const BinTree &a); //displt the inorder traversal
    int getHeight (const NodeData &a) const; //Finds the hegiht of a given value in the tree, if height isnt
    //found it returns 0, else returns height
    
    //Conversions
    void bstreeToArray(NodeData* []);
    void arrayToBSTree(NodeData* []);
    
private:
    struct Node {
        NodeData* data;						// pointer to data object
        Node* left;							// left subtree pointer
        Node* right;						// right subtree pointer
    };
    
    Node* root;								// root of the tree
    
    // utility&helper functions
    void inorderHelper(Node* current) const;
    void sideways(Node*, int) const; //provided by instructor
    void deleteTracker(Node*& current);
    void copyTree(Node* current, Node*& newPtr) const;
    bool equalCheck(Node* left, Node* right) const;
    int heightHelper(const NodeData &toFind, Node* current) const;
    int secondHeightHelper(Node* current) const;
    int bST2AHelper(Node* current, NodeData* array[]);
    void Arr2BSTHelper(Node *current, NodeData* copyFrom[], int low, int high);
};

#endif /* bintree_h */
