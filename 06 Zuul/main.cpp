/*This is the main method of the program. Zuul is text-based adventure game. 
The user will type in commands to move through a maze of rooms, which contain items.
Author: Ruby Amyeen
Date: December 8th, 2021
 */

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

//function prototypes
void Welcome();

int main() {
  //variables
  Room* currentRoom;
  char secondWord[80];
  char firstCommand[10];
  char* roomDescription = new char[80];
  char* itemDescription = new char[80];
  
  vector<Room*> roomList;
  vector<Item*> inventory;
  vector<Item*> itemList;
  
  const char* commandWords[6] = {"go", "quit", "help",
    "inventory", "get", "drop"};

  //directions
  char* north = new char[10];
  strcpy(north, "north");
  char* east = new char[10];
  strcpy(east, "east");
  char* south = new char[10];
  strcpy(south, "south");
  char* west = new char[10];
  strcpy(west, "west");
  
  
  /*Rooms: (0) museum, (1)hall, (2)weapons, (3)workshop,
 (4)outside, (5)garden, (6)fountain, (7)library,
 (8)sparring, (9)meds, (10)courtyard, (11)theator
 (12)studies, (13)dining, (14)market
   */
  const char* roomDescriptionList[15] = {"Grand Arts Museum",
    "Main Hall", "Weapons Room", "Blacksmith's Workshop",
    "Outer Palace", "Garden", "Fountain of Youth",
    "Library", "Sparring Room", "Medical Wing", "Courtyard",
    "Theatre", "Private Studies", "Dining Hall", "Market"};
  
  const char* itemDescriptionList[5] = {"crown of thorns", "javelin",
    "bronze", "anthology", "scalpel"};
  
  char input[40];
  int spaceIndex = 0;
  bool hasSpace;
  bool stillPlaying = true;

  //CREATE ROOMS
  for (int i = 0; i < 15; i++) {
    strcpy(roomDescription, roomDescriptionList[i]);
    Room* rPtr = new Room(roomDescription);
    roomList.push_back(rPtr);
    //cout << rPtr->getDescription() << endl;
  }

  //CREATE ITEMS
  for (int i = 0; i < 5; i++) {
    strcpy(itemDescription, itemDescriptionList[i]);
    Item* iPtr = new Item(itemDescription);
    itemList.push_back(iPtr);
    //cout << iPtr->getDescription() << endl;
  }
  
  //setting items
  roomList[10]->setItem(itemList[0]); //crown in courtyard
  roomList[2]->setItem(itemList[1]); //javelin in weapons
  roomList[3]->setItem(itemList[2]); //bronze in workshop
  roomList[7]->setItem(itemList[3]); //anthology in library
  roomList[9]->setItem(itemList[4]); //scalpel in med wing
  
  Welcome();

  //set exits
  
  //outside (4)  
  roomList[4]->setExit(east, roomList[11]);
  roomList[4]->setExit(south, roomList[1]);
  roomList[4]->setExit(west, roomList[3]);
  roomList[4]->setExit(north, roomList[5]);

  //theatre (11)
  roomList[11]->setExit(west, roomList[4]);
  roomList[11]->setExit(south, roomList[7]);

  //library (7)
  roomList[7]->setExit(north, roomList[11]);
  roomList[7]->setExit(south, roomList[12]);

  //studies (12)
  roomList[12]->setExit(north, roomList[7]);
  roomList[12]->setExit(west, roomList[13]);
  roomList[12]->setExit(south, roomList[0]);

  //dining (13)
  roomList[13]->setExit(east, roomList[12]);
  roomList[13]->setExit(west, roomList[1]);
  roomList[13]->setExit(south, roomList[9]);

  //museum (0)
  roomList[0]->setExit(north, roomList[12]);
  roomList[0]->setExit(west, roomList[9]);

  //main hall(1)
  roomList[1]->setExit(east, roomList[13]);
  roomList[1]->setExit(north, roomList[4]);

  //med wing (9)
  roomList[9]->setExit(north, roomList[13]);
  roomList[9]->setExit(east, roomList[0]);

  //workshop (3)
  roomList[3]->setExit(east, roomList[4]);
  roomList[3]->setExit(north, roomList[14]);
  roomList[3]->setExit(south, roomList[2]);

  //market (14)
  roomList[14]->setExit(south, roomList[3]);

  //weapons (2)
  roomList[2]->setExit(north, roomList[3]);
  roomList[2]->setExit(west, roomList[8]);

  //sparring room (8)
  roomList[8]->setExit(east, roomList[2]);

  //garden (5)
  roomList[5]->setExit(south, roomList[4]);
  roomList[5]->setExit(east, roomList[10]);

  //courtyard (10)
  roomList[10]->setExit(west, roomList[5]);
  roomList[10]->setExit(north, roomList[6]);

  //fountain (6)
  roomList[6]->setExit(south, roomList[10]);
  
  currentRoom = roomList[4];
  
  while (stillPlaying == true) {
    cout << endl;
    cout << "Enter a command: ";
    cin.get(input, 40);
    cin.get();
    
    for (int i = 0; i < strlen(input); i++) {
      if (input[i] == ' ') {
	spaceIndex = i;
	hasSpace = true;
	//command word when user inputs two words
	strncpy(firstCommand, input, spaceIndex);
	//set second words to what's after the space
	strncpy(secondWord, input + (spaceIndex+1), strlen(input) - spaceIndex);
	break;
      }
    }

    //help
    if (strcmp(input, "help") == 0) {
      cout << "You are lost. You are alone. "
	   << "You wander around the island." << endl;
      cout << "You are in the " << currentRoom->getDescription()
	   << "." << endl;
      cout << "Your command words are: ";
      for (int i = 0; i < 6; i++) {
	cout << commandWords[i] << " ";
      }
      cout << endl;
      //cout << endl;

    //inventory
    } else if (strcmp(input, "inventory") == 0) {
      if (inventory.empty()) {
	cout << "Your inventory is empty!" << endl;
      } else {
	cout << "You are carrying: ";
	for (int i = 0; i < inventory.size(); i++) {
	  cout << inventory[i]->getDescription() << " ";
	}
	cout << endl;
      }
    //quit
    } else if (strcmp(input, "quit") == 0) {
      stillPlaying = false;
      cout << "Thank you for playing!" << endl;
      cout << endl;

    //action commands
    } else if(hasSpace) {
      
      //go
      if (spaceIndex == 2) {
	Room* nextRoom = currentRoom->getExit(secondWord);
	if (nextRoom != NULL) {
	  currentRoom = nextRoom;
	  cout << "You are in the " <<
	    currentRoom->getDescription() << "." << endl;
	  currentRoom->displayItems();
	} else {
	  cout << "There is nowhere to go..." << endl;
	}
        

	
      //get
      } else if (spaceIndex == 3) {
	bool hasItem = false;
	for (int i = 0; i < 5; i++) {
	  if((currentRoom->hasItem(secondWord)) &&
	   (strcmp(secondWord, itemList[i]->getDescription()) == 0)) {
	    currentRoom->removeItem(secondWord);
	    inventory.push_back(itemList[i]);
	    cout << "You picked up " << secondWord << endl;
	    hasItem = true;
	    break;
	  }
	}
	if (hasItem == false) {
	  cout << "Item can't be picked up!" << endl;
	}
	
      //drop
      } else if (spaceIndex == 4) {
	bool dropped = false;
	for (int i = 0; i < inventory.size(); i++) {
	  if(strcmp(secondWord, inventory[i]->getDescription()) == 0) {
	      inventory.erase(inventory.begin() + i);
	      currentRoom->addItem(secondWord);
	      cout << "Item was dropped." << endl;
	      dropped = true;
	      break;
	  }
	}
	if (dropped == false) {
	  cout << "Item could not be dropped!" << endl;
	}
	
      }
    }
     //checkwin
    if (strcmp("Grand Arts Museum", currentRoom->getDescription()) == 0) {
      for (int i = 0; i < inventory.size(); i++) {
	if (strcmp(inventory[i]->getDescription(), "crown of thorns") == 0) {
	  cout << "You win!" << endl;
	  stillPlaying = false;
	}
      }
    }
  }
  
  return 0;
}

//print welcome stuff
void Welcome() {
  char name[20];
  cout << "What's your name, young hero? ";
  cin.get(name, 20);
  cin.get();
  cout << endl;
  
  cout << name << ", Arcadia is in great danger." << endl;
  cout << "The crown of thorns is the only way to save this mystical island." << endl;
  cout << "Meet me at 12 am at the Grand Arts Museum with the crown of thorns." << endl;
  cout << endl;
  
  cout << "Type 'help' if you need help." << endl;
}


