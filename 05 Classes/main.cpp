/*
 This is main method of the program. It has 4 functions to: add media, search media database, delete media, and quit the program.
Author: Ruby Amyeen
Date: 11/28/21
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <limits>

#include "media.h"
#include "game.h"
#include "music.h"
#include "movie.h"
using namespace std;

//function prototypes
void addMedia(vector<Media*> &mediaList);
void searchMedia(vector<Media*> mediaList);
void deleteMedia(vector<Media*> &mediaList);

int main() {
  
  //variables
  vector<Media*> mediaList;
  bool stillRunning = true;
  
  while(stillRunning == true) {
    char input[10];
    //prompts the user to enter add, search, delete, or quit
    cout << "Please enter: 'ADD', 'SEARCH', 'DELETE', or 'QUIT'" << endl;
    cin >> input;

    //add
    if (strcmp(input, "ADD") == 0) {
      addMedia(mediaList);
      
    //search
    } else if (strcmp(input, "SEARCH") == 0) {
      searchMedia(mediaList);
      
    //delete
    } else if (strcmp(input, "DELETE") == 0) {
      deleteMedia(mediaList);
      
    //quit
    } else if (strcmp(input, "QUIT") == 0) {
      stillRunning = false;
      cout << "Leaving media database" << endl;
    }
  }

  return 0;
}

//method to add media
void addMedia(vector<Media*> &mediaList) {
  char type[20];
  
  cout << "Enter the type of media ('game', 'music', or 'movie'): ";
  cin >> type;

  //game
  if (strcmp(type, "game") == 0) {
    //variables
    char* gameTitle = new char[80];
    int gameYear = 0;
    char* gamePublisher = new char[80];
    int gameRating = 0;

    //title
    cout << "Enter the game title: ";
    //from stack overflow to flush out the cin buffer
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(gameTitle, 80);
    cin.get();

    //year
    cout << "Enter the game release date: ";
    cin >> gameYear;

    //publisher
    cout << "Enter the publisher of the game: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(gamePublisher, 80);
    cin.get();

    //rating
    cout << "Enter game rating: ";
    cin >> gameRating;

    Game* gamePtr = new Game(gameTitle, gameYear, gamePublisher, gameRating);
    mediaList.push_back(gamePtr);
    cout << "Media added!" << endl;
    
  //music
  } else if (strcmp(type, "music") == 0) {
    //variables
    char* musicTitle = new char[80];
    char* musicArtist = new char[80];
    int musicYear = 0;
    int musicDuration = 0;
    char* musicPublisher = new char[80];

    //title
    cout << "Enter the song title: ";
    //from stack overflow to flush out the cin buffer
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(musicTitle, 80);
    cin.get();

    //artist
    cout << "Enter the song artist: ";
    cin.get(musicArtist, 80);
    cin.get();

    //year
    cout << "Enter the song release date: ";
    cin >> musicYear;

    //duration
    cout << "Enter the song duration: ";
    cin >> musicDuration;

    //publisher
    cout << "Enter the publisher of the song: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(musicPublisher, 80);
    cin.get();

    Music* musicPtr = new Music(musicTitle, musicArtist, musicYear, musicDuration, musicPublisher);
    mediaList.push_back(musicPtr);
    cout << "Media added!" << endl;
    
  //movie
  } else if (strcmp(type, "movie") == 0) {
    //variables
    char* movieTitle = new char[80];
    char* movieDirector = new char[80];
    int movieYear = 0;
    int movieDuration = 0;
    int movieRating = 0;

    //title
    cout << "Enter the movie title: ";
    //from stack overflow to flush out the cin buffer
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(movieTitle, 80);
    cin.get();

    //director
    cout << "Enter the movie director: ";
    cin.get(movieDirector, 80);
    cin.get();

    //year
    cout << "Enter the movie release date: ";
    cin >> movieYear;

    //duration
    cout << "Enter the movie duration: ";
    cin >> movieDuration;

    //rating
    cout << "Enter movie rating: ";
    cin >> movieRating;

    Movie* moviePtr = new Movie(movieTitle, movieDirector, movieYear, movieDuration, movieRating);
    mediaList.push_back(moviePtr);
    cout << "Media added!" << endl;
  }
  
  
}

//method to search media
void searchMedia(vector<Media*> mediaList) {
  char input[10];
  cout << "Please enter 'title' to search by title or 'year' to search by year: ";
  cin >> input;
  if (strcmp(input, "title") == 0) {
    char title[80];
    cout << "Enter the title: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(title, 80);
    cin.get();
    for (int i = 0; i < mediaList.size(); i++) {
      if (strcmp(title, mediaList[i]->getTitle()) == 0) {
	mediaList[i]->display();
      }
    }
  } else if (strcmp(input, "year") == 0) {
    int year;
    cout << "Enter the year: ";
    cin >> year;
    for (int i = 0; i < mediaList.size(); i++) {
      if (mediaList[i]->getYear() == year) {
	mediaList[i]->display();
      }
    }
  }
}

//method to delete media
void deleteMedia(vector<Media*> &mediaList) {
  //variables
  char input[10];
  Media* temp;
  char response;
  
  cout << "Please enter 'title' to delete by title or 'year' to delete by year: ";
  cin >> input;
  if (strcmp(input, "title") == 0) {
    char title[80];
    cout << "Enter the title: ";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get(title, 80);
    cin.get();
    for (int i = mediaList.size() - 1; i >= 0; i--) {
      if (strcmp(title, mediaList[i]->getTitle()) == 0) {
	cout << "Do you want to delete:" << endl;
	mediaList[i]->display();
	cout << "Enter 'y' to confirm delete:" << endl;
	cin >> response;
	if (response == 'y') {
	   temp = mediaList[i];
	   delete temp;
	   mediaList.erase(mediaList.begin() + i);
	   break;
	}
      }
    }
  } else if (strcmp(input, "year") == 0) {
    int year;
    cout << "Enter the year: ";
    cin >> year;
    for (int i = mediaList.size() - 1; i >= 0; i--) {
      if (mediaList[i]->getYear() == year) {
	cout << "Do you want to delete:" << endl;
	mediaList[i]->display();
	cout << "Enter 'y' to confirm delete:" << endl;
	cin >> response;
	if (response == 'y') {
	   temp = mediaList[i];
	   delete temp;
	   mediaList.erase(mediaList.begin() + i);
	   cout << "Media deleted!" << endl;
	   break;
	}
      }
    }
  }
}
