// File Name: main.cpp
//
// Author: Yessica Gaona Morales
// Collaborators: Timothy Maraj
// Date: 11/16/2020
// Assignment Number: 6
// CS 2308 Fall 2020
//
// This function drives a game of Tic-tac-toe. Players 
// can enter their moves and they are displayed on a board.
// Players can also undo their oppponent's last move. 
// When the win conditions are met, or there is a tie,
// the winner or draw is announced.

#include "GameState.h"
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
using namespace std;

//***********************************************************
// readCommand: Reads user input to determine if they want
//              to perform move or undo their opponents.
// input: The user input.
// returns: User command: "move" or "undo".
//***********************************************************
string readCommand(string input) {
    string command;
	  //the command is in the first 4 char of the string
    for (int i = 0; i < 4; i++) {
        command += input[i];
    }
    return command;
}
//***********************************************************
// converXYInt: Converts the 6th character of the user's
//              input into the x-coordinate of move struct.
// input: The user input.
// returns: The integer x-coordinate of the move struct.
//***********************************************************
int convertXInt(string input) {
    char X = input[5];
    int moveX = X - 48; //ASCII char conversion to number
    return moveX;

}
//***********************************************************
// convertYInt: Converts the 8th character of the user's
//              input into the y-coordinate of move struct.
// input: The user input.
// returns: The integer y-coordinate of the move struct.
//***********************************************************
int convertYInt(string input) {
    char Y = input[7];
    int moveY = Y - 48; ////ASCII char conversion to number
    return moveY;
}


int main() {
    GameState game;  //initialize stack object
    Move playerMove;    //keeps track of board coordinates
    string choice;  //used to read input
    bool keepPlaying = true;    //makes game stop when win or tie
    int addStatus;  //to check board status after move is added
    int currentPlayer;  //keeps track of current player
    bool display = true;

    while (keepPlaying == true) {
        while (display == true) {   //only display board when needed
            game.displayBoardState(cout);
            display = false;
        }
        display = true;
        currentPlayer = game.getCurrentPlayer();
        cout << "Player " << currentPlayer << " make a turn." << endl;
        getline(cin, choice);
        if (readCommand(choice) == "undo") {
            if (game.undoLast() == 0) {     //check if board is emtpty
                cout << "No moves to undo." << endl;
                display = false;
            }
        }
        else {  //read the moves from the string
            playerMove.x = convertXInt(choice);
            playerMove.y = convertYInt(choice);
            addStatus = game.addMove(playerMove);
            if (addStatus == -1) {  //if spot was full, or invalid move
                cout << "Incorrect move. Please try again." << endl;
                display = false;
            }
            else if (addStatus == 0) {  //if added, but board is now full
                keepPlaying = false;
                if (game.checkLastPlayerWin() == 1) {   //last player wins
                    game.displayBoardState(cout);
                    cout << "Player " << currentPlayer << " won!" << endl;
                }
                else {  //there is a tie
                    game.displayBoardState(cout);
                    cout << "It's a draw!" << endl;
                }
            }
            else {  //if there are still spots left
                if (game.checkLastPlayerWin() == 1) {
                    game.displayBoardState(cout);
                    cout << "Player " << currentPlayer << " won!" << endl;
                    keepPlaying = false;
                }
            }
        }
    }
    return 0;
}


