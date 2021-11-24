#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;
class Media {
protected:
  char title[80];
  int year;
  
public:
  //constructor
  Media(char* newTitle, int newYear);

  //destructor
  //~Media();

  //get methods
  char* getTitle();
  int getYear();
  
};

#endif
