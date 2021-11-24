#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

//constructor
Media::Media(char* newTitle, int newYear) {
  strcpy(title, newTitle);
  year = newYear;
}

//destructor
//Media::~Media();

//get methods
char* Media::getTitle() {
  return title;
}
int Media::getYear() {
  return year;
}
