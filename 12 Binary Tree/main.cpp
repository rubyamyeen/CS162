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
BNode* add(BNode* head, int data);
BNode* remove(BNode* head, int data);
BNode* minValueNode(BNode* node);
int search(BNode* head, int data);
void printTree(BNode* head, int depth);

int main() {
  //create BST head
  BNode* head = NULL;
  
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
      head = add(head, input);
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
      head = add(head, num);
    }
  }
  
  while(stillRunning == true) {
    char input[20];
    //prompts the user to enter add, print, delete, or quit
    cout << "Please enter: 'ADD', 'DELETE', "
	 << "'PRINT', 'SEARCH', 'QUIT'" << endl;
    cin >> input;

    //add
    if (strcmp(input, "ADD") == 0) {
      int data = 0;
      cout << "Enter a integer to insert:" << endl;
      cin >> data;
      head = add(head, data);
      
    //delete
    } else if (strcmp(input, "DELETE") == 0) {
      int data = 0;
      cout << "Enter a integer to delete:" << endl;
      cin >> data;
      head = remove(head, data);
      
    //print
    } else if (strcmp(input, "PRINT") == 0) {
      //head->setValue(9);
      //cout << head->getValue() << endl;
      int depth = 0;
      printTree(head, depth);
      
    //search
    } else if (strcmp(input, "SEARCH") == 0) {
      int data = 0;
      cout << "Enter a integer to search for:" << endl;
      cin >> data;
      if (search(head, data) == data) {
	cout << "Found!" << endl;
      } else {
	cout << "Not in list" << endl;
      }
      
    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
      
    }
  }

    
  return 0;
}

//method to add
BNode* add(BNode* head, int data) {
  //add node
  if (head == NULL) {
    head = new BNode(data);
    return head;
    
  // go left
  } else if (head->getValue() > data) {
    head->setLeft(add(head->getLeft(), data));

  // go right
  } else if (head->getValue() < data) {
    head->setRight(add(head->getRight(), data));
    
  }
  return head;
  
}


// method to print tree (similar to heap)
void printTree(BNode* head, int depth) {
  //empty: nothing to print!
  if (head == NULL) {
    return;
  }
  
  if (head->getRight() != NULL) {
    printTree(head->getRight(), depth+1);
  }
  
  for (int i = 0; i < depth; i++) {
    cout << "\t ";
  }
  cout << head->getValue() << endl;

  if (head->getLeft() != NULL) {
    printTree(head->getLeft(), depth+1);
  }

}

//references BST wiki 
int search(BNode* head, int data) {
  if (head == NULL || head->getValue() == data) {
    return head->getValue();
  }
  if (head->getValue() > data) {
    if (head->getLeft() == NULL) {
      return head->getValue();
    }
    return search(head->getLeft(), data);
  } else {
    if (head->getRight() == NULL) {
      return head->getValue();
    }
    return search(head->getRight(), data);
  }
}

//method to give the min value in a tree (not empty tree)
BNode* minValueNode(BNode* node) {
  BNode* current = node;
  while (current && current->getLeft() != NULL) {
    //goes to smallest
    current = current->getLeft();
  }
  return current;
}

//method to remove references from geeks for geeks
BNode* remove(BNode* head, int data) {
  //3 cases:  
  //has one child: swap one of its children
  //multiple children: go left once and then right as far as you can
  //root: go left once and then right as far as you can

  if (head == NULL) {
    cout << "Not found in list" << endl;
    return head;
    
  // go left
  } else if (head->getValue() > data) {
    head->setLeft(remove(head->getLeft(), data));

  // go right
  } else if (head->getValue() < data) {
    head->setRight(remove(head->getRight(), data));
    
  //at the correct node to delete
  } else {
    //if node doesn't have any children
    if (head->getLeft() == NULL && head->getRight() == NULL) {
      return NULL;
      
    //no left child
    } else if (head->getLeft() == NULL) {
      BNode* temp = head->getRight();
      delete head;
      return temp;
      
    //no right child
    } else if (head->getRight() == NULL) {
      BNode* temp = head->getLeft();
      delete head;
      return temp;
    }
    // TWO children
    //assign to smallest in right subtree
    BNode* temp = minValueNode(head->getRight());
    
    head->setValue(temp->getValue());

    head->setRight(remove(head->getRight(), temp->getValue()));
    
    //head->getRight() = remove(head->getRight(), temp->getValue());
    
  }
  return head;
}
