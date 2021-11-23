#include <iostream>
#include <cstring>

using namespace std;

class Game {
  char title[80];
  int year;
  char publisher[80];
  double rating;
  
 public:
  //constructor
  Game(char* newTitle, int newYear, char* newPublisher, double newRating);
  
  //destructor
  //~Game();
  
  //get methods
  char* getTitle();
  int getYear();
  char* getPublisher();
  double getRating();
  
};
