//Defines all the music functions

#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

//constructor
Music::Music(char* newTitle, char* newArtist, int newYear, int newDuration, char* newPublisher): Media(newTitle, newYear){
  strcpy(artist, newArtist);
  duration = newDuration;
  strcpy(publisher, newPublisher);
}

//destructor
Music::~Music() {
   cout << "in the music destructor" << endl;
}

//display method
void Music::display() {
  cout << title << endl;
  cout << artist << endl;
  cout << year << endl;
  cout << duration << endl;
  cout << publisher << endl;
}
