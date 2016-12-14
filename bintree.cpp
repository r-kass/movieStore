//  Created by Nguyen Nguyen on 10/20/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//10.22.16
//  bintree.cpp
//This program creates a inary searcg tree class called Bintree that will be able to read in a data fie
//and build binary search trees with the file input, and no repeat input used as well. The class is able to
//overload and search for a certain data using pointers as well as using the given NodeData class.
//**************************************************************************\\

#include "bintree.h"
#include "movie.h"
#include "movieFactory.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

//******************************Constructors********************************\\
//**************************************************************************\\
//Assigns the first node root to be Null
//**************************************************************************\\

BinTree::BinTree()
{
    this->root=NULL;
}

//**************************************************************************\\
// destructor, calls makeEmpty
//**************************************************************************\\

BinTree::~BinTree()
{
    if(root!= NULL)
    {
        makeEmpty(); //clears out all the nodes and it's associated data values
    }
}

// true if tree is empty, otherwise false
bool BinTree::isEmpty() const
{
    bool empty = true;
    if(this->root != NULL)
    {
        empty =false;
    }
    return empty;
}

//**************************************************************************\\
// make the tree empty so isEmpty returns true
//**************************************************************************\\

void BinTree::makeEmpty()
{
    if(!isEmpty())
    {
        deleteTracker(this->root);  //calls recursive delete function
    }
}

//**************************************************************************\\
//assist in tracking the current node, recursively, to delete all left and right nodes fromt the
//bottom to the top. Sets the node data to null then deletes the ptr and sets the position to null.
//**************************************************************************\\

void BinTree::deleteTracker(Node*& current)
{
    if (current != NULL)    // post order traversal
    {
        deleteTracker(current->left);     // go to the left
        deleteTracker(current->right);    // go to the right
        if (current->data != NULL)
        {
            delete current->data;   // deletes the data
            current->data = NULL;
        }
        delete current;
        current = NULL; //deletes and sets node to Null
    }
}

//Overload Operators
//**************************************************************************\\
//Equality Overload Operator, states if or not two trees are exactly the same
//**************************************************************************\\

bool BinTree::operator==(const BinTree &compare) const
{
    bool equal=false; //initialize a boolena to false
    
    if(this->root ==NULL && compare.root ==NULL)
    { //both are empty trees
        equal=true; //thus equal
        return equal; //return
    }
    
    return equalCheck(this->root, compare.root); //if the above didn't return then run
    //equalCheck to go down the tree and check
}

//**************************************************************************\\
//Equality Overload Helper, systematically checks of left and right are the same
//recursviely goes down the BST to check if it's equal, if one is different it's false
//**************************************************************************\\

bool BinTree::equalCheck(Node* left, Node* right) const
{
    //Check whether the node data is the same
    if ((left != NULL && right != NULL) && (*left->data == *right->data))
    {
        return true;
    }
    //Return false when reached the end
    if ((left == NULL) || (right == NULL))
    {
        return false;
    }
    
    //Check data and then assign each one to the next left and the next right to repeat check
    return ((left->data == right->data) && equalCheck(left->left, right->left ) && equalCheck (left->right, right->right));
}

//**************************************************************************\\
//inequality Operator, states two trees aren't the exact same
//**************************************************************************\\

bool BinTree:: operator!=(const BinTree &a) const
{
    
    if(*this == a) //used the equalty operator overload
    {
        return false;
    }
    return true;
}

//Assister functions
//**************************************************************************\\
//Insert function w/while look to insert a datapoint into a given BST in the right order
//
//**************************************************************************\\

bool BinTree::insert(Movie* insertData)
{
    bool insert=false;
    
    Node* newMovie= new Node;
    newMovie->data =insertData;
    insertData=NULL;
    newMovie->left =NULL;
    newMovie->right =NULL;// new ptr
    
    if (isEmpty())
    {  //if it's empty then found =false, return
        this->root =newMovie;		// set a current Node ptr to root
    }
    else
    {
        Node* current = root;
        
        //Check if data is less than, greater than, or equal to the current data
        while (!insert)
        {
            if (*newMovie->data == *current->data) //duplicate, remove
            {
                delete newMovie;
                newMovie=NULL;
                insert =false;
                return insert;
            }
            else if (*newMovie->data < *current->data)
            {
                if (current->left== NULL) // at leaf, insert left
                {
                    current->left = newMovie;
                    insert = true;
                }
                else
                {
                    current = current->left; //moves current to it's leaf node and then it'll go back
                    //to the while loop and retest the above scenarios
                }
            }
            else if(*newMovie->data > *current->data)
            {
                if(current->right == NULL)
                {
                    current->right = newMovie;
                    insert = true;
                }
                else
                {
                    current = current->right; //moves current to it's leaf node and then it'll go back
                    //to the while loop and retest the above scenarios
                }
            }
            else     //data must be equal to a the current data and so don't insert
            {
                delete newMovie;   //delete ptr
                newMovie=NULL;     //set to null
                return insert;       //insert is still at false
            }
        }
    }
    return insert;
}

//**************************************************************************\\
//Get the nodeData of a given object passed in by reference in the tree
//if that NodeData is found, then you set the NodeData pointer to it. If not found, setTo may have
//random junk info at initially
//**************************************************************************\\

bool BinTree::retrieve(MovieFactory* moviePtr, int amountIn) const
{
    bool found=false; //declares a boolean
    
    if (isEmpty()) {  //if it's empty then found =false, return
        return found;
    }
    else  //traverse the BST
    {
        movieNode* current = root;		// set a current Node ptr to root
        
        while (!found) {
            if (lookFor == *current->data) //if found
            {
                // on find, set passed pointer and exit loop
                setTo = current->data;
                found = true;
            }
            else if(lookFor < *current->data)  //if less than data then go check left
            {
                if (current->left == NULL) {
                    return found;
                }
                else
                {
                    current = current->left; //Instead of recursion, goes back to while loop and
                    //goes further down the children
                }
            }
            else if (lookFor > *current->data) //if greater than current data, go check right
            {
                if (current->right == NULL)
                {
                    return found;
                }
                else
                {
                    current = current->right; //Instead of recursion, goes back to while loop
                }
            }
        }
    }
    return found;
}

//****************************Accessors******************************//
//**************************************************************************\\
//Output overload to display the tree using inorder Traversal.
//Precondition: NodeData class will display it's own data
//**************************************************************************\\

ostream& operator<<(ostream& output, const BinTree &a)
{
    a.inorderHelper(a.root);
    output << endl;
    return output;
}

//*************************Ostream helper********************************************\\
//Output overload helper to display the tree using inorder Traversal.
//Prints left, center, then right.
//Precondition: NodeData class will display it's own data
//**************************************************************************\\

void BinTree::inorderHelper(Node* current) const
{
    if (current != NULL)  // traverse and print data
    {
        inorderHelper(current->left);
        cout << *current->data << " ";
        inorderHelper(current->right);
    }
}
