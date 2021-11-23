#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

//constructor
Movie::Movie(char* newTitle, char* newDirector, int newYear, int newDuration, int newRating){
  strcpy(title, newTitle);
  strcpy(director, newDirector);
  year = newYear;
  duration = newDuration;
  rating = newRating;
}

//destructor
//Movie::~Movie();
  
//get methods
char* Movie::getTitle() {
  return title;
}

char* Movie::getDirector() {
  return director;
}

int Movie::getYear() {
  return year;
}

int Movie::getDuration() {
  return duration;
}

int Movie::getRating() {
  return rating;
}
