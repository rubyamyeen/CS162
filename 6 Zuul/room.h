//blueprint for room
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
using namespace std;

class Room {
  char description[20];
 public:
  //constructor
  Room(char* newDescription);

  //get method
  char* getDescription();

  
};

#endif
