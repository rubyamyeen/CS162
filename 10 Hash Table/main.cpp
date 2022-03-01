/*
This is the main method for Hash Table
Using hash tables to store student data because they are efficient when storing information. The program has an ADD, PRINT, DELETE, and QUIT function
Author: Ruby Amyeen
Date: 2/28/22
*/

#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

//class for hash node
class HNode {
  int key;
  Student* data;
  HNode* next;
  
public: 
  //constructor
  HNode(int newKey, Student* newData) {
    key = newKey;
    data = newData;
    next = NULL;
  }

  //getter
  HNode* getNext() {
    return next;
  }
  
  
};

//class for hash table
class HTable {  
  HNode** hashTable;
  //int size;
  
public:  
  //constructor
  //creates a hash table with all head pointers set to NULL
  HTable(int size) {
    //size = newSize;
    hashTable = new HNode*[size];
    for (int i = 0; i < size; i++) {
      hashTable[i] = NULL;
    }
  }

  //hash function
  int hash(Student* data, int size) {
    //add hash function with % (size must be PRIME)
    return 0;
  }
  
};

int main() {
  int size = 11;
  HTable* studentList = new HTable(size);
}
