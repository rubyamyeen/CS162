//defines student functions
#include <iostream>
#include <cstring>

#include "student.h"

using namespace std;

//constructor
Student::Student(char* newFirstname, char* newLastname, int newId, float newGpa) {
  strcpy(firstname, newFirstname);
  strcpy(lastname, newLastname);
  id = newId;
  gpa = newGpa;
}

//get methods
char* Student::getfirstname(){
  return firstname;
}

char* Student::getlastname(){
  return lastname;
}

int Student::getid(){
  return id;
}

float Student::getgpa(){
  return gpa;
}
