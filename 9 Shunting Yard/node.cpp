//defines node functions
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

//constructors
BNode::BNode() {
  left = NULL;
  right = NULL;
  data = '\0';
}

BNode::BNode(char newData) {
  left = NULL;
  right = NULL;
  data = newData;
}

//destructor
BNode::~BNode() {
}
  
//getters
BNode* BNode::getRight() {
  return right;
}

BNode* BNode::getLeft() {
  return left;
}

char BNode::getData() {
  return data;
}
  
//setters
void BNode::setLeft(Node* newLeft) {
  left = newLeft;
}

void BNode::setRight(Node* newRight) {
  right = newRight;
}

void BNode::setData(char* newValue) {
  data = newData;
}
