// File Name: GameState.cpp
//
// Author: Yessica Gaona Morales
// Collaborators: Timothy Maraj
// Date: 11/16/2020
// Assignment Number: 6
// CS 2308 Fall 2020
//
// This program represents the current state of the 
// Tic-tac-toe game. The current state is stored in the 
// "gameState" variable and past moves in the "moveStack"
// variable. The functions used to drive the game are 
// defined in this file.

#include <iomanip>
#include <iostream>
#include <cctype>
#include <string>
#include "GameState.h"
using namespace std;

int sizeOfStack = 0;    //to keep track of which player is next

//***********************************************************
// checkLastPlayerWin: Checks the current state of the board to 
//                     see if the last player won the game.
// returns: If the last player met conditions to win the game, 

//          returns true, else returns false.
//***********************************************************
bool GameState::checkLastPlayerWin() {
    char targetSymbol = this->getCurrentPlayer() ? 'x' : 'o';
    int sumHorizontal, sumVertical;
    for (int i = 0; i < 3; ++i) {
        sumHorizontal = 0;
        sumVertical = 0;
        for (int j = 0; j < 3; ++j) {
            sumHorizontal += this->boardState[i][j] == targetSymbol;
            sumVertical += this->boardState[j][i] == targetSymbol;
        }
        if (sumHorizontal == 3 || sumVertical == 3)
            return true;
    }
    int sumDiagonal1 = 0, sumDiagonal2 = 0;
    for (int i = 0; i < 3; ++i) {
        sumDiagonal1 += this->boardState[i][i] == targetSymbol;
        sumDiagonal2 += this->boardState[i][2 - i] == targetSymbol;
    }
    if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
        return true;

    return false;
}

//***********************************************************
// GameState: Initializes the board.
//***********************************************************
GameState::GameState() {
    //sets every element in the board to empty (underscore)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            boardState[i][j] = '_';
    }
}

//***********************************************************
// getCurrentPlayer: Returns player that needs to make the
//                   next move.
// player: the number associated with said player.
//***********************************************************
int GameState::getCurrentPlayer() {
    //uses size of move stack to get current player
    if (sizeOfStack % 2 == 0)
        return 0;
    else
        return 1;
}

//***********************************************************
// addMove: Updates the board and stack given a move.
//
// move: The move of type Move.
// returns: If the given move is invalid, returns -1. If the move
//          was added, but the board is now full, retruns 0.
//          If move was added, and there are spaces left on the 
//          board, returns 1.
//***********************************************************
int GameState::addMove(Move move) {

    //check if spot is taken, or move is out of range
    if (move.x < 0 || move.x > 2)
        return 1;
    if (move.y < 0 || move.y > 2)
        return  1;
    if (boardState[move.x][move.y] != '_')
        return -1;

    //if move not invalid, add to move stack
    moveStack.push(move);
    sizeOfStack++;

    //mark with 'x' or 'o' depending on player
    int player = getCurrentPlayer();
    if (player == 0)
        boardState[move.x][move.y] = 'o';
    if (player == 1)
        boardState[move.x][move.y] = 'x';
    if (moveStack.getSize() < 9)
        return 1;   //if board is not empty
    else
        return 0;   //if board is full

}

//***********************************************************
// undoLast: Returns the board state to its previous state
//           and removes the last move from the stack.
// returns: 1 if the move was removed, 0 if the board was is empty.
//***********************************************************
bool GameState::undoLast() {
    //check if there are no moves to undo
    if (moveStack.getSize() == 0) {
        return false;
    }
    else {  //replace last move with '_' and remove it from move stack
        Move lastMove = moveStack.top();
        boardState[lastMove.x][lastMove.y] = '_';
        moveStack.pop();
        sizeOfStack++;
        return 1;
    }
}

//***********************************************************
// displayBoardState: Prints the current state of the board.
//
// std::ostream&out: Parameter that allows output with 'out'.
//***********************************************************
void GameState::displayBoardState(std::ostream& out) {
    //displays board, one row at a time
    for (int i = 0; i < 3; i++) {
        out << boardState[i][0] << boardState[i][1] <<
            boardState[i][2] << endl;
    }
}


