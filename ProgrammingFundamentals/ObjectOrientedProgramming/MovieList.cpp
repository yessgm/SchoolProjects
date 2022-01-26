
// File Name: MovieList.cpp
//
// Author: Yessica Gaona Morales
// Collaborators: none
// Date: 11/4/2020
// Assignment Number: 5
// CS 2308 Fall 2020
//
// This program includes the implementation of MovieList member functions

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "MovieList.h"
using namespace std;

//***********************************************************
// MovieList: Creates an empty list.
//***********************************************************
MovieList::MovieList() {
	 top = NULL;
}

//***********************************************************
// ~MovieList: Deallocates all nodes in the list.
//***********************************************************
MovieList::~MovieList() {
	while (top != NULL) {
		MovieNode* p = top;
		top = top->next;
		delete p;
	}
}

//***********************************************************
// display: Prints movie titles from top to bottom with their
//			positions numbered.
// out: Parameter that allows output with 'out'.
//***********************************************************
void MovieList::display(ostream& out){
	int count = 0;	//to track index
	MovieNode* p = top;
	while (p != NULL) {	//traverse list
		out << count << ": " << p->title << endl;
		p = p->next;
		count++;
	}
}

//***********************************************************
// addToTop: Adds movie to the top of the list.
// title: The name of the movie.
//***********************************************************
void MovieList::addToTop(string title) {
	MovieNode* newNode = new MovieNode(title, NULL);
	newNode->title = title;
	newNode->next = top;
	top = newNode;
}

//***********************************************************
// addToBottom: Adds movie to the bottom of the list.
// title: The name of the movie.
//***********************************************************
void MovieList::addToBottom(string title) {
	MovieNode* newNode = new MovieNode(title, NULL);
	newNode->title = title;
	newNode->next = nullptr;

	if (top == NULL) //if the list is empty
		top = newNode;	//add to beginning
	else{
		MovieNode* p = top;
		while (p->next != NULL) {	//find the last node
			p = p->next;
		}
		p->next = newNode;	//make p's node point to newNode
	}
}

//***********************************************************
// remove: Removes a movie from the list.
// title: The name of the movie to be removed.
// returns: If movie was found and removed, 1, 0 if not found.
//***********************************************************
bool MovieList::remove(string title) {
	MovieNode* p = top;      // to traverse the list
	MovieNode* n = nullptr;   // trailing node pointer

	// skip nodes not equal to title, stop at last
	while (p && p->title != title) {
		n = p;        
		p = p->next;
	}

	if (p) {
		if (n == nullptr) {   // p points to the first elem
			top = p->next;
			delete p;
			return 1;
		}
		else {            // n points to the predecessor
			n->next = p->next;
			delete p;
			return 1;
		}
	}
	return 0;
}

//***********************************************************
// moveToPosition: Moves movie with given title to position n.
// title: The name of the movie.
// position: Index of the position to be moved to.
// returns: If movie was found and moved, 1, if not found, 0.
//***********************************************************
bool MovieList::moveToPosition(string title, int position) {
	MovieNode* newNode = new MovieNode(title, NULL);
	newNode->title = title;
	int count = 0;	//for tracking position

	MovieNode* p = top;      // to traverse the list
	MovieNode* n = nullptr;   // trailing node pointer

	//advance pointers through list to insertion point
	//while we don't reach the end of the list and we are
	//pointing to the position that we want
	while (p && count < position+1) {
		n = p;
		p = p->next;
		count++;
	}
	remove(title);

	//change pointers to include new node
	if (n == nullptr) {	
		top = newNode;
		newNode->next = p;
		return 0;
	}
	else {
		n->next = newNode;
		newNode->next = p;
		return 1;
	}
	return 0;
}

//***********************************************************
// moveToTop: Moves movie with given title to top of list.
// title: Name of the movie.
// returns: If movie was found and moved, 1, 0 if not found.
//***********************************************************
bool MovieList::moveToTop(string title) {
	if (remove(title) == 1) {
		addToTop(title);
		return 1;
	}
	else
		return 0;
}

//***********************************************************
// nextLarger: Finds movie that comes next given title in
//				alphabetical order.
// title: Name of the movie.
// returns: The name of the movie that comes next.
//***********************************************************
string MovieList::nextLarger(string title) {
	MovieNode *p = top;
	string nextLarger = "zz";
	string larger = "";

	//check if movie is in the list 
	while (p != NULL && p->title != title) {	
		p = p->next;
	}
	if (!p)
		return "";	// movie not found

	p = top;
	while (p != NULL) {		//traverse list
		if (p->title > title) {		//if movie larger than title
			larger = p->title;
			if (larger < nextLarger) //movie is < current larger
				nextLarger = larger;
		}
		p = p->next;
	}
	if (nextLarger == "zz")		//if no larger movie found
		return "";

	return nextLarger;
}

//***********************************************************
// displaySorted: Uses nextLarger to output the titles in
//				alphabetical order with numbered positions.
// out: Parameter that allows output with 'out'.
//***********************************************************
void MovieList::displaySorted(ostream& out) {
	MovieNode* p = top;
	string min = "zz";
	int count = 0;	//to track how many movies are greater

	while (p != NULL){	//find min movie
		if (p->title < min) 
			min = p->title;
		p = p->next;
		count++;
	}

	out << "0: " << min << endl;	//output min 
	for (int i = 1; i < count; i++) {	//find next larger 
		out << i << ": " << nextLarger(min) << endl;
		min = nextLarger(min);
	}
}



