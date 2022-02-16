/*
This is the main method for the Shunting Yard Algorithm. 
Uses the Shunting Yard Algorithm to turn the expression from the user into postfix notation and then creates a binary tree to find the infix, prefix and postfix notation. 
Author: Ruby Amyeen
Date 2/14/22
*/

//Referenced code from GeeksforGeeks

#include <iostream>
#include <cstring>

using namespace std;

//node struct
struct Node {
  char data;
  Node* next;
public:
  Node() {
    data = '\0';
    next = NULL;
  }
  Node(char newData) {
    data = newData;
    next = NULL;
  }
};

//stack class
class Stack {
  Node* top;
//functions
public:
  Stack();
  ~Stack();
  void push(char operation);
  void pop();
  char peek();
  void display();
};


//queue class
class Queue {
  Node* front;
  Node* rear;
//functions
public:
  Queue();
  ~Queue();
  void enqueue(char operation); //add nodes to rear
  void dequeue(); //removes from front
  void display();
};

int main() {

  Stack* stack = new Stack();
  Queue* queue = new Queue();
  char expression[20];
  char notation[10];
  
  cout << "Enter a mathematical expression:" << endl;
  cin.get(expression, 20);
  cin.get();

  for (int i = 0; i < strlen(expression); i += 2) { // + 2 to skip spaces
  }

  cout << "Enter the notation ('infix', 'prefix', 'postfix') you'd like to output the expression:" << endl;
  cin.get(notation, 10);
  cin.get();
  
  cout << "Expression: " << expression << endl;
  cout << "Notation: " << notation << endl;

  //creating a stack
  stack->push('A');
  stack->push('B');
  stack->push('C');
  
  stack->display();
  stack->pop(); 
  cout << endl;
  stack->display();

  cout << endl;
  
  //creating a queue
  queue->enqueue('A');
  queue->enqueue('B');
  queue->enqueue('C');

  queue->display(); 
  queue->dequeue();
  cout << endl;
  queue->display();
  

  
  
  return 0;
}




//STACK FUNCTIONS DEFINED
//constructor
Stack::Stack() {
  top = NULL;
}

//deconstructor
Stack::~Stack() {
  if (top != NULL) {
    pop();
  }
}

//push function
void Stack::push(char operation) {
  Node* temp = new Node(operation);
  temp->next = top; //old top of the stack
  top = temp; // new node becomes the top
}

//pop function
void Stack::pop() {
  if (top != NULL) {
    Node* temp = top;
    top = temp->next;
    delete temp;
  }
}

//peek function
char Stack::peek() {
  return top->data;
}

//display test
void Stack::display() {
  Node* current = top;
  while (current != NULL) {
    cout << current->data << endl;
    current = current->next;
  }
}

//QUEUE FUNCTIONS DEFINED
//constructor
Queue::Queue() {
  front = rear = NULL;
}

//deconstructor
Queue::~Queue() {
}

//adding to rear function
void Queue::enqueue(char operation) {
  Node* temp = new Node(operation);
  if (rear == NULL) {
    front = rear = temp;
  }
  rear->next = temp;
  rear = temp;
}

//removing from front function
void Queue::dequeue() {
  if (front == NULL) {
    return;
  }

  Node* temp = front;
  front = front->next;

  if (front == NULL) {
    rear = NULL;
  }

  delete temp;
}

void Queue::display() {
  Node* current = front;
  while (current != NULL) {
    cout << current->data << endl;
    current = current->next;
  }
}
