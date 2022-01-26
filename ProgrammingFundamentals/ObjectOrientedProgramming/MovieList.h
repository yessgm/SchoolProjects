// File Name: MovieList.h
//
// Author: Vladyslav Prokopenko
// Date: 10/26/2020
// Assignment Number: 5
// CS 2308/CS 5301 Fall 2020
// Instructor: Jill Seaman

#ifndef LAB5_MOVIELIST_H
#define LAB5_MOVIELIST_H

#include <string>
#include <iostream>
#include "MovieNode.h"


class MovieList {
public:
    MovieList();
    ~MovieList();
    void display(std::ostream& out);
    void addToTop(std::string title);
    void addToBottom(std::string title);
    bool remove(std::string title);
    bool moveToPosition(std::string title, int position);
    bool moveToTop(std::string title);
    std::string nextLarger(std::string title)
    ;
    void displaySorted(std::ostream& out);
private:
    MovieNode* top;
};


#endif //LAB5_MOVIELIST_H
