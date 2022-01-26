// File Name: MovieNode.h
//
// Author: Vladyslav Prokopenko
// Date: 10/26/2020
// Assignment Number: 5
// CS 2308/CS 5301 Fall 2020
// Instructor: Jill Seaman
#include <string>

struct MovieNode{
    MovieNode(std::string title, MovieNode* next = nullptr) : title{title}, next{next}{}
    std::string title;
    MovieNode* next;
};
