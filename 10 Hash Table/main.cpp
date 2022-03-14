/*
This is the main method for Hash Table
Using hash tables to store student data because they are efficient when storing information. The program has an ADD, PRINT, DELETE, GENERATE, and QUIT function
Author: Ruby Amyeen
Date: 2/28/22
*/

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//struct for student
struct Student {
  char firstname[20];
  char lastname[20];
  int id;
  float gpa;
public:
  Student(char* newFirstname, char* newLastname, int newId, float newGpa) {
    strcpy(firstname, newFirstname);
    strcpy(lastname, newLastname);
    id = newId;
    gpa = newGpa;
  }
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
void add(HNode*& head, Student* data);
void remove(HNode*& head, HNode* current, HNode* previous, int targetID);
void print(HNode* head);
int checkCollision(HNode* head);
void generate(HNode**& htable, int gen, int& id, int size);

int main() {
  bool stillRunning = true;
  int genId;
  int size = 101;
  //creating hash table
  HNode** htable = new HNode*[size];

  //empty table
  for (int i = 0; i < size; i++) {
    htable[i] = NULL;
  }

  while(stillRunning == true) {
    char input[20];
    //prompts the user to enter add, print, delete, or quit
    cout << "Please enter: 'ADD', 'DELETE', "
	 << "'PRINT', 'GENERATE', or 'QUIT'" << endl;
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
      Student* student = new Student(firstname, lastname, id, gpa);

      add(htable[hashFunction(student, size)], student);

      //check if need to rehash
      for (int i = 0; i < size; i++) {
	if (htable[i] != NULL) {
	  if (checkCollision(htable[i]) > 3) {
	    //cout << checkCollision(htable[i]) << endl;
	    //rehash
	    //create new htable
	    size *= 2;
	    HNode** temp = new HNode*[size];
	    
	    //empty table
	    for (int i = 0; i < size; i++) {
	      temp[i] = NULL;
	    }

	    //go through old table to rehash function the data

	    for (int i = 0; i < size/2; i++) {
	      HNode* current = htable[i];
	      while (current != NULL) {
		add(temp[hashFunction(current->getStudent(), size)], current->getStudent());
		current = current->getNext();
	      }
	      //add(temp[hashFunction(htable[i]->getStudent(), size)], htable[i]->getStudent());
	      //hash function on old htable nodes with new size
	    }
	    //cout << size << endl;
	    cout << "Rehashed!" << endl;
	    cout << "Size of the new table: " << size << endl;
	    
	    //delete old table
	    for (int i = 0; i < size/2; i++) {
	      htable[i]->~HNode();
	    }
	    htable = new HNode*[size];
	    htable = temp;
	    delete[] temp;
	    
	    break;
	  }
	}
      }
      
      //cout << "Student added!" << endl;
  
    //print
    } else if (strcmp(input, "PRINT") == 0) {
      for (int i = 0; i < size; i++) {
	print(htable[i]);
      }
      //cout << "Student database printed!" << endl;
      
    //delete
    } else if (strcmp(input, "DELETE") == 0) {
      int targetID = 0;
      cout << "Enter student ID to delete:" << endl;
      cin >> targetID;
      for (int i = 0; i < size; i++) {
	remove(htable[i], htable[i], htable[i], targetID);
      }
      //cout << "Student deleted!" << endl;
      
    //generate
    } else if (strcmp(input, "GENERATE") == 0) {
      int number = 0;
      cout << "Enter the number of students you'd like to add:" << endl;
      cin >> number;
      generate(htable, number, genId, size);
      //cout << "Students generated!" << endl;
      
    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
      cout << "Leaving student database..." << endl;
    }
  }
  return 0;
}

//hash function
int hashFunction(Student* data, int size) {
  return data->id % size;  
}

//add function
void add(HNode*& head, Student* data) {
  HNode* current = head;
  if(current == NULL) {
    head = new HNode(data);
  } else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new HNode(data));
  }
}

//generate function
void generate(HNode**& htable, int gen, int& id, int size) {
  srand(time(NULL));
  int random = 0;
  int numOfLines = 1;
  
  for (int i = 0; i < gen; i++) {
    //reading in files
    fstream fin;
    fstream lin;
    fin.open("first.txt");
    lin.open("last.txt");    
    char* firstName = new char[50];
    char* lastName = new char[50];   
    numOfLines = 1;
    random = rand() % 1001;

    while(fin >> firstName && lin >> lastName) {
      if(numOfLines == random) {
	//cout << "Line Number:" << numOfLines << endl;
	//cout << firstName << " " << lastName << endl;
	break;
      }
      ++numOfLines;
    }
    //cout << "Name: " << firstName << " " << lastName << endl;
    id++;
    float gpa = float(rand() % 501)/100;

    Student* student = new Student(firstName, lastName, id, gpa);

    add(htable[hashFunction(student, size)], student);
  }  
}

//method to display
void print(HNode* head) {
  if (head != NULL) {
    cout << (head->getStudent())->firstname << " "
	 << (head->getStudent())->lastname << ", "
	 << (head->getStudent())->id << ", " << fixed << setprecision(2)
	 << (head->getStudent())->gpa << endl;
    //sets current node pointer to the next node pointer
    print(head->getNext());
  }
}

//method to check collisions
int checkCollision(HNode* head) {
  int collisions = 0;
  HNode* current = head;
  while (current->getNext() != NULL) {
    collisions++;
    current = current->getNext();
  }
  return collisions;
}

//method to delete
void remove(HNode * &head, HNode* current, HNode* previous, int targetID) {
  if (head == NULL) {
    return;
  } else if (current == NULL) {
    return;
  } else if (targetID == current->getStudent()->id) {
    //delete two cases: deleting the head or any other node
    //if target id is in head
    if (targetID == head->getStudent()->id) {
      HNode* temp = head;
      head = head->getNext();
      temp->~HNode();
    } else {
      previous->setNext(current->getNext());
      current->~HNode();
    }
  } else {
    remove(head, current->getNext(), current, targetID);
  }
}
