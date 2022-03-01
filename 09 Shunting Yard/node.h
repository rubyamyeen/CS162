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
  char value;
 public:
  //constructor
  BNode();
  BNode(char newValue);
  BNode(char newValue, BNode* newLeft, BNode* newRight);
  ~BNode();
  
  //getters
  BNode* getRight();
  BNode* getLeft();
  char getValue();
  
  //setters
  void setLeft(BNode* newLeft);
  void setRight(BNode* newRight);
  void setValue(char newValue);
};

#endif
