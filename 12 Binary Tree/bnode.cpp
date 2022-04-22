//defines node functions
#include <iostream>
#include <cstring>
#include "bnode.h"

using namespace std;

//constructors
BNode::BNode() {
  left = NULL;
  right = NULL;
  value = -1;
}

BNode::BNode(int newValue) {
  left = NULL;
  right = NULL;
  value = newValue;
}

BNode::BNode(int newValue, BNode* newLeft, BNode* newRight) {
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

int BNode::getValue() {
  return value;
}
  
//setters
void BNode::setLeft(BNode* newLeft) {
  left = newLeft;
}

void BNode::setRight(BNode* newRight) {
  right = newRight;
}

void BNode::setValue(int newValue) {
  value = newValue;
}
