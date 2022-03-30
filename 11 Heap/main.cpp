/*
 *This program creates a heap from the user-entered numbers or a file with numbers. 
 *It also has a visual representation of a tree.
 *Author: Ruby Amyeen
 *Date: 3/14/22
 */

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

//function prototypes
void generate(int*& heap);
void userInput(int*& heap);
void add(int*& heap, int data, int index);
void print(int* heap, int size);
void printOutput(int*& heap, int index);

int main() {
  int* heap = new int[100];
  int* output = new int[100];
  bool stillRunning = true;

  //empty heap
  for (int i = 0; i < 100; i++) {
    heap[i] = 0;
  }
  //empty output
  for (int i = 0; i < 100; i++) {
    output[i] = 0;
  }
  
  while (stillRunning == true) {
    char input[20];
    //prompts the user to enter add, print, delete, or quit
    cout << "Please enter: 'ADD', 'DELETE', "
	 << "'PRINT', 'GENERATE', or 'QUIT'" << endl;
    cin >> input;

    //add
    if (strcmp(input, "GENERATE") == 0) {
      generate(heap);
    } else if (strcmp(input, "ADD") == 0) {
      userInput(heap);
    } else if (strcmp(input, "PRINT") == 0) {
      
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
    }
  }
  printOutput(heap, 1);
  return 0;
}


void generate(int*& heap) {
  //get file
  char* fileName = new char[20];
  cout << "Enter file name (include .txt)" << endl;
  cin >> fileName;
  fstream fin;
  fin.open(fileName);

  int input = 0;
  int index = 1;
  while(fin >> input) {
    //cout << input << " ";
    //add function
    add(heap, input, index);
    ++index;
  }
  int size = index;
  //cout << size << endl;
  print(heap, size);
  fin.close();
  cout << endl;

}

void userInput(int*& heap) {
  char input[10];
  int index = 1;
  while (strcmp(input, "DONE") != 0) {
    cout << "Enter a number or 'DONE' to print the list:" << endl;
    cin >> input;
    int num = atoi(input);
    //add
    add(heap, num, index);
    ++index;
  }
  int size = index - 1;
  //cout << size << endl;
  print(heap, size);
  cout << endl;
}


void add(int*& heap, int data, int index) {
  int parentIndex = index / 2;
  //add to heap
  heap[index] = data;
  while (heap[index] > heap[parentIndex] && index > 1) {
    //swap
    int temp = heap[index];
    heap[index] = heap[parentIndex];
    heap[parentIndex] = temp;
    //update index and parent index
    index = parentIndex;
    parentIndex = parentIndex / 2;
  }
}

void print(int* heap, int size) {
  for (int i = 1; i < size; i++) {
    cout << heap[i] << " ";
  }
}

 void printOutput(int*& heap, int index) {
   int size = sizeof(&heap)/sizeof(int);
   int max = index;
  int left = 2 * index;
  int right = 2 * index + 1;
  if (left <= size && heap[left] > heap[max]) {
    max = left;
  }
  if (right <= size && heap[right] > heap[max]) {
    max = right;
  }
  if (max != index) {
    int temp = heap[index];
    heap[index] = heap[max];
    heap[max] = temp;
    printOutput(heap, max);
  }
}
