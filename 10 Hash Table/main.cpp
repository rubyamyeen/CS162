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
  Student* data;
  HNode* next;
  
public: 
  //constructor
  HNode(Student* newData) {
    data = newData;
    next = NULL;
  }

  //getter
  HNode* getNext() {
    return next;
  }

  void setNext(HNode* newNext) {
    next = newNext;
  }
  
  
};

//hash function returns key

int main() {
  int size = 11;
  
  //creating hash table
  HNode** htable = new HNode*[size];

  //empty table
  for (int i = 0; i < size; i++) {
    htable[i] = NULL;
  }
  
  
}
