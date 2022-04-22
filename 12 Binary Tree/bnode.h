//blueprint for node
#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <cstring>

using namespace std;

class BNode{
private:
  BNode* left;
  BNode* right;
  int value;
 public:
  //constructor
  BNode();
  BNode(int newValue);
  BNode(int newValue, BNode* newLeft, BNode* newRight);
  ~BNode();
  
  //getters
  BNode* getRight();
  BNode* getLeft();
  int getValue();
  
  //setters
  void setLeft(BNode* newLeft);
  void setRight(BNode* newRight);
  void setValue(int newValue);
};

#endif
