#include <iostream>
#include <cstring>

using namespace std;

class Movie {
  char title[80];
  char director[80];
  int year;
  int duration;
  int rating;
  
 public:
  //constructor
  Movie(char* newTitle, char* newDirector, int newYear, int newDuration, int Rating);
  
  
  //destructor
  //~Movie();
  
  //get methods
  char* getTitle();
  char* getDirector();
  int getYear();
  int getDuration();
  int getRating();
  
};
