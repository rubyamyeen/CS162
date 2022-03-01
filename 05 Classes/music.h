//blueprint for music

#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music: public Media {
  char artist[80];
  int duration;
  char publisher[80];
  
 public:
  //constructor
  Music(char* newTitle, char* newArtist, int newYear, int newDuration, char* newPublisher);
  
  
  //destructor
  ~Music();

  void display();
  
};

#endif
