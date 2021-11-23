#include <iostream>
#include <cstring>

using namespace std;

class Music {
  char title[80];
  char artist[80];
  int year;
  int duration;
  char publisher[80];
  
 public:
  //constructor
  Music(char* newTitle, char* newArtist, int newYear, int newDuration, char* newPublisher);
  
  
  //destructor
  //~Music();
  
  //get methods
  char* getTitle();
  char* getArtist();
  int getYear();
  int getDuration();
  char* getPublisher();
  
};
