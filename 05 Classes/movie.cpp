//defines movie functions

#include <iostream>
#include <cstring>
#include "movie.h"

using namespace std;

//constructor
Movie::Movie(char* newTitle, char* newDirector, int newYear, int newDuration, int newRating): Media(newTitle, newYear){
  strcpy(director, newDirector);
  duration = newDuration;
  rating = newRating;
}

//destructor
Movie::~Movie() {
  cout << "in the movie destructor" << endl;
}

//display method
void Movie::display() {
  cout << title << endl;
  cout << director << endl;
  cout << year << endl;
  cout << duration << endl;
  cout << rating << endl;
  
}
