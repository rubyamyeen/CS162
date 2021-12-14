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

  bool hasItem(char* secondWord);
  
  void setExit(char* direction, Room* nextRoom);

  void dropItem(char* secondWord);
  
  void displayItems();
  
  Room* getExit(char* direction);
  
};

#endif
