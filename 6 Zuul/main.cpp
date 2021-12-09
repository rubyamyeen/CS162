/*This is the main method of the program. Zuul is text-based adventure game. 
The user will type in commands to move through a maze of rooms, which contain items.
Author: Ruby Amyeen
Date: December 8th, 2021
 */

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
using namespace std;

int main() {
  //variables
  char name[20];
  vector<Room*> roomList;
  
  cout << "What's your name, young hero? ";
  cin.get(name, 20);
  cin.get();
  cout << endl;
  
  cout << name << ", Arcadia is in great danger."
       << endl;
  cout << "The crown of thorns is the only way to save this mystical island." << endl;
  cout << "Meet me at 12 am in the Grand Arts Museum with the crown of thorns." << endl;
  cout << "Fail to do so? Well then the demons will attack at noon..." << endl;
  cout << endl;
  
  cout << "The clock is ticking." << endl;
  cout << "Type 'help' if you have lost your way" << endl;
  cout << endl;

  //trying to create a room instance
  char* description = new char[20];
  strcpy(description, "Grand Arts Museum");
  Room museum(description);
  cout << museum.getDescription() << endl;
  roomList.push_back(&museum);
  cout << roomList[0]->getDescription() << endl;
	 
  

  
  return 0;
}
