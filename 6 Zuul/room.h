//blueprint for room
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#include "item.h"

using namespace std;

class Room {
  char description[20];
  vector<Item*> items;
  map<char*, Room*> mapExits;
 public:
  //constructor
  Room(char* newDescription);

  //get method
  char* getDescription();

  void setItem(Item *newItem);

  void setExit(char* direction, Room* nextRoom);

  Room* getExit(char* direction);
  
};

#endif
