/*
This is the main method for the Shunting Yard Algorithm. 
Uses the Shunting Yard Algorithm to turn the expression from the user into postfix notation and then creates a binary tree to find the infix, prefix and postfix notation. 
Author: Ruby Amyeen
Date 2/14/22
*/

//Referenced code from GeeksforGeeks (for stacks and queues)

#include <iostream>
#include <cstring>
#include "node.h"

using namespace std;

//function prototypes
bool isOperator(char character);
int precedence(char operation);

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

struct BStackNode {
  BNode* data;
  BStackNode* next;
public:
  BStackNode() {
    data = NULL;
    next = NULL;
  }
  BStackNode(BNode* newData) {
    data = newData;
    next = NULL;
  }
};


//stack for building tree
class BStack {
  BStackNode *top;
public:
   BStack();
  ~BStack();
  void push(BNode* newData);
  void pop();
  BNode* peek();
  void display();
  bool isEmpty();
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
  bool isEmpty();
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
  char expression[100];
  char notation[10];
  
  cout << "Enter a mathematical expression:" << endl;
  cin.get(expression, 100);
  cin.get();

  //shunting yard (referred to wiki page for algorithm)
  for (int i = 0; i < strlen(expression); i += 2) { // + 2 to skip space
    
    //if number/variable put into queue
    if (!isOperator(expression[i]) && expression[i] != '(' && expression[i] != ')') {
      //cout << expression[i] << " is a number/variable" << endl;
      queue->enqueue(expression[i]);

    //if operator
    } else if(isOperator(expression[i])) {
      if (stack->isEmpty() || stack->peek() == '(') {
	stack->push(expression[i]);
      } else {
	while(stack->peek() != '(' && (precedence(expression[i]) < precedence(stack->peek())
				       || (precedence(expression[i]) == precedence(stack->peek())
					   && expression[i] != '^'))) {
	  queue->enqueue(stack->peek());
	  stack->pop();
	}
	stack->push(expression[i]);
      }
  
    //if left parenthesis push to stack
    } else if (expression[i] == '(') {
      stack->push(expression[i]);
     
    //if right parenthesis then pop stack into queue until
    //left parenthesis (matching parenthesis) is at top
    } else if (expression[i] == ')') {
      while (stack->peek() != '(' && !(stack->isEmpty())) {
	queue->enqueue(stack->peek()); //moves top of stack to queue
	stack->pop(); //deletes top
      }
      stack->pop(); //deletes left parenthesis

    }
     
  }

  //for leftover operations
  while (!stack->isEmpty()) {
      queue->enqueue(stack->peek());
      stack->pop();
  }

  cout << endl;

  cout << "Postfix: ";
  queue->display();

  cout << "Infix: " << expression << endl;

  
  cout << "Enter the notation ('infix', 'prefix', 'postfix') you'd like to output the expression:" << endl;
  cin.get(notation, 10);
  cin.get();
  
  cout << "Expression: " << expression << endl;
  cout << "Notation: " << notation << endl;

  
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
  if (!isEmpty()) {
    Node* temp = top;
    top = temp->next;
    delete temp;
  } else {
    exit(1);
  }
}

//peek function
char Stack::peek() {
  if (!isEmpty()) {
    return top->data;
  } else {
    exit(1);
  }
}

//display test
void Stack::display() {
  Node* current = top;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

 bool Stack::isEmpty() {
   return (top == NULL);
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

//test to display for queue
void Queue::display() {
  Node* current = front;
  while (current != NULL) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

//method to check if character is an operator
 bool isOperator(char character) {
   if (character == '^' || character == '*'
       || character == '/' || character == '+' || character == '-') {
     return true;
   } else {
     return false;
   }
 }

//checks precedence
int precedence(char operation) {
  if (operation == '^') {
    return 4;
  } else if (operation == '*' || operation == '/') {
    return 3;
  } else if (operation == '+' || operation == '-') {
    return 2;
  }
  return 0;
}




//BSTACK FUNCTIONS DEFINED (copy and pasted)
//constructor
BStack::BStack() {
  top = NULL;
}

//deconstructor
BStack::~BStack() {
  if (top != NULL) {
    pop();
  }
}

//push function
void BStack::push(BNode* newData) {
  BStackNode* temp = new BStackNode(newData);
  temp->next = top; //old top of the stack
  top = temp; // new node becomes the top
}

//pop function
void BStack::pop() {
  if (!isEmpty()) {
    BStackNode* temp = top;
    top = temp->next;
    delete temp;
  } else {
    exit(1);
  }
}

//peek function
BNode* BStack::peek() {
  if (!isEmpty()) {
    return top->data;
  } else {
    exit(1);
  }
}

//display test
void BStack::display() {
  BStackNode* current = top;
  while (current != NULL) {
    cout << current->data->getValue() << " ";
    current = current->next;
  }
  cout << endl;
}

 bool BStack::isEmpty() {
   return (top == NULL);
 }
