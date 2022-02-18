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
      /*
    //if operator and it has higher precedence than the top of the stack
    } else if(isOperator(expression[i])) {
      while(precedence(expression[i]) < precedence(stack->peek())
	    || (precedence(expression[i]) == precedence(stack->peek())
		&& expression[i] != '^')) {
	queue->enqueue(stack->peek());
	stack->pop();
      }
      stack->push(expression[i]);
    }
  
  
  
	      precedence(expression[i]) > precedence(stack->peek())) {
      stack->push(expression[i]);

    //if operator and it had lower precedence or same as top of stack
    } else if(isOperator(expression[i]) && precedence(expression[i]) <= precedence(stack->peek())) {
      while (
    }
    */
  }

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

  /*creating a stack
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
  */

  
  
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
