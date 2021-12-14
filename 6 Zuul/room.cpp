//defines room functions
#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

//constructor
Room::Room(char* newDescription) {
  strcpy(description, newDescription);
}

//get method
char* Room::getDescription() {
  return description;

}

void Room::setItem(Item* newItem) {
  items.push_back(newItem);
  //cout << items[0]->getDescription() << endl;
}

void Room::setExit(char* direction, Room* nextRoom) {
  mapExits.insert(pair<char*, Room*>(direction, nextRoom));
}

Room* Room::getExit(char* direction) {
  //cout << direction << endl;
  Room* ptr = NULL;
  for(map<char*, Room*>::iterator it = mapExits.begin();
      it != mapExits.end(); it++) {
    if(strcmp(it->first, direction) == 0) {
      return it->second;
    }
  }
  return ptr;
}



