//defines node functions
#include <iostream>
#include <cstring>
#include "bnode.h"

using namespace std;

//constructors
BNode::BNode() {
  left = NULL;
  right = NULL;
  parent = NULL;
  color = 1; //red 
  value = -1;
  
}

BNode::BNode(int newValue) {
  left = NULL;
  right = NULL;
  parent = NULL;
  value = newValue;
  color = 1; //red
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

BNode* BNode::getParent() {
  return parent;
}

int BNode::getValue() {
  return value;
}

int BNode::getColor() {
  return color;
}

  
//setters
void BNode::setLeft(BNode* newLeft) {
  left = newLeft;
}

void BNode::setRight(BNode* newRight) {
  right = newRight;
}

void BNode::setParent(BNode* newParent) {
  parent = newParent;
}

void BNode::setValue(int newValue) {
  value = newValue;
}

void BNode::setRed() {
  color = 1; //red
}
void BNode::setBlack() {
  color = 0; //black
}
