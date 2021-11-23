#include <iostream>
#include <cstring>
#include "game.h"

using namespace std;

//constructor
Game::Game(char* newTitle, int newYear, char* newPublisher,  double newRating){
  strcpy(title, newTitle);
  year = newYear;
  strcpy(publisher, newPublisher);
  rating = newRating;
}

//destructor
//Game::~Game();
  
//get methods
char* Game::getTitle() {
  return title;
}

int Game::getYear() {
  return year;
}

char* Game::getPublisher() {
  return publisher;
}

double Game::getRating() {
  return rating;
}

