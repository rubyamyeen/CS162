#include <iostream>
#include <cstring>
#include "media.h"
#include "game.h"
#include "music.h"
#include "movie.h"
using namespace std;

int main() {
  char* title = new char[80];
  strcpy(title, "Super Smash Bros");
  char* publisher = new char[80];
  strcpy(publisher, "Nintendo");
  Game ssb(title, 2019, publisher, 5.0);
  cout << ssb.getYear() << endl;
  cout << ssb.getRating() << endl;
  cout << ssb.getTitle() << endl;
  cout << ssb.getPublisher() << endl;

  char* martist = new char[80];
  strcpy(martist, "NIKI");
  char* mpublisher = new char[80];
  strcpy(mpublisher, "Universal Publishing Group");
  Music lowkey(title, martist, 2019, 3, mpublisher);
  cout << lowkey.getYear() << endl;
  cout << lowkey.getDuration() << endl;
  cout << lowkey.getTitle() << endl;
  cout << lowkey.getPublisher() << endl;
  cout << lowkey.getArtist() << endl;

  
}
