//blueprint for room
#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Room {
  char description[20];
  struct Item {
    char description[20];
  };
  vector<Item*> items;
  

 public:
  //constructor
  Room(char* newDescription);

  //get method
  char* getDescription();

};

#endif
