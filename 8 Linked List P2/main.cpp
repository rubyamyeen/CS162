/*
This is the main method for Linked Lists. It's a student database that includes 5 commands: to add, delete, average, print and quit.
Author: Ruby Amyeen
Date: 12/21/21
 */

#include <iostream>
#include <cstring>
#include <iomanip>

#include "node.h"
#include "student.h"

using namespace std;

//functions
//using recursion
void print(Node* head);
//using recursion
void remove(Node*&head, Node* current, Node* previous, int targetID);
//using recursion
void addR(Node*&head, Node* current, Student* newStudent);

int main(){
  Node *head = NULL;
  bool stillRunning = true;
  
  while(stillRunning) {
    char input[20];
    cout << "Please enter: 'ADD', 'DELETE', 'PRINT', or 'QUIT'" << endl;
    cin >> input;
    //add
    if (strcmp(input, "ADD") == 0) {
      //prompts user for information
      char *firstname = new char[20];
      cout << "Enter first name:" << endl;
      cin >> firstname;

      char *lastname = new char[20];
      cout << "Enter last name:" << endl;
      cin >> lastname;

      int id = 0;
      cout << "Enter student id:" << endl;
      cin >> id;

      double gpa = 0;
      cout << "Enter gpa:" << endl;
      cin >> gpa;

      Student *ptr = new Student(firstname, lastname, id, gpa);

      addR(head, head, ptr);

    //print
    } else if (strcmp(input, "PRINT") == 0) {
      print(head);
      
    //delete
    } else if (strcmp(input, "DELETE") == 0) {
      if (head == NULL) {
	cout << "List is empty... there is nothing to delete." << endl;
      } else {
	int id;
	cout << "Enter student ID to delete:" << endl;
	cin >> id;
	remove(head, head, head, id);
      }
      
    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
      cout << "Leaving student database" << endl;
    }
  }
  
  return 0;
}

//printing list using recursion
void print(Node *head) {
  if (head != NULL) {
    cout << (head->getStudent())->getfirstname() << " "
	 << (head->getStudent())->getlastname() << ", "
	 << (head->getStudent())->getid() << ", " << fixed << setprecision(2)
	 << (head->getStudent())->getgpa() << endl;
    //sets current node pointer to the next node pointer
    print(head->getNext());
  }
}

//inserting to list using recursion
void addR(Node* &head, Node* current, Student *newStudent) {
  if (head == NULL) {
    head = new Node(newStudent);
    head->setStudent(newStudent);
  } else if (newStudent->getid() < head->getStudent()->getid()) {
    Node* add = new Node();
    add->setStudent(newStudent);
    add->setNext(head);
    head = add;
  } else if (current->getNext() != NULL &&
	     newStudent->getid() > (current->getNext()->getStudent())->getid()){
    addR(head, current->getNext(), newStudent);
  } else {
    Node* add = new Node();
    add->setStudent(newStudent);
    add->setNext(current->getNext());
    current->setNext(add);
  }
}

//DOESNT WORK (also using iteration)
void remove(Node * &head, Node* current, Node* previous, int targetID) {
  if (head == NULL) {
    return;
  } else if (current == NULL) {
    cout << "Student is not in database!" << endl;
  } else if (targetID == current->getStudent()->getid()) {
    //delete
    previous->setNext(current->getNext());
    delete current;
  } else {
    remove(head, current->getNext(), current, targetID);
  }
}
