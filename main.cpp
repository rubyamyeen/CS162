/*
 *This program is a red black tree, which is a balanced binary search tree.
 *Nodes are either red or black, root and leaves are black, red nodes have black *children, all paths from a node to null have same number of black nodes
 *The user will enter a list of numbers and they will be correctly
 *placed in a tree.
 *Colors: 1 is RED and 0 is BLACK 
 *Author: Ruby Amyeen
 *Date: 4/18/22
 */

#include <iostream>
#include <utility> //for swap
#include <cstring>
#include <fstream>
#include "bnode.h"

using namespace std;

//function prototypes
BNode* add(BNode* root, BNode* newNode); 
void insert(BNode* root, BNode* newNode); 
void fixViolation(BNode* newNode);
void leftRotate(BNode* root, BNode* x);
void rightRotate(BNode* root, BNode* x);
//int search(BNode* root, int data);
void printTree(BNode* root, int depth);

BNode* grandparent(BNode* current);
BNode* sibling(BNode* current);
BNode* uncle(BNode* current);

/*class RBT {
private:
  BNode* root;
protected:
  void 
  }*/


int main() {
  //create BST root
  BNode* root = NULL;
  
  bool stillRunning = true;
  
  char type[10];
  cout << "Please enter 'FILE' to add by file or 'INPUT' to add by user input:" << endl;
  cin >> type;
  if (strcmp(type, "FILE") == 0) {
    //get file
    char* fileName = new char[20];
    cout << "Enter file name (include .txt)" << endl;
    cin >> fileName;
    fstream fin;
    fin.open(fileName);

    int input = 0;
    while(fin >> input) {
      //cout << input << " ";
      //add function
      BNode* newNode = new BNode(input);
      root = add(root, newNode);
    }

    fin.close();
    
  } else if (strcmp(type, "INPUT") == 0) {
    char input[10];
    while (strcmp(input, "DONE") != 0) {
      cout << "Enter a number or 'DONE' to print the list:" << endl;
      cin >> input;
      if (strcmp(input, "DONE") == 0) {
	break;
      }
      int num = atoi(input);
      //add
      BNode* newNode = new BNode(num);
      root = add(root, newNode);
    }
  }
  
  while(stillRunning == true) {
    char input[20];
    //prompts the user to enter add, print, delete, or quit
    cout << "Please enter: 'ADD', "
	 << "'PRINT', or 'QUIT'" << endl;
    cin >> input;

    //add
    if (strcmp(input, "ADD") == 0) {
      int data = 0;
      cout << "Enter a integer to insert:" << endl;
      cin >> data;
      BNode* newNode = new BNode(data);
      root = add(root, newNode);
      //int depth = 0;
      //printTree(root, depth);
      
    //print
    } else if (strcmp(input, "PRINT") == 0) {
      //root->setValue(9);
      //cout << root->getValue() << endl;
      int depth = 0;
      printTree(root, depth);
      
    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
      
    }
  }

    
  return 0;
}

//method to go through tree
void insert(BNode* root, BNode* newNode) {

  if (root!= NULL) {
    if (root->getValue() > newNode->getValue()) { //go left
      if (root->getLeft() != NULL) {
	insert(root->getLeft(), newNode);
	return;
      } else {
	root->setLeft(newNode);
      }
    } else if (root->getValue() < newNode->getValue()) { //go right
      if (root->getRight() != NULL) {
	insert(root->getRight(), newNode);
	return;
      } else {
	root->setRight(newNode);
      }
    }
  }
  newNode->setParent(root);
}


//method used in main to add
BNode* add(BNode* root, BNode* newNode) {
  insert(root, newNode);
  fixViolation(newNode);
  
  root = newNode;
  while (root->getParent() != NULL){
    root = root->getParent();
  }
  return root;

}

//Referenced from GeeksForGeeks and wiki
//method fixes violations and maintains RBT properties
void fixViolation(BNode* newNode) {
  if (newNode->getParent() == NULL) { //CASE 1: add to the root
    newNode->setBlack();
  } else if (newNode->getParent()->getColor() == 0) { //CASE 2: parent is black (good)
    return;
    
  } else if (uncle(newNode) != NULL && uncle(newNode)->getColor() == 1) { //CASE 3: parent and uncle red
    newNode->getParent()->setBlack();
    uncle(newNode)->setBlack();
    grandparent(newNode)->setRed();
    fixViolation(grandparent(newNode));
    
  } else { //CASE 4: parent is smaller or larger than node (rotation needed)
    BNode* Parent = newNode->getParent(); //new node's parent
    BNode* Grandparent = grandparent(newNode); //new node's grandparent
    //parent is smaller than child
    if (newNode == Parent->getRight() && Parent == Grandparent->getLeft()){
      leftRotate(newNode, Parent);
      newNode = newNode->getLeft();
    }
    //parent is larger than child
    else if (newNode == Parent->getLeft() && Parent == Grandparent->getRight()){
      rightRotate(newNode, Parent);
      newNode = newNode->getRight();
    }

    Parent = newNode->getParent();
    Grandparent = grandparent(newNode);
    if (newNode == Parent->getLeft()){
      rightRotate(newNode, Grandparent);
    } else {
      leftRotate(newNode, Grandparent);
    }
    Parent->setBlack();
    Grandparent->setRed();
  }
}



// method to print tree (similar to heap)
void printTree(BNode* root, int depth) {
  //empty: nothing to print!
  if (root == NULL) {
    return;
  }
  
  //go right
  if (root->getRight() != NULL) {
    printTree(root->getRight(), depth+1);
  }
  
  for (int i = 0; i < depth; i++) {
    cout << "\t ";
  }
  
  if (root->getColor() == 0) { //BLACK
    cout << root->getValue() << endl;
  } else if (root->getColor() == 1) { //RED
    cout << "\033[1;31m" << root->getValue() << " \033[0m" << endl;
  }
  
  //go left
  if (root->getLeft() != NULL) {
    printTree(root->getLeft(), depth+1);
  }

}

//referenced from https://www.youtube.com/watch?v=95s3ndZRGbk
//method for left rotate

void leftRotate(BNode* root, BNode* x) {
  BNode* y = x->getRight(); //y points to right of x
  x->setRight(y->getLeft()); //turning y's left subtree into x's right tree
  if (y->getLeft() != NULL) {
    y->getLeft()->setParent(x);
  }
  y->setParent(x->getParent()); //link x's parent to y

  //if x at root then y is new root
  if (x->getParent() == NULL) {
    root = y;
  } else if (x == x->getParent()->getLeft()) {  //if x is left child
    x->getParent()->setLeft(y);
  } else {
    x->getParent()->setRight(y);
  }
  y->setLeft(x); //left child of y is x
  x->setParent(y); //y is parent of x
    
}


//method for right rotate
void rightRotate(BNode* root, BNode* x) {
  BNode* y = x->getLeft(); //y points to left of x
  x->setLeft(y->getRight()); //turning y's right subtree into x's left tree
  if (y->getRight() != NULL) {
    y->getRight()->setParent(x);
  }
  y->setParent(x->getParent()); //link x's parent to y

  //if x at root then y is new root
  if (x->getParent() == NULL) {
    root = y;
  } else if (x == x->getParent()->getLeft()) { //if x is left child
    x->getParent()->setLeft(y);
  } else {
    x->getParent()->setRight(y);
  }
  y->setRight(x); //right child of y is x
  x->setParent(y); //y is parent of x
  
}

//Node Family Members
//grandparent -> parent of the parent of the current
BNode* grandparent(BNode* current) {
  BNode* parent = current->getParent();
  BNode* Grandparent = parent->getParent();
  if (parent == NULL) {
    return NULL;
    
  } else {
    return Grandparent;
  }
} 

//sibling -> left or right of the current
BNode* sibling(BNode* current) {
  BNode* parent = current->getParent();
  if (parent == NULL) {
    return NULL;
    
  }
    //current is left child of parent --> sibling is right
    if (parent->getLeft() == current) {
      BNode* sibling = parent->getRight();
      return sibling;
    //current is left child of parent --> sibling is left
    } else if(parent->getRight() == current) {
      BNode* sibling = parent->getLeft();
      return sibling;
    }
  return NULL;
}

//uncle -> sibling of the current's parent
BNode* uncle(BNode* current) {
  BNode* parent = current->getParent();
  if (grandparent(current) == NULL) {
    return NULL;
    
  }
  return sibling(parent);
}
