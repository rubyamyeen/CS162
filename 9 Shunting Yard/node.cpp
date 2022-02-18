//defines node functions
#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

//constructors
BNode::BNode() {
  left = NULL;
  right = NULL;
  value = '\0';
}

BNode::BNode(char newValue) {
  left = NULL;
  right = NULL;
  value = newValue;
}

BNode::BNode(char newValue, BNode* newLeft, BNode* newRight) {
  left = newLeft;
  right = newRight;
  value = newValue;
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

char BNode::getValue() {
  return value;
}
  
//setters
void BNode::setLeft(BNode* newLeft) {
  left = newLeft;
}

void BNode::setRight(BNode* newRight) {
  right = newRight;
}

void BNode::setValue(char newValue) {
  value = newValue;
}
