#include <iostream>
#include <cstring>
#include "music.h"

using namespace std;

//constructor
Music::Music(char* newTitle, char* newArtist, int newYear, int newDuration, char* newPublisher): Media(newTitle, newYear){
  //strcpy(title, newTitle);
  strcpy(artist, newArtist);
  //year = newYear;
  duration = newDuration;
  strcpy(publisher, newPublisher);
}

//destructor
//Music::~Music();
  
//get methods
/*
char* Music::getTitle() {
  return title;
}
*/

char* Music::getArtist() {
  return artist;
}

/*
int Music::getYear() {
  return year;
}
*/

int Music::getDuration() {
  return duration;
}

char* Music::getPublisher() {
  return publisher;
}
