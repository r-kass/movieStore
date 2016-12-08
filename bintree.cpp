//  Created by Nguyen Nguyen on 10/20/16.
//  Copyright © 2016 Nguyen Nguyen. All rights reserved.
//10.22.16
//  bintree.cpp
//  Lab2
//This program creates a inary searcg tree class called Bintree that will be able to read in a data fie
//and build binary search trees with the file input, and no repeat input used as well. The class is able to
//overload and search for a certain data using pointers as well as using the given NodeData class.
//**************************************************************************\\

#include "bintree.h"
#include "nodedata.h"
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
// copy constructor that creates a deep copy of a BST tree
//**************************************************************************\\

BinTree::BinTree(const BinTree &a)
{
    copyTree(a.root, this->root); //Calls upon the helper function
}

//**************************************************************************\\
// destructor, calls makeEmpty
//**************************************************************************\\

BinTree::~BinTree()
{
    makeEmpty(); //clears out all the nodes and it's associated data values
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
//Assignment Operator,assigns one tree to another by checking if it's not the same.
//then delete the left hand tree, deep copy the right hand tree to the left.
//**************************************************************************\\

BinTree& BinTree::operator=(const BinTree &a)
{
    if (*this != a)  //check if it's not already the same
    {
        deleteTracker(this->root);  // delete entire current tree
        copyTree(a.root, this->root);  // copy the tree like a deep copy constructor
    }
    return *this;
}

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

bool BinTree::insert(NodeData* insertData)
{
    bool insert=false;
    
    Node* insertNode = new Node;  //creates a new Node for the data to be inserted
    insertNode->data = insertData;    //assigns the data to the current data being pointed to
    //initialize everything to Null
    insertData=NULL;
    insertNode->left = NULL;
    insertNode->right = NULL;
    
    if (isEmpty())
    {
        this->root = insertNode; //empty, set as root
        insert=true;
    }
    else
    {
        Node* current = root;
    
        //Check if data is less than, greater than, or equal to the current data
        while (!insert)
        {
            if (*insertNode->data < *current->data)
            {
                if (current->left== NULL) // at leaf, insert left
                {
                    current->left = insertNode;
                    insert = true;
                }
                else
                {
                    current = current->left; //moves current to it's leaf node and then it'll go back
                                            //to the while loop and retest the above scenarios
                }
            }
            else if(*insertNode->data > *current->data)
            {
                if(current->right == NULL)
                {
                    current->right = insertNode;
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
                delete insertNode;   //delete ptr
                insertNode=NULL;     //set to null
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

bool BinTree::retrieve(const NodeData & lookFor, NodeData* & setTo) const
{
    bool found=false; //declares a boolean
    
    if (isEmpty()) {  //if it's empty then found =false, return
         return found;
    }
    else  //traverse the BST
    {
        Node* current = root;		// set a current Node ptr to root
        
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
//**************************************************************************\\
//Took from the Data structure book by Frank Carrano pg.463.
//It'll make a copy of the tree via recursion
//**************************************************************************\\

void BinTree::copyTree(Node* current, Node*& newPtr) const
{
    // Uses preorder traversal
    if (current != NULL) //if Null then nothing to copy
    {
        newPtr = new Node; //Create new Node object for copy
        NodeData *temp = new NodeData(*current->data); // new NodeData* object for copying
        newPtr->data = temp; //set data to be the same
        //go left in BST
        copyTree(current->left, newPtr->left);
        //go right in BST
        copyTree(current->right, newPtr->right);
    }
    else
    {
        newPtr = NULL;  //nothing to copy, initiate ptr to null
    }
}
//**************************************************************************\\
//Finds the height of a given value in the tree, if height isnt
//found it returns 0, else returns height
//**************************************************************************\\

int BinTree::getHeight (const NodeData & searchItem) const
{
    return heightHelper(searchItem, this->root);
}

//**************************************************************************\\
//Helps to find the height of the search Data.
//Got hint from:
//http://algorithms.tutorialhorizon.com/find-the-maximum-depth-or-height-of-a-binary-tree/
//**************************************************************************\\


int BinTree::heightHelper(const NodeData &toFind, Node* current) const
{
    if (current == NULL)
    {
        return 0;   // node is not in tree, return height = 0
    }
    else if (*current->data == toFind)
    {
        return secondHeightHelper(current);   // node found
    }
    else
    {
        int left = heightHelper(toFind, current->left);  // search left
        int right = heightHelper(toFind, current->right);    // search right
        return max(left, right);
    }
}

//**************************************************************************\\
//Helps to find the height of the search Data.
//Got hint from:
//http://algorithms.tutorialhorizon.com/find-the-maximum-depth-or-height-of-a-binary-tree/
//Take the Max(leftHeight, rightHeight) and add 1 for the root and return
//**************************************************************************\\

int BinTree::secondHeightHelper(Node* current) const
{
    if (current == NULL)
    {
        return 0;   // this is a leaf node, 1 being added below so this is 0
    }
    else
    {
    // counts the amount of levels in the tree from root node plus 1 for the root
    return 1 + max(secondHeightHelper(current->left), secondHeightHelper(current->right));
    }
}
 
  //**************************************************************************\\
// fill an array of Nodedata* by using an inorder traversal of the tree. It leaves the tree empty.
//**************************************************************************\\

void BinTree::bstreeToArray(NodeData* array[])
{
    if(isEmpty())
    {
        array=NULL;  //if empty then no need for array
    }
    else
    {
        bST2AHelper(this->root, array); //calls recursion
        makeEmpty();  //deletes the BST since it's been copied over
    }
}
//**************************************************************************\\
//Helper function for BST to Array using recursion to help find location of where each NodeData is at
//**************************************************************************\\

int BinTree::bST2AHelper(Node* current, NodeData* array[])
{
    if (current == NULL)
    {
        return 0;   // BST is empty
    }
    
    int left = bST2AHelper(current->left, array);
    
    NodeData *temp;         //temp ptr created
    temp = current->data;   // saves current data to temp
    current->data = NULL;   //current is no longer pointing to data
    *(array + left) = temp; //array points to temp
    temp = NULL;
    
    int right = bST2AHelper(current->right, array + left + 1);
    
    int position = left + right + 1; // return position
   
    return position;
}

//**************************************************************************\\
//builds a balanced BinTree from a sorted array of NodeData* leaving the array filled with NULLs.
//The root (recursively) is at (low+high)/2 where low is the lowest subscript of the array range
//and high is the highest.
//**************************************************************************\\

void BinTree::arrayToBSTree(NodeData* array[])
    {
    this->makeEmpty(); //Clears out the current BST
    int getSize=0;
   
    //goes through array up to 100 null values, checks when array is not NUll to count the array size
    for(int i=0; i < 100; i++){
        if(array[i] != NULL){
            getSize++;
        }else{
            array[i]=NULL;
        }
    }
    
    //Recursively call helper function
    Arr2BSTHelper(root,array, 0, getSize-1);
}
//*********************A to B helper **********************************************\\
//Helper function to turn array to a BST by reading the array from left and right
//recursively and methodly clears out each array element as it gets transferred
//**************************************************************************\\

void BinTree::Arr2BSTHelper(Node *current, NodeData* copyFrom[], int low, int high)
{
    if (low > high)
    {
        current = NULL; // end of array NodeData
    }
    else
    {
        int middle = (low + high) / 2; // picks NodeData from array to build balanced tree
        
        NodeData* temp;              // NodeData temp pointer
        temp = copyFrom[middle];    // assigns middle element from array section to temp
        copyFrom[middle] = NULL;    // clears the middle array element
        
        insert(temp);   //calls the insert Function to put the aray into the BST
        Arr2BSTHelper(current, copyFrom, low, middle - 1);    // fill left
        Arr2BSTHelper(current, copyFrom, middle + 1, high);   // fill right
    }
}

//**********Given functions by the instructor******************//
//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const
{
    sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const
{
    if (current != NULL)
    {
        level++;
        sideways(current->right, level);
        
        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--)
        {
            cout << "    ";
        }
        
        cout << *current->data << endl;        // display information of object
        sideways(current->left, level);
    }
}
