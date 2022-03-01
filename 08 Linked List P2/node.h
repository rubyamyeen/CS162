#ifndef NODE_H
#define NODE_H
#include "student.h"
#include <iostream>

using namespace std;

/*
 * Author: Fiona Wang
 * Date: Jan. 3, 2022
 * This is the node header file and contains get and set functions
 */

class Node{
 public:
  //Initializing node functions
  Node(Student* newStudent);
  ~Node();
  Node();
  void setStudent(Student* newStudent);
  Student* getStudent();
  void setNext(Node* newNode);
  Node* getNext();

 private:
  //Initializing node variables
  Student* value;
  Node* next;
};
#endif
