#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
  //variables
  bool isPalindrome = false;
  char str[80];
  char reverse[80];
  char punctuation[] = {' ', ',', '.', '-', '?', '!', ':', ';'};
  
  //prompts the user
  cout << "Enter a phrase/word to check if it's a palindrome" << endl;
  cin.get(str, 80, '\n');
  cin.get();
  //cout << str << endl;
  
  //remove punctuation
  for (int i = 0; i < strlen(punctuation); i++) {
      remove(begin(str), end(str), punctuation[i]);
    }
  //lower case
  for (int i = 0; i < strlen(str); i++) {
    str[i] = tolower(str[i]);
  }
  //cout << str << endl;
  
  int index = 0;
  //reverse string
  for (int i = strlen(str) - 1; i >= 0; i--) {
    if (str[i] != '\0') {
  	reverse[index] = str[i];
	index++;
    }
  }
  reverse[index] = '\0';
  //cout << reverse << endl;
  
  //compare strings and check if palindrome
  if (strcmp(str, reverse) == 0) {
    cout <<  "Palindrome." << endl;
  } else {
    cout << "Not a palindrome." << endl;
  }
}
