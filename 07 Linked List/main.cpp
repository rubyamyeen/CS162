/*
This is the main method for Linked Lists
Author: Ruby Amyeen
Date: 12/21/21
 */
#include <iostream>
#include <cstring>
#include <iomanip>

#include "node.h"
#include "student.h"

using namespace std;


int main(){ 
  //creating test students:
  char* firstname = new char[20];
  strcpy(firstname, "Ruby");
  char* lastname = new char[20];
  strcpy(lastname, "Amyeen");
 
  Student* ptr = new Student(firstname, lastname, 1, 4.0);
 
  char* firstname1 = new char[20];
  strcpy(firstname1, "Janae");
  char* lastname1 = new char[20];
  strcpy(lastname1, "Mair");
 
  Student* ptr1 = new Student(firstname1, lastname1, 2, 4.0);
 
  char* firstname2 = new char[20];
  strcpy(firstname2, "Nyla");
  char* lastname2 = new char[20];
  strcpy(lastname2, "Salam");
 
  Student* ptr2 = new Student(firstname2, lastname2, 3, 4.0);

  //creating node pointers
  Node* head = new Node(ptr);
  Node* second = new Node(ptr1);
  Node* third = new Node(ptr2);

  //linking
  head->setNext(second);
  second->setNext(third);
 
 
  //printing linked list
  Node* temp = head;
  int studentCount = 1;

  while (temp != NULL) {
    cout << "-----Student " << studentCount << "-----"  << endl;
    cout << (temp->getStudent())->getfirstname() << endl;
    cout << (temp->getStudent())->getlastname() << endl;
    cout << (temp->getStudent())->getid() << endl;
    cout << fixed << setprecision(2)
	 << (temp->getStudent())->getgpa() << endl;
    //sets current node pointer to the next node pointer
    temp = temp->getNext();
    studentCount++;
  }
  
  return 0;
}
