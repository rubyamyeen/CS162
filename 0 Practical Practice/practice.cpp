#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int main() {
  int numbers[8];
  for (int i = 0; i < 8; i++) {
    cout << "Enter a number:" << endl;
    cin >> numbers[i];
  }
  
  int total = 1;
  for (int i = 0; i < 8; i++) {
    if (numbers[i]%7 != 0) {
      total *= numbers[i];
    }
  }
  cout << total << endl;
  
  return 0;
}
