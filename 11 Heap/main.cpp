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
void generate(int*& heap, int& size);
void userInput(int*& heap, int& size);
void add(int*& heap, int data, int index);
void print(int* heap, int size);
void printOutput(int*& heap, int& index, int& size);
void printTree(int index, int* heap, int depth, int size);

int main() {
  //variables
  int* heap = new int[100];
  int heapSize = 0;
  int* output = new int[100];

  //empty heap
  for (int i = 0; i < 100; i++) {
    heap[i] = 0;
  }
  //empty output
  for (int i = 0; i < 100; i++) {
    output[i] = 0;
  }
  
  char input[20];
  //prompts the user to enter add by file or user input
  cout << "Please enter 'file' to add by file or 'input' to add by user input:" << endl;
  cin >> input;

  if (strcmp(input, "file") == 0) {
    generate(heap, heapSize);
    cout << endl;
  } else if (strcmp(input, "input") == 0) {
    userInput(heap, heapSize);
    cout << endl;
  }
  
  int index = 1;
  
  printTree(1, heap, 0, heapSize);
  cout << endl;
  
  cout << "Output: " << endl;
  printOutput(heap, index, heapSize);
  cout << endl;
  
  return 0;
}

//function to generate
void generate(int*& heap, int& size) {
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
  size = index - 1;
  //cout << "Size from gen func: " << size << endl;
  cout << "Heap: " << endl;
  print(heap, size);
  fin.close();
  cout << endl;
}

//function to input from user
void userInput(int*& heap, int& size) {
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
  size = index - 2;
  //cout << size << endl;
  cout << "Heap: " << endl;
  print(heap, size);
  cout << endl;
}

//add function
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

//print function
void print(int* heap, int size) {
  for (int i = 1; i < size+1; i++) {
    cout << heap[i] << " ";
  }
}

//print output function
void printOutput(int*& heap, int& index, int& size) { 
  index = 1;
  int last = size;
  
  //print output
  cout << heap[1] << " ";  
  int rootData = heap[last];
  
  //replace root with last
  heap[1] = heap[last];
  heap[last] = 0;  
  size--;
  
  //checks if root needs to be swapped
  while(heap[index*2] != 0) {
    if (heap[index] < heap[index*2] || heap[index] < heap[index*2+1]) {
      if (heap[index*2] > heap[index*2+1]) {
	//swap root with left
	int temp = heap[index];
	heap[index] = heap[index*2];
	heap[index*2] = temp;
	index = index*2;
      } else {
	//swap root with right
	int temp = heap[index];
	heap[index] = heap[index*2+1];
	heap[index*2+1] = temp;
	index = index*2+1;

      } 
    } else {
      break;
    }
  }

  //recursion
  if(size != 0) {
    printOutput(heap, index, size);
  }
  
}

//print tree function
void printTree(int index, int* heap, int depth, int size) {
  //right 
  if (index*2+1 <= size && heap[index*2+1] != 0) {
    printTree(index*2+1, heap, depth+1, size);
  }
  for(int i = 0; i < depth; i++) {
    cout << "\t";
  }
  cout << heap[index] << endl;
   //left 
  if (index*2 <= size && heap[index*2] != 0) {
    printTree(index*2, heap, depth+1, size);
  }
}
