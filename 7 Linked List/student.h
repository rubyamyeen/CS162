#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student{
  char firstname[20];
  char lastname[20];
  int id;
  float gpa;
public:
  //constructor
  Student(char* newFirstname, char* newLastname, int newId, float newGpa);
  //get methods
  char* getfirstname();
  char* getlastname();
  int getid();
  float getgpa();
};

#endif
