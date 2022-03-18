/*
 *This program creates a heap from the user-entered numbers or a file with numbers. 
 *It also has a visual representation of a tree.
 *Author: Ruby Amyeen
 *Date: 3/14/22
 */

#include <iostream>
#include <cstring>
using namespace std;

//function prototypes
void generate(int*& heap);
void input(int*& heap);
void add(int*& heap, int data, int index);
void print(int* heap);
void printOutput(int*& heap, int data, int index);


int main() {
  int* heap = new int[100];

  //empty heap
  for (int i = 0; i < 100; i++) {
    heap[i] = 0;
  }
  
  return 0;
}


void generate(int*& heap) {
  //get file
  //ask for file name
  //add using add function
}
