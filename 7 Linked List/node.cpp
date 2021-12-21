//defines node functions
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

//gets next Node pointer
Node* Node::getNext(){
  return next;
}

//gets student pointer
Student* Node::getStudent(){
  return student;
}

//sets next node pointer
void Node::setNext(Node* newNext){
  next = newNext;
}

//constructor
Node::Node(Student* newStudent){
  student = newStudent;
  next = NULL;
}

//destructor
Node::~Node() {
  cout << "Deleting..." << endl;
  delete student;
  next = NULL;
}
