//defines room functions
#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

//constructor
Room::Room(char* newDescription) {
  strcpy(description, newDescription);
}

//get method
char* Room::getDescription() {
  return description;

}
