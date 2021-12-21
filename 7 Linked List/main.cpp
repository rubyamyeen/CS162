#include <iostream>

#include "node.h"
#include "student.h"

using namespace std;


int main(){
  char* firstname = new char[20];
  strcpy(firstname, "Ruby");
  char* lastname = new char[20];
  strcpy(lastname, "Amyeen");

  Student* s = new Student(firstname, lastname, 411982, 4.0);

  cout << s << endl;
  
  Node* head = new Node(s);
  cout << head->getStudent() << endl;
  
  return 0;
}
