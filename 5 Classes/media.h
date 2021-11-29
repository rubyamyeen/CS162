//blueprint of the parent class

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

  //virtual function
  virtual void display() = 0;

  //get methods
  char* getTitle();
  int getYear();

  //destructor
  virtual ~Media();
  
};

#endif
