//defines the parent class functions

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

//constructor
Media::Media(char* newTitle, int newYear) {
  strcpy(title, newTitle);
  year = newYear;
}

//get methods
char* Media::getTitle() {
  return title;
}
int Media::getYear() {
  return year;
}

//destructor
Media::~Media() {
  
}
