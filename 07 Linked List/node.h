//blueprint for node
#ifndef NODE_H
#define NODE_H

#include "student.h"
#include <iostream>
#include <cstring>

using namespace std;

class Node{
  Student* student;
  Node* next;
public:
  //get methods
  Node* getNext();
  Student* getStudent();

  //set method
  void setNext(Node* newNext);

  //constructor
  Node(Student* newStudent);

  //destructor
  ~Node();		
};

#endif
