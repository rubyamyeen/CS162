/*
 *This program is a binary serach tree where each node has a 2 children
 *and a data value.
 *The user will enter a list of numbers and they will be correctly
 *placed in a tree.
 *Author: Ruby Amyeen
 *Date: 4/18/22
 */

#include <iostream>
#include <cstring>
#include <fstream>
#include "bnode.h"

using namespace std;

//function prototypes
BNode* add(BNode* root, int data);
int search(BNode* root, int data);
void printTree(BNode* root, int depth);

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
      root = add(root, input);
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
      root = add(root, num);
    }
  }
  
  while(stillRunning == true) {
    char input[20];
    //prompts the user to enter add, print, delete, or quit
    cout << "Please enter: 'ADD', "
	 << "'PRINT', 'SEARCH', 'QUIT'" << endl;
    cin >> input;

    //add
    if (strcmp(input, "ADD") == 0) {
      int data = 0;
      cout << "Enter a integer to insert:" << endl;
      cin >> data;
      root = add(root, data);
      
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

//method to add
BNode* add(BNode* root, int data) {
  //add node
  if (root == NULL) {
    root = new BNode(data);
    return root;
    
  // go left
  } else if (root->getValue() > data) {
    root->setLeft(add(root->getLeft(), data));

  // go right
  } else if (root->getValue() < data) {
    root->setRight(add(root->getRight(), data));
    
  }
  return root;
  
}


// method to print tree (similar to heap)
void printTree(BNode* root, int depth) {
  //empty: nothing to print!
  if (root == NULL) {
    return;
  }
  
  if (root->getRight() != NULL) {
    printTree(root->getRight(), depth+1);
  }
  
  for (int i = 0; i < depth; i++) {
    cout << "\t ";
  }
  cout << root->getValue() << endl;

  if (root->getLeft() != NULL) {
    printTree(root->getLeft(), depth+1);
  }

}

//references BST wiki 
int search(BNode* root, int data) {
  if (root == NULL || root->getValue() == data) {
    return root->getValue();
  }
  if (root->getValue() > data) {
    if (root->getLeft() == NULL) {
      return root->getValue();
    }
    return search(root->getLeft(), data);
  } else {
    if (root->getRight() == NULL) {
      return root->getValue();
    }
    return search(root->getRight(), data);
  }
}
