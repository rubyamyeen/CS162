//blueprint for movie

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie: public Media {
  char director[80];
  int duration;
  int rating;
  
 public:
  //constructor
  Movie(char* newTitle, char* newDirector, int newYear, int newDuration, int Rating);
  
  //destructor
  ~Movie();

  void display();
  
};

#endif
