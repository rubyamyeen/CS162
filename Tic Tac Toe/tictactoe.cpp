/*
This program is 2 player game of tic-tac-toe
Author: Ruby Amyeen
Date: 9/20/21
*/

#include <iostream>
using namespace std;

//prototype functions
void printBoard(int board[3][3]);
void clearBoard(int board[3][3]);
bool checkWin(int board[3][3], int player);
bool checkTie(int board[3][3]);

int main() {
  //variables
  int blank = 0;
  int xMove = 1;
  int oMove = 2;
  int xTurn = 0;
  int oTurn = 1;
  int turn = xTurn;
  int board[3][3];
  
  int xWins = 0;
  int oWins = 0;
  bool stillPlaying = true;
  
   while (stillPlaying == true) {
     clearBoard(board);
     cout << "To make a move: Enter the row letter (a, b, c) followed by a column number (1, 2, 3)" << endl;
     while (checkWin(board, xMove) == false && checkWin(board, oMove) == false && checkTie(board) == false) {
       printBoard(board);
       char input[20];
       cin >> input;
       if(strlen(input) != 2) {
	 cout << "Enter a letter followed by a number" << endl;
       }
       //if the user entered the row letter incorrectly
       else if(input[0] != 'a' &&
	       input[0] != 'b' &&
	       input[0] != 'c') {
	 cout << "Row must be an a, b, or c" << endl;
       }
       else if(input[1] != '1' &&
	       input[1] != '2' &&
	       input[1] != '3') {
	 cout << "Column must be an a, b, or c" << endl;
       }
       else {
	 //plays move
	 int row = input[0] - 'a';
	 int column = input[1] - '1';
	 //makes sure move is placed on a free spot
	 if (board[row][column] == blank) {
	   if (turn == xTurn) {
	     board[row][column] = xMove;
	     turn = oTurn;
	   }
	   else {
	     board[row][column] = oMove;
	     turn = xTurn;
	   }
	 }
	 else {
	   cout << "There is a piece there! Please try again" << endl;
	 }
       }
     }
     if (checkWin(board, xMove) == true) {
       cout << "X wins!" << endl;
       xWins++;
     }
     else if (checkWin(board, oMove) == true) {
       cout << "O wins!" << endl;
       oWins++;
     }
     if (checkTie(board) == true && checkWin(board, xMove) == false &&  checkWin(board, oMove) == false) {
       cout << "It's a tie!" << endl;
     }
     cout << "X wins: " << xWins << ", O wins: " << oWins << endl;
     cout << "Would you like to play again?" << endl;
     cout << "Enter yes or no" << endl;
     char yesno[2];
     cin >> yesno;
     if (yesno[0] == 'y') {
       stillPlaying = true;
       turn = xTurn;
     }
     else {
       stillPlaying = false;
       cout << "Thank you for playing!" << endl;
     }
   }
     
 }

//method to print board
void printBoard(int board[3][3]) {
  int blank = 0;
  int xMove = 1;
  int oMove = 2;
  cout << " \t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    char outputRow = 'a' + row;
    cout << outputRow << "\t";
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == blank) {
        cout << " \t";
      }
      else if (board[row][column] == xMove) {
	cout << "X\t";
      }
      else if (board[row][column] == oMove) {
	cout << "O\t";
      }
    }
    cout << endl;
  }
}

//method to clear board
void clearBoard(int board[3][3]) {
  int blank = 0;
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column <  3; column++) {
      board[row][column] = blank;
    }
  }
}

//method to check win
bool checkWin(int board[3][3], int player) {
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    return true;
  }
  return false;
}

//method to check tie
bool checkTie(int board[3][3]) {
  int blank = 0;
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == blank) {
	return false;
      }
    }
  }
  return true;
}

  


