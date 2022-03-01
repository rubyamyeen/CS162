//defines item functions
#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

//constructor
Item::Item(char* newDescription) {
  strcpy(description, newDescription);
}

//get method
char* Item::getDescription() {
  return description;
}

