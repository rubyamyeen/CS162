/*
This is the main method for Hash Table
Using hash tables to store student data because they are efficient when storing information. The program has an ADD, PRINT, DELETE, and QUIT function
Author: Ruby Amyeen
Date: 2/28/22
*/

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//struct for student
struct Student {
  char firstName[20];
  char lastName[20];
  int id;
  float gpa;
};

//class for hash node
class HNode {
  Student* data;
  HNode* next;
  
public: 
  //constructor
  HNode(Student* newData) {
    data = newData;
    next = NULL;
  }

  //get next
  HNode* getNext() {
    return next;
  }

  //set next
  void setNext(HNode* newNext) {
    next = newNext;
  }

  Student* getStudent() {
    return data;
  }

  void setData(Student* newData) {
    data = newData;
  }  
  
};

//function prototypes
int hashFunction(Student* data, int size);
void add(HNode** &htable, int size);
void generate(int number);

int main() {
  int size = 11;
  
  //creating hash table
  HNode** htable = new HNode*[size];

  //empty table
  for (int i = 0; i < size; i++) {
    htable[i] = NULL;
  }

  generate(5);
  add(htable, size);

  
  return 0;
}

//hash function
int hashFunction(Student* data, int size) {
  return data->id % size;  
}

//add function
void add(HNode** &htable, int size) {  
  Student* student = new Student();
  
  cout << "Enter first name:" << endl;
  cin.get(student->firstName, 20);
  cin.get();
    
  cout << "Enter last name:" << endl;
  cin.get(student->lastName, 20);
  cin.get();
    
  cout << "Enter student id:" << endl;
  cin >> student->id;
    
  cout << "Enter gpa:" << endl;
  cin >> student->gpa;
  
  htable[hashFunction(student, size)] = new HNode(student);  
}

//generate function
void generate(int number) {    
  //reading in files
  fstream fin;
  fstream lin;
  fin.open("first.txt");
  lin.open("last.txt");
  
  for (int i = 0; i < number; i++) {
    char* firstName = new char[50];
    char* lastName = new char[50];
    fin >> firstName;
    lin >> lastName;
    cout << firstName << " " << lastName << endl;
  }
  
}
