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

//function prototypes
void Welcome();
void createRooms(vector<Room*> &roomList);

//struct for Items
/*struct Item {
  char description[20];
  };*/

int main() {
  //variables
  char command[20];
  vector<Room*> roomList;
  //vector<Item*> inventory;
  const char* commandWords[6] = {"go", "quit", "help", "inventory", "get", "drop"};
  char input[40];
  int spaceIndex = 0;
  bool hasSpace;
  bool stillPlaying = true;
  
  Welcome();
  
  while (stillPlaying == true) {
    cout << endl;
    cout << "Enter a command: ";
    cin.get(input, 40);
    cin.get();
    
    for (int i = 0; i < strlen(input); i++) {
      if (input[i] == ' ') {
	spaceIndex = i;
	hasSpace = true;
	//cout << "There's a space at index: " << spaceIndex << endl;
      }
    }

    //help
    if (strcmp(input, "help") == 0) {
      cout << "You are lost. You are alone. You wander around the island." << endl;
      cout << "Your command words are: ";
      for (int i = 0; i < 6; i++) {
	cout << commandWords[i] << " ";
      }
      cout << endl;

    //inventory
    } else if (strcmp(input, "inventory") == 0) {
      cout << "You are carrying: " << endl;

    //quit
    } else if (strcmp(input, "quit") == 0) {
      stillPlaying = false;
      cout << "Thank you for playing!" << endl;

    //action commands
    } else if(hasSpace) {
      
      //go
      if (spaceIndex == 2) {
	cout << "Where do you want to go?" << endl;

      //get
      } else if (spaceIndex == 3) {
	cout << "What do you want to get?" << endl;

      //drop
      } else if (spaceIndex == 4) {
	cout << "What do you want to drop?" << endl;
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
  cout << "Meet me at 12 am in the Grand Arts Museum of the Palace with the crown of thorns." << endl;
  cout << endl;
  
  cout << "Type 'help' if you need help." << endl;
}

/*creating 15 rooms:(1) Grand Arts Museum,(2) Main Hall,(3) Weapons Room,(4) Blacksmith's Workshop,
(5) Outside the Palace,(6) Garden,(7) Fountain of Youth,(8) Library,(9) Sparring Room,
(10) Medical Wing,(11) Courtyard,(12) Theatre, (13) Private Studies,(14) Dining, (15), Market
*/
void createRooms(vector<Room*> &roomList) {
  //trying to create a room instance
  char* description = new char[20];
  strcpy(description, "Grand Arts Museum");
  Room museum(description);
  cout << museum.getDescription() << endl;
  roomList.push_back(&museum);
  cout << roomList[0]->getDescription() << endl;
 
}

