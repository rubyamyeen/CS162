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
void print(Node *head);
void remove(Node * &head, Student *newStudent);
void add(Node * &head, Student *newStudent);
void addR(Node * &head, Node* next, Student *newStudent);


int main(){
  Node *head = NULL;
  bool stillRunning = true;
  
  /*while(stillRunning) {
    char input[20];
    cout << "Please enter: 'ADD', 'DELETE', 'PRINT', or 'QUIT'" << endl;
    cin >> input;
    //add
    if (strcmp(input, "ADD") == 0) {
      cout << "Student added!" << endl;
      prompts user for information
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
    //print
    } else if (strcmp(input, "PRINT") == 0) {
      cout << "Printed!" << endl;
      print(head);
    //delete
    } else if (strcmp(input, "DELETE") == 0) {
      cout << "Student deleted!" << endl;
    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
      cout << "Leaving student database" << endl;
    }
    }*/
  
  //creating test students:
  char *firstname = new char[20];
  strcpy(firstname, "Ruby");
  char *lastname = new char[20];
  strcpy(lastname, "Amyeen");
 
  Student *ptr = new Student(firstname, lastname, 1, 4.0);
 
  char *firstname1 = new char[20];
  strcpy(firstname1, "Janae");
  char *lastname1 = new char[20];
  strcpy(lastname1, "Mair");
 
  Student *ptr1 = new Student(firstname1, lastname1, 2, 4.0);
 
  char *firstname2 = new char[20];
  strcpy(firstname2, "Nyla");
  char *lastname2 = new char[20];
  strcpy(lastname2, "Salam");
 
  Student* ptr2 = new Student(firstname2, lastname2, 3, 4.0);

  addR(head, head, ptr);
  print(head);
  cout << "------------------------" << endl;
  addR(head, head, ptr1);
  print(head);
  cout << "------------------------" << endl;
  addR(head, head,  ptr2);
  print(head);
  
  /*
  //creating node pointers
  head = new Node(ptr);
  Node *second = new Node(ptr1);
  Node *third = new Node(ptr2);

  //linking
  head->setNext(second);
  second->setNext(third);
  */
 
  //printing linked list
  Node *temp = head;
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

//printing list using recursion
void print(Node *head) {
  if (head != NULL) {
    cout << (head->getStudent())->getfirstname() << endl;
    cout << (head->getStudent())->getlastname() << endl;
    cout << (head->getStudent())->getid() << endl;
    cout << fixed << setprecision(2)
	 << (head->getStudent())->getgpa() << endl;
    //sets current node pointer to the next node pointer
    print(head->getNext());
  }
}

//inserting to list using recursion
void add(Node * &head, Student *newStudent) {

  Node *current = head;
  if (current == NULL) {
    head = new Node();
    head->setStudent(newStudent);
  } else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    
    }
    current->setNext(new Node());
    current->getNext()->setStudent(newStudent);
  }
  
}

void remove(Node * &head, Student *newStudent) {
  
}

void addR(Node* &head, Node* next, Student *newStudent) {
  if (head == NULL) {
    head = new Node(newStudent);
    head->setStudent(newStudent);
  } else if (next->getNext() != NULL){
    addR(head, next->getNext(), newStudent);
  } else {
    Node* tail = new Node();
    tail->setStudent(newStudent);
    next->setNext(tail);
  }
}
