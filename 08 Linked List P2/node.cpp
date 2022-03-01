#include <iostream>
#include "node.h"
#include "student.h"
#include <cstring>

using namespace std;

/*
 * Author: Fiona Wang
 * Date: January 11, 2022
 * This is the node cpp file
 */

//Creating and setting node variables
Node::Node(Student* newStudent) {
  value=newStudent;
  next=NULL;
}

//default constructor
Node::Node() {
  value = NULL;
  next = NULL;
}

//Node destructor
Node::~Node() {
  delete &value;
  next=NULL;
}

//Function for setting student information
void Node::setStudent(Student* newStudent){
  value = newStudent;
}

//Function for getting student information
Student* Node::getStudent(){
  return value;
}

//Function for setting new nodes
void Node::setNext(Node* newNode){
  next=newNode;
}

//Function for getting the nodes
Node* Node::getNext(){
  return next;
}
