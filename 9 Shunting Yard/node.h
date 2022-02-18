//blueprint for node
#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <cstring>

using namespace std;

class BNode{
  BNode* left;
  BNode* right;
  char data;
 public:
  //constructor
  BNode();
  BNode(char newData);
  ~BNode();
  
  //getters
  BNode* getRight();
  BNode* getLeft();
  char getData();
  
  //setters
  void setLeft(BNode* newLeft);
  void setRight(BNode* newRight);
  void setData(char newData);
};

#endif
