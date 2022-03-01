/*
This program allows you to add and delete information on students (first name, last name, student id, and GPA) in a vector
Author: Ruby Amyeen
Date: 10/12/21
*/

#include <iostream>
//for set precision
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;

//struct for student
struct Student {
  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
};

//function prototypes
void addStudent(vector<Student*> &studentList);
void printStudent(vector<Student*> studentList);
void deleteStudent(vector<Student*> &studentList);

int main() {
  //variables
  vector <Student*> studentList;
  bool stillRunning = true;

  while(stillRunning == true) {
    char input[10];
    //prompts the user to enter add, print, delete, or quit
    cout << "Please enter: 'ADD', 'DELETE', 'PRINT', or 'QUIT'" << endl;
    cin >> input;

    //add
    if (strcmp(input, "ADD") == 0) {
      addStudent(studentList);
      cout << "Student added!" << endl;
    //print
    } else if (strcmp(input, "PRINT") == 0) {
      printStudent(studentList);
    //delete
    } else if (strcmp(input, "DELETE") == 0) {
      deleteStudent(studentList);
      cout << "Student deleted!" << endl;
    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
      cout << "Leaving student database" << endl;
    }
  }
  return 0;
}

//method to add a student
void addStudent(vector<Student*> &studentList) {
  Student* sPtr = new Student();
    
  cout << "Enter first name:" << endl;
  cin >> (*sPtr).firstName;
    
  cout << "Enter last name:" << endl;
  cin >> (*sPtr).lastName;
    
  cout << "Enter student id:" << endl;
  cin >> (*sPtr).id;
    
  cout << "Enter gpa:" << endl;
  cin >> (*sPtr).gpa;
    
  studentList.push_back(sPtr);
}

//method to delete a student
void deleteStudent(vector<Student*> &studentList) {
  int id;
  cout << "Enter student id:" << endl;
  cin >> id;
  for (int i = 0; i < studentList.size(); i++) {
    if (studentList[i]->id == id) {
      studentList.erase(studentList.begin() + i);
    }
  }
}

//method to print a student
void printStudent(vector<Student*> studentList) {
  for (int i = 0; i < studentList.size(); i++) {
    cout << studentList[i]->firstName << " " << studentList[i]->lastName
	 << ", " << studentList[i]->id << ", " << fixed
	 << setprecision(2) << studentList[i]->gpa << endl;
  }
  if (studentList.empty()) {
    cout << "Student database is empty!" << endl;
  }
}
