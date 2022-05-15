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
  BNode* parent;
  int value;
  int color;
  
 public:
  //constructor
  BNode();
  BNode(int newValue);
  BNode(int newValue, BNode* newLeft, BNode* newRight);
  ~BNode();
  
  //getters
  BNode* getRight();
  BNode* getLeft();
  BNode* getParent();
  int getValue();
  int getColor();
  
  //setters
  void setLeft(BNode* newLeft);
  void setRight(BNode* newRight);
  void setParent(BNode* newParent);
  void setValue(int newValue);
  void setBlack();
  void setRed();
};

#endif
