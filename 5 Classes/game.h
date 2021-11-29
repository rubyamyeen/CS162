//blueprint for game

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Game: public Media{
  char publisher[80];
  int rating;
  
 public:
  //constructor
  Game(char* newTitle, int newYear, char* newPublisher, int newRating);

  //destructor
  ~Game();
  
  void display();
  
};

#endif
