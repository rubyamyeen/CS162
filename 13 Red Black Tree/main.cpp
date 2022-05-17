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
#include <cstring>
#include <fstream>
#include "bnode.h"

using namespace std;

//function prototypes
BNode* add(BNode* root, BNode* newNode);
void fixViolation(BNode*& root, BNode*& newNode);
void leftRotate(BNode* root, BNode* x);
void rightRotate(BNode* root, BNode* x);
//int search(BNode* root, int data);
void printTree(BNode* root, int depth);

BNode* grandparent(BNode* current);
BNode* sibling(BNode* current);
BNode* uncle(BNode* current);

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

//Node Family Members
//grandparent -> parent of the parent of the current
BNode* grandparent(BNode* current) {
  BNode* parent = current->getParent();
  BNode* grandparent = parent->getParent();
  if (parent == NULL) {
    return NULL;
    
  } else {
    return grandparent;
  }
} 

//sibling -> left or right of the current
BNode* sibling(BNode* current) {
  BNode* parent = current->getParent();
  if (parent == NULL) {
    return NULL;
    
  } else {
    //current is left child of parent --> sibling is right
    if (parent->getLeft() == current) {
      BNode* sibling = parent->getRight();
      return sibling;
    //current is left child of parent --> sibling is left
    } else if(parent->getRight() == current) {
      BNode* sibling = parent->getLeft();
      return sibling;
    }
  }
  return NULL;
}

//uncle -> sibling of the current's parent
BNode* uncle(BNode* current) {
  BNode* parent = current->getParent();
  // BNode* grandparent = grandparent(current);
  if (grandparent(current) == NULL) {
    return NULL;
    
  } else {
    return sibling(parent);
  }
}


//method to add
BNode* add(BNode* root, BNode* newNode) {
  if (root == NULL) {
    return newNode;
  }
  if (root->getValue() > newNode->getValue()) { //go left
    root->setLeft(add(root->getLeft(), newNode));
    root->getLeft()->setParent(root);
  } else if (root->getValue() < newNode->getValue()) { //go right
    root->setRight(add(root->getRight(), newNode));
    root->getRight()->setParent(root);
  }
  return root;
  /*if (root == NULL) {
    //root = newNode;
    return root;
  }
  if (root != NULL) {
    if (root->getValue() > newNode->getValue()) { //go left
      if (root->getLeft() != NULL) { //recurse left
	return add(root->getLeft(), newNode);
      } else {
	//BNode* add = new BNode(data);
	root->setLeft(newNode);
	newNode->setParent(root);
	return newNode;
      }
    } else { //go right
      if (root->getRight() != NULL) { //recurse right
	return add(root->getRight(), newNode);
      } else {
	//BNode* add = new BNode(data);
	root->setRight(newNode);
	newNode->setParent(root);
	return newNode;
      }
    }
  }
  return NULL;
  */
}

//Referenced from GeeksForGeeks
//method fixes violations and maintains RBT properties
void fixViolation(BNode*& root, BNode*& newNode) {
  BNode* newParent = NULL;
  BNode* newGrand = NULL;
  while ((newNode != root) && (newNode->getColor() != 0) && (newNode->getParent()->getColor() == 1)) {
    newParent = newNode->getParent();
    newGrand = newNode->getParent()->getParent();

    //CASE A: (parent of new node is left child of the grandparent of newnode)
    if (newParent == newGrand->getLeft()) {
      BNode* newUncle = newGrand->getRight();

      //CASE 1: uncle of new node is also red -> recolor
      if (newUncle != NULL && newUncle->getColor() == 1) {
	newGrand->setRed();
      }
    }    
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
