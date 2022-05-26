/*
 *This program is a red black tree, which is a balanced binary search tree.
 *Nodes are either red or black, root and leaves are black, red nodes have black *children, all paths from a node to null have same number of black nodes
 *The user will enter a list of numbers and they will be correctly
 *placed in a tree.
 *Colors: 1 is RED and 0 is BLACK 
 *v is the node to deleted and u is the child that replaces v
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

BNode* remove(BNode* root, int data);
void fixDB(BNode* u, BNode* root);
BNode* getV(BNode* root, int data);
BNode* getRoot(BNode* x);
void replaceNode(BNode* v, BNode* u);

BNode* minValueNode(BNode* node);
void leftRotate(BNode* root, BNode* x);
void rightRotate(BNode* root, BNode* x);
int search(BNode* root, int data);
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
	 << "'PRINT', 'SEARCH' or 'DELETE' or 'QUIT'" << endl;
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

    //search
    } else if (strcmp(input, "SEARCH") == 0) {
      int data = 0;
      cout << "Enter a integer to search for:" << endl;
      cin >> data;
      if (search(root, data) == data) {
	cout << "Found!" << endl;
      } else {
	cout << "Not in list" << endl;
      }
    } else if (strcmp(input, "DELETE") == 0) {
      //delete
      int data = 0;
      cout << "Enter a integer to delete:" << endl;
      cin >> data;
      root = remove(root, data);
      
    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
    }
  }

    
  return 0;
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
//method fixes violations for INSERT and maintains RBT properties
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
      
    //parent is larger than child
    } else if (newNode == Parent->getLeft() && Parent == Grandparent->getRight()){
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

//returns v: node to be deleted
BNode* getV(BNode* root, int data) {
  BNode* v = root;
  while (v != NULL) {
    if (v->getValue() > data) { //go left
      v = v->getLeft();
    } else if (v->getValue() < data) { //go right
      v = v->getRight();
    } else if (v->getValue() == data) {
      return v;
    }
  }
  return NULL;
}

//returns actual root
BNode* getRoot(BNode* x) {
  if (x == NULL) {
    return x;
    
  } while (x->getParent() != NULL) {
    x = x->getParent();
  }
  //now at root
  return x;
}

//method to replace v (to be deleted) with u (child node)
void replaceNode(BNode* v, BNode* u) {
  //reassign parent pointer
  u->setParent(v->getParent());
  //v is root
  if (v->getParent() == NULL) {
    return;
  }
  if (v == v->getParent()->getLeft()) {
    v->getParent()->setLeft(u);
  } else {
    v->getParent()->setRight(u);
  }
}

/*
//method to remove references from geeks for geeks
BNode* remove(BNode* root, int data) {
  //3 cases:  
  //has one child: swap one of its children
  //multiple children: go left once and then right as far as you can
  //root: go left once and then right as far as you can

  if (root == NULL) {
    cout << "Not found in list" << endl;
    return root;
    
  // go left
  } else if (root->getValue() > data) {
    root->setLeft(remove(root->getLeft(), data));

  // go right
  } else if (root->getValue() < data) {
    root->setRight(remove(root->getRight(), data));
    
  //at the correct node to delete
  } else {
    //if node doesn't have any children
    if (root->getLeft() == NULL && root->getRight() == NULL) {
      return NULL;
      
    //no left child
    } else if (root->getLeft() == NULL) {
      BNode* temp = root->getRight();
      temp->setParent(root->getParent());
      delete root;
      return temp;
      
    //no right child
    } else if (root->getRight() == NULL) {
      BNode* temp = root->getLeft();
      temp->setParent(root->getParent());
      delete root;
      return temp;
    }
    // TWO children
    //assign to smallest in right subtree
    BNode* temp = minValueNode(root->getRight());
    temp->setParent(root->getParent());
    root->setValue(temp->getValue());

    root->setRight(remove(root->getRight(), temp->getValue()));
        
  }
  return root;
}
*/

//method to remove
BNode* remove(BNode* root, int data) {
  //not found in list
  if (getV(root, data) == NULL) {
    cout << "Not found in list" << endl;
    return root;
  } else {
    BNode* v = new BNode();
    v = getV(root, data);
    //if v has one child OR none
    if (v->getLeft() == NULL || v->getRight() == NULL) {
      BNode* u = new BNode();
      
      //has left
      if (v->getLeft() != NULL) {
	u = v->getLeft();
	
      //has right
      } else if (v->getRight() != NULL) {
	u = v->getRight();

	//no children
      } else {
	u->setValue(-1);
	u->setBlack();
      }

      replaceNode(v, u); //if v and u were red then you don't need to change anything
      
      if (v->getColor() == 0) { //black
	if (u->getColor() == 1) { //red
	  u->setBlack();
	} else { //DOUBLE BLACK
	  //fix double black
	  fixDB(u, getRoot(u));
	}
      } else {
      }
      if (u->getValue() == -1 && u->getParent() == NULL) {
	return NULL;
      }
      //deleting the node
      BNode* root = getRoot(u);
      if (u->getValue() == -1) {
	if (u->getParent()->getLeft() == u) {
	  u->getParent()->setLeft(NULL);
	} else {
	  u->getParent()->setRight(NULL);
	}
	delete u;
      }
      delete v;
      return root;
      
    //two children
    } else {
      BNode* u = minValueNode(v->getRight());
      v->setValue(u->getValue());
      remove(v->getRight(), u->getValue());
    }
  }
  return getRoot(root);
}

//References https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474ea
void fixDB(BNode* u, BNode* root) {
  if (u->getParent() != NULL) {
    //CASE 2
    BNode* s = sibling(u);
    if (s->getColor() == 1) { //sibling is red 
      u->getParent()->setRed(); //swap color of parent and sibling
      s->setBlack();
      if (u == u->getParent()->getLeft()) { //rotate at parent node left --> db is at left
	leftRotate(u->getParent(), root);
	
      } else if (u == u->getParent()->getRight()) { //rotate at parent node right --> db is at right
	rightRotate(u->getParent(), root);
      }
    }
    //CASE 3
    s = sibling(u);
    if (u->getParent()->getColor() == 0 && s->getColor() == 0
	&& s->getLeft()->getColor() == 0 && s->getRight()->getColor() == 0) { //sibling is black and sibling's children are black
      s->setRed(); //sibling red
      fixDB(u->getParent(), root); //parent is black make it db
    } else {
      //CASE 4
      s = sibling(u);
      if (u->getParent()->getColor() == 1 && s->getColor() == 0 
	  && s->getLeft()->getColor() == 0 && s->getRight()->getColor() == 0) { //sibling and children are black but parent is red
	s->setRed();
	u->getParent()->setBlack(); //set black
      } else {
	s = sibling(u);
	//CASE 5
	if (s->getColor() == 0) {
	  if (u == u->getParent()->getLeft() && s->getRight()->getColor() == 0
	      && s->getLeft()->getColor() == 1) { //sibling is black, sibling left child (close) is red while right (far) is black
	    s->setRed(); //swap colors
	    s->getLeft()->setBlack();
	    rightRotate(s, root); //rotate opposite direction of db RIGHT
	  } else if (u == u->getParent()->getRight() && s->getRight()->getColor() == 1
	      && s->getLeft()->getColor() == 0) { //sibling is black, sibling right child (close) is red while left (far) is black
	    s->setRed(); //swap colors
	    s->getRight()->setBlack();
	    leftRotate(s, root); //rotate opposite direction of db LEFT
	  }
	}
	//CASE 6 after CASE 5
	s = sibling(u);
	if (u->getParent()->getColor() == 0) { 
	  s->setBlack();
	} else {
	  s->setRed();
	}
	u->getParent()->setBlack();
	if (u == u->getParent()->getLeft()) {
	  s->getRight()->setBlack();
	  leftRotate(u->getParent(), root);
	} else {
	  s->getLeft()->setBlack();
	  rightRotate(u->getParent(), root);
	}
      }
    }
    return;
  }
  return; //CASE 1 -> if double black at root just return the root (to later delete it)
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


//method to give the min value in a tree (not empty tree)
//finding in order successor
BNode* minValueNode(BNode* node) {
  BNode* current = node;
  while (current && current->getLeft() != NULL) {
    //goes to smallest
    current = current->getLeft();
  }
  return current;
}
