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

//function prototypes using recursion
void print(Node* head);
void average(Node* head, float sum, float count);
void remove(Node*&head, Node* current, Node* previous, int targetID);
void add(Node*&head, Node* current, Student* newStudent);

int main(){

  //variables
  Node *head = NULL;
  bool stillRunning = true;
  
  while(stillRunning) {
    
    char input[20];
    cout << "Please enter: 'ADD', 'DELETE', 'PRINT', 'AVERAGE', or 'QUIT'" << endl;
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

      //creates student pointer
      Student *ptr = new Student(firstname, lastname, id, gpa);

      add(head, head, ptr);

    //print
    } else if (strcmp(input, "PRINT") == 0) {
      print(head);
      
    //delete
    } else if (strcmp(input, "DELETE") == 0) {
      if (head == NULL) {
	cout << "Empty list!" << endl;
      } else {
	int id;
	cout << "Enter student ID to delete:" << endl;
	cin >> id;
	remove(head, head, head, id);
      }
      
    //average
    } else if (strcmp(input, "AVERAGE") == 0) {
      if (head == NULL) {
	cout << "Empty list!" << endl;
      } else {
	average(head, 0, 0);
      }
    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
    }
  }
  
  return 0;
}

//method to print list using recursion
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

void average(Node* head, float sum, float count) {
  if (head != NULL) {
    count++;
    sum += head->getStudent()->getgpa();
    average(head->getNext(), sum, count);
  } else {
    cout << "Average GPA: " << fixed
	 << setprecision(2) << (sum / count) << endl;
  }
}

//method to add using recursion
void add(Node* &head, Node* current, Student *newStudent) {
  if (head == NULL) {
    head = new Node(newStudent);
    head->setStudent(newStudent);
    //if the id number is less than the head (new student has to be head)
  } else if (newStudent->getid() < head->getStudent()->getid()) {
    Node* add = new Node();
    add->setStudent(newStudent);
    add->setNext(head);
    head = add;
  } else if (current->getNext() != NULL &&
	     newStudent->getid() > (current->getNext()->getStudent())->getid()){
    add(head, current->getNext(), newStudent);
  } else {
    Node* add = new Node();
    add->setStudent(newStudent);
    add->setNext(current->getNext());
    current->setNext(add);
  }
}

//method to delete using recursion
void remove(Node * &head, Node* current, Node* previous, int targetID) {
  if (head == NULL) {
    cout << "Empty list... there's nothing to delete" << endl;
    return;
  } else if (current == NULL) {
    cout << "Student is not in database!" << endl;
    return;
  } else if (targetID == current->getStudent()->getid()) {
    //delete two cases: deleting the head or any other node
    //if target id is in head
    if (targetID == head->getStudent()->getid()) {
      Node* temp = head;
      head = head->getNext();
      temp->~Node();
    } else {
      previous->setNext(current->getNext());
      current->~Node();
    }
  } else {
    remove(head, current->getNext(), current, targetID);
  }
}
