#include <iostream>
#include <cstring>

using namespace std;

int main() {
  
  char input[20];
  
  cout << "Enter a phrase:" << endl;
  cin.get(input, 20);
  cin.get();
  
  cout << input << endl;
  int index = 0;
  char temp = input[index];
  input[index] = input[index+1];
  input[index+1] = temp;
  //cout << input << endl;
  for (index = 0; index < strlen(input); index++) {
    if ((input[index-1] == ' ') && (input[index+1] != ' ') && (input[index+1] != '\0')) {
       temp = input[index];
       input[index] = input[index + 1];
       input[index + 1] = temp;
       cout << input << endl;
    }
  }
  cout << input << endl;
  return 0;
}