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

bool Room::hasItem(char* secondWord) {
  for (int i = 0; i < items.size(); i++) {
    if (strcmp(secondWord, items[i]->getDescription()) == 0) {
      return true;
    }
  }
  return false;
}

//for the get item command in main
void Room::removeItem(char* secondWord) {
  for (int i = 0; i < items.size(); i++) {
    if(strcmp(secondWord, items[i]->getDescription()) == 0) {
      items.erase(items.begin() + i);
    }
  }
}

//for the drop item command in main
void Room::addItem(char* secondWord) {
  Item* newItem = new Item(secondWord);
  items.push_back(newItem);
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

void Room::displayItems() {
  if (!items.empty()) {
    cout << "Items available: ";
    for (int i = 0; i < items.size(); i++) {
      cout << items[i]->getDescription() << " ";
    }
    cout << endl;
  }
}



