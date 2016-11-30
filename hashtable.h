
// -----------------------Hastable.h---------------------------------
// Assignment4
// -------------------------------------------------------------------------------
// Purpose: Due to template implementation Templatized Hastable class has holds
// implementations in .h file. Serves as a data structure to hold customers
// -------------------------------------------------------------------------------
// uses chain model hashing, duplicate customer is not allowed

#ifndef hashtable_h
#define hashtable_h

#include <stdio.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "customer.h"
using namespace std;

template <class item_type>

class HashTable {
    
public:
    
    // Default constructor
    // Calls buildTable() creates an empty hastable
    HashTable() {
        buildTable();
    }
    
    // BinTree default constructor
    //Calls makeEmpty() function. destructs Hashtable
    ~HashTable(){
        makeEmpty();
    }
    
    // find
    // Returns specified items, returns null if not found
    item_type *find(int key) const {
        
        int hash = (key % SIZE);                // assign hash
        
        if (table[hash] == NULL){         // no customer at index
            return NULL;
        }
        
        else{
            
            ItemList *node = table[hash];
            
            // traverse tree until found
            while (node != NULL){
                if (key == node->key)
                    return node->data;
                
                node = node->next;
            }
        }
        return NULL;                           // not found
    }
    
    // Insert
    // Adds the item in hastable, Checks for duplicates
 
    void insert(int key, item_type *item) {

        int hash = (key % SIZE);             // assign hash
        
        ItemList *node = new ItemList;      // node to hold object
        node->data = item;                  // pointer to object
        node->key = key;                    // pointer to key
        node->next = NULL;                  // next null
        
        // if the index is empty
        if (table[hash] == NULL) {
            node->next = table[hash];
            table[hash] = node;
        }
        
        else { //one or more nodes
            
            ItemList * current = table[hash];
            while (current->next != NULL){

                if (key == current->key){ //if duplicate, to handle duplicate hashing
                    delete node->data;      // delete customer
                    delete node;            // delete pointer
                    throw logic_error("Can't add same key twice");
                }
                
                current = current->next;
            }
            
            current->next = node; // add to the list
        }
    }
    
private:
    static const int SIZE = 50; // twice size of customer base
    
    // makeEmpty
    // Deletes all items in the table

    void makeEmpty() {
        
        for (int i = 0; i < SIZE; ++i) {
            
            if (table[i] != NULL) {
                ItemList* del = table[i];

                while (table[i] != NULL) {          //loop until last node
                    table[i] = table[i]->next;      // move head
                    delete del->data;                      // delete object
                    delete del;                            // delete node
                    del = NULL;
                    del = table[i];	               // assing del to head
                }
            }
        }
    }
    // buildTable
    // helper method to create empty table
    
    void buildTable() {
        for (int i = 0; i < SIZE; ++i) {
            table[i] = NULL;
        }
    }
    
    struct ItemList  {
        
        item_type * data;   // holds object
        int key;            // holds key
        ItemList * next;
    };
    
    ItemList *table[SIZE];   // hastable array
};

#endif /* hashtable_h */