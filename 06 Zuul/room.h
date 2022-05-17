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

  //method to set item
  void setItem(Item *newItem);

  //checks if room has certain item
  bool hasItem(char* secondWord);

  //method to set exits
  void setExit(char* direction, Room* nextRoom);

  //method to add item
  void addItem(char* secondWord);

  //method to remove item
  void removeItem(char* secondWord);

  //displays what items are available in room
  void displayItems();

  //gives the exit room for a direction
  Room* getExit(char* direction);
  
};

#endif
