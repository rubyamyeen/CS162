
/*
This program is a guessing game where the computer chooses a random number between 0 and 100. The user guesses the number until they guess the right number and can choose if they want to play again.
Author: Ruby Amyeen
Date: 9/12/21
*/
#include <iostream>
using namespace std;
int main() {
	bool stillPlaying = true;
	while (stillPlaying == true) {
	        //variables
	        int guess = -1;
	        int guessCount = 0;
	        int randNum = -1;
		//setting random seed
		srand(time(NULL));
		//0-100 inclusive
		randNum = rand() % 101;
		//cout << "The random number is " << randNum << endl;
		while (guess != randNum) {
			cout << "Enter a number between 1 and 100: " << endl;
			cin >> guess;
			cout << "You typed: " << guess << endl;
			if (guess < randNum) {
				cout << "Guess is less than random number" << endl;
				cout << "Enter another guess" << endl;
				//checks if guess is less than random number
				guessCount++;
				//adds one to count
			} else if (guess > randNum) {
				cout << "Guess is greater than random number" << endl;
				cout << "Enter another guess" << endl;
				//checks if guess is greater than random number
				guessCount++;
				//adds one to count
			} else {
			  guessCount++;
				cout << "The guess is correct! Congratulations" << endl;
				cout << "Number of guesses: " << guessCount << endl;
				//checks if guess is the random number
			}
		}
		char answer;
		//prompt to play again
		cout << "Do you want to play again? Press y for yes or n for no" << endl;
		cin >> answer;
		if (answer == 'y') {
			stillPlaying = true;
		} else if (answer == 'n') {
			stillPlaying = false;
			cout << "Thank you for playing!";
		} else {
			cout << "Sorry, did not understand response";
		}
	}
	
	return 0;
}
