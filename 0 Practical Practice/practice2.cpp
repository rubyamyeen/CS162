#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char str[20];
  char removedVowels[20];
  cout << "Enter a phrase:" << endl;
  cin.get(str, 20);
  cin.get();
  int index = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != 'a' && str[i] != 'e'
	&& str[i] != 'i' && str[i] != 'u'
	&& str[i] != 'o') {
      removedVowels[index] = str[i];
      index++;
    }
  }
  cout << removedVowels << endl;
  return 0;
}
