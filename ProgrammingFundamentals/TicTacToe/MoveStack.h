// File Name: MoveStack.h
//
// Author: Yessica Gaona Morales
// Collaborators: Timothy Maraj
// Date: 11/16/2020
// Assignment Number: 6
// CS 2308 Fall 2020
//
// This is a header file for a game of Tic-tac-toe 
// that defines a struct of game moves, and a stack 
// class of game moves. The functions for the 
// MoveStack class are also defined here.

#ifndef LAB6_PART1_STACK_H
#define LAB6_PART1_STACK_H
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

//**********************************************************************
// MoveStack.h
//**********************************************************************
struct Move {
    Move() : x(0), y(0) {}
    Move(int x, int y) : x(x), y(y) {}
    int x;
    int y;
    Move* next;
};

class MoveStack {
private:
    //const static int STACKSIZE = 9;
    //Move stackArray[STACKSIZE];
    Move* topOfStack;    //index to the top of the stack
    int stackSize = 0;

    //***********************************************************
    // isFull: Checks if the stack is full.
    // returns: True if full, false otherwise.
    //***********************************************************
    bool isFull() {
        if (stackSize == 9)
            return true;
        else
            return false;
    }

    //***********************************************************
    // isEmpty: Checks if the stack is empty.
    // returns: True if empty, false otherwise.
    //***********************************************************
    bool isEmpty() {
        if (stackSize == 0)
            return true;
        else
            return false;
    }

public:

    //***********************************************************
    // MoveStack: Creates an empty stack
    //***********************************************************
    MoveStack() { topOfStack = nullptr; }

    //***********************************************************
    // ~MoveStack: Cleans dynamically allocated memory.
    //***********************************************************
    ~MoveStack() {
        while (topOfStack) {
            Move* p = topOfStack;
            topOfStack = topOfStack->next;
            delete p;
        }
    }

    //***********************************************************
    // getSize: Returns the size of the stack.
    //***********************************************************
    int getSize() {
        return stackSize;
    }

    //***********************************************************
    // top: Returns a move of type Move from top of the stack.
    //***********************************************************
    Move top() {
        Move move;
        move.x = topOfStack->x;
        move.y = topOfStack->y;
        return move;
    }

    //***********************************************************
    // push: Adds a move to the top of the stack.
    // move: The move of type Move that needs to be added.
    //***********************************************************
    void push(Move move) {
        assert(!isFull());  //check if stack is full

        stackSize++;
        Move* newMove = new Move;
        newMove->x = move.x;
        newMove->y = move.y;
        newMove->next = topOfStack;
        topOfStack = newMove;
    }

    //***********************************************************
    // pop: Removes a move from the top of the stack.
    //***********************************************************
    void pop() {
        assert(!isEmpty()); //check if stack is empty

        stackSize--;

        Move* p = topOfStack;
        topOfStack = topOfStack->next;
        delete p;
    }
};

#endif //LAB6_PART1_STACK_H

//#ifndef LAB6_PART1_STACK_H
//#define LAB6_PART1_STACK_H
//#include <iostream>
//#include <cassert>
//#include <iomanip>
//using namespace std;
//
//struct Move {
//    Move() : x(0), y(0) {}
//    Move(int x, int y) : x(x), y(y) {}
//    int x;
//    int y;
//};
//
//class MoveStack {
//private:
//    const static int STACKSIZE = 9;
//    Move stackArray[STACKSIZE];
//    int topOfStack;    //index to the top of the stack
//
//    //***********************************************************
//    // isFull: Checks if the stack is full.
//    // returns: True if full, false otherwise.
//    //***********************************************************
//    bool isFull() {
//        if (topOfStack == STACKSIZE - 1)
//            return true;
//        else
//            return false;
//    }
//
//    //***********************************************************
//    // isEmpty: Checks if the stack is empty.
//    // returns: True if empty, false otherwise.
//    //***********************************************************
//    bool isEmpty() {
//        if (topOfStack == -1)
//            return true;
//        else
//            return false;
//    }
//
//public:
//
//    //***********************************************************
//    // MoveStack: Creates an empty stack
//    //***********************************************************
//    MoveStack() { topOfStack = -1; }
//
//    //***********************************************************
//    // ~MoveStack: Cleans dynamically allocated memory.
//    //***********************************************************
//    ~MoveStack() {
//        topOfStack = -1;
//    }
//
//    //***********************************************************
//    // getSize: Returns the size of the stack.
//    //***********************************************************
//    int getSize() {
//        return topOfStack + 1;
//    }
//
//    //***********************************************************
//    // top: Returns a move of type Move from top of the stack.
//    //***********************************************************
//    Move top() {
//        return stackArray[topOfStack];
//    }
//
//    //***********************************************************
//    // push: Adds a move to the top of the stack.
//    // move: The move of type Move that needs to be added.
//    //***********************************************************
//    void push(Move move) {
//        assert(!isFull());  //check if stack is full
//
//        topOfStack++;
//        stackArray[topOfStack].x = move.x;
//        stackArray[topOfStack].y = move.y;
//    }
//
//    //***********************************************************
//    // pop: Removes a move from the top of the stack.
//    //***********************************************************
//    void pop() {
//        assert(!isEmpty()); //check if stack is empty
//
//        Move temp;
//        temp.x = stackArray[topOfStack].x;
//        temp.y = stackArray[topOfStack].y;
//        topOfStack--;
//    }
//};
//
//#endif //LAB6_PART1_STACK_H
