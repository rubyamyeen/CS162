//defines game functions

#include <iostream>
#include <cstring>
#include "game.h"

using namespace std;

//constructor
Game::Game(char* newTitle, int newYear, char* newPublisher, int newRating): Media(newTitle, newYear){
  strcpy(publisher, newPublisher);
  rating = newRating;
}

//destructor
Game::~Game() {
   cout << "in the game destructor" << endl;
}


//display method
void Game::display() {
  cout << title << endl;
  cout << year << endl;
  cout << publisher << endl;
  cout << rating << endl;
}
