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
void add(BNode* head, int data);
void addConsole(BNode* head);
void addFile(BNode* head);
void print(BNode* head);
void remove(BNode* head, int data);

int main() {
  //create BST head
  BNode* head = new BNode();
  
  bool stillRunning = true;
  
  while(stillRunning == true) {
    char input[20];
    //prompts the user to enter add, print, delete, or quit
    cout << "Please enter: 'ADD', 'DELETE', "
	 << "'PRINT', 'SEARCH', 'QUIT'" << endl;
    cin >> input;

    //add
    if (strcmp(input, "ADD") == 0) {
      char type[20];
      //prompts the user to enter add by file or user input
      cout << "Please enter 'file' to add by file or 'input' to add by user input:" << endl;
      cin >> type;
      if (strcmp(type, "file") == 0) {
        addFile();
      } else if (strcmp(type, "input") == 0) {
	addConsole();
      }
    //delete
    } else if (strcmp(input, "DELETE") == 0) {

    //print
    } else if (strcmp(input, "PRINT") == 0) {

    //search
    } else if (strcmp(input, "SEARCH") == 0) {
    
    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
      
    }
  }

    
  return 0;
}

void addFile(BNode* head) {
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
    add(head, input);
  }
 
  fin.close();
}


void addConsole() {
  //char* list = new char[50];
  int list[20];
  int num = 0;
}

void add(BNode* head, int data) {
}
