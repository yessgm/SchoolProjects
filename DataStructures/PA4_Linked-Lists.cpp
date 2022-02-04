// Author : Yessica Gaona Morales
//
// Programming Assignment Number 4
//
// Spring 2021 - CS 3358 - 252
//
// Due Date : March 31, 2021
//
// Instructor: Husain Gholoom.
//
// This program uses a linked-list implemented by a class to
// a. build 2 lists of 15 randomly generated characters (list 1 & 2).
// b. combine both lists into (list 3), with alternating chars from each.
// c. display the first element of the third list, and calculate its number of
//    occurences in the list.
// d. create (list 4) by removing all of the duplicate chars in the third
// e. move last element in list 4 to the beggining of the list.
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct ListNode {   // the node data type
  char value;       // data
  ListNode* next;   // pointer to the next node
};

class LinkedList{
public:
  LinkedList();
  ~LinkedList();
  void display();
  void addToTop(char letter);
  void addToBottom(char letter);
  bool remove(char letter);
  int getSize();
  char returnChar(int position);
  int countOccurences(char letter);
  char generateRandomChar();
  void removeRepeats();
private:
  ListNode* top;
};

//***********************************************************
// LinkedList: Creates an empty list.
//***********************************************************
LinkedList::LinkedList() {
	 top = NULL;
}

//***********************************************************
// ~LinkedList: Deallocates all nodes in the list.
//***********************************************************
LinkedList::~LinkedList() {
	while (top) {
		ListNode* q = top;
		top = top->next;
		delete q;
	}
}

//***********************************************************
// display: Prints the characters in the list top->bottom.
//***********************************************************
void LinkedList::display(){
  int counter = 0; //used to count number of nodes
  ListNode* q = top; //pointer of node-type used to traverse list
  while(q){
    cout << q->value << "  ";
    q = q->next;
    counter++;
    if(counter == 15){ // after 15 nodes, skip line
      cout << endl;
    }
  }
}

//***********************************************************
// addToTop: Adds node to the top of the list.
// letter: The letter to be added.
//***********************************************************
void LinkedList::addToTop(char letter){
  ListNode* newNode = new ListNode;
    newNode->value = letter;
    newNode->next = top;
    top = newNode;
}

//***********************************************************
// addToBottom: Adds node to the bottom of the list.
// letter: The letter to be added.
//***********************************************************
void LinkedList::addToBottom(char letter){
  ListNode* newNode = new ListNode;
  newNode->value = letter;
  newNode->next = NULL;

  if (top == NULL) //if the list is empty add to top
    top = newNode;
  else{
    ListNode* q = top;
    while(q->next){ //find the last node
      q = q->next;
    }
    q->next = newNode; //make p's node point to newNode
  }
}

//***********************************************************
// remove: Removes first occurence of char in  the list.
// letter: The letter to be removed.
// returns- If letter was found and removed
//***********************************************************
bool LinkedList::remove(char letter){
  ListNode* p = top;  //to traverse list
  ListNode* n = NULL; //trailing node pointer

  // skip nodes not equal to title, stop at last
  while (p && p->value != letter) {
		n = p;
		p = p->next;
	}

  if (p) {
    if (n == NULL) {  // p points to the first elem
      top = p->next;
      delete p;
      return true;
    }
    else {  // n points to the previous node
      n->next = p->next; //skip p
      delete p;
      return true;
    }
  }
  return false;
}

//***********************************************************
// getSize: Counts number of nodes in the list and returns its size.
//***********************************************************
int LinkedList::getSize(){
  int counter;
  ListNode* q = top;
  while(q){
    q = q->next;
    counter++;
  }
  return counter;
}

//***********************************************************
// returnChar: Returns character at given position.
// letter: The letter we are looking for.
//***********************************************************
char LinkedList::returnChar(int index){
  int position = 0; //keeps track of position
  ListNode* q = top; //node pointer to traverse the list
  while(position < index){
    q = q->next; //traverse list until desired position is reached
    position++;
  }
  return q->value;
}

//***********************************************************
// countOccurences: Counts number of times a given character appears
//                  in the list.
// letter: The letter to be tracked.
// returns- number of times letter occurs in the list.
//***********************************************************
int LinkedList::countOccurences(char letter){
  int counter = 0; //counts number of times char appears
  ListNode* q = top; //pointer of node-type used to traverse list
  while(q){
    if(q->value == letter)
      counter++;
    q = q->next;
  }
  return counter;
}

//***********************************************************
// generateRandomChar: generates a random number in the
//    ASCII range 66-89 ('B'-'Y') and converts it to a char.
// returns- character
//***********************************************************
char LinkedList::generateRandomChar(){
  int num = rand(); //generates pseudorandom integer (given seed in main)
  char character = (num % 24) + 66; //narrows integer to proper range
  return character;
}

//***********************************************************
// removeRepeats: identifies repeated nodes and removes them.
//***********************************************************
void LinkedList::removeRepeats(){
  ListNode* q = top; //pointer to node used to traverse list
  while(q){ //removes repeats, leaves last time char appears
    if(countOccurences(q->value) > 1){
      for(int j=0; j<(countOccurences(q->value)-1); j++)
        remove(q->value);
    }
    q = q->next;
  }
}

//***********************************************************
// main: Creates multiple objects of linked-lists and calls other
//    functions to perform operations on said lists.
//***********************************************************
int main(){

  srand(time(NULL)); //seed to generate random numbers

  LinkedList list1; //create 2 empty lists
  LinkedList list2;

  //populate both lists with randomly renerated characters:
  for(int i=0; i<15; i++){
    list1.addToTop(list1.generateRandomChar());
    list2.addToTop(list2.generateRandomChar());
  }

  // display list 1 and 2
  cout << "Pointer Implementation of Linked List\n\n";
  cout << "List 1:\n";
  list1.display();
  cout << "\n\nList 2:\n";
  list2.display();

  //combine 2 lists into list 3 by alternating values:
  LinkedList list3;
  for(int i=0; i<15; i++){
    list3.addToBottom(list1.returnChar(i));
    list3.addToBottom(list2.returnChar(i));
  }

  //display list 3
  cout << "\n\nList 3:\n";
  list3.display();

  //display first element of the 3rd list and number of occurences
  char firstChar = list3.returnChar(0); //holds the first char in list 3
  cout << "\n\nFirst element in List 3: " << firstChar << "\n";
  cout << "\nNumber of occurences of '"<< firstChar<< "' in List 3: ";
  cout << list3.countOccurences(firstChar);

  //create a new list (list4) that excludes repeating nodes in list 3:
  //copy list 3 into list 4 and remove repeated nodes
  LinkedList list4;
  for(int i=0; i<30; i++){
    list4.addToBottom(list3.returnChar(i));
  }
  list4.removeRepeats();

  //display list 4
  cout << "\n\nList 4:\n";
  list4.display();
  cout << "\n\nNumber of elements in List 4: " << list4.getSize() << endl;

  //move last node in list 4 to the front:
  char last = list4.returnChar(list4.getSize()-1); //holds char in last node
  list4.remove(last);
  list4.addToTop(last);

  //display new list 4
  cout << "\nNew List 4: \n";
  list4.display();
  cout << "\n\n\nThis LL program is implemented by:\nYessica Gaona Morales -";
  cout << " March 31, 2021\n\n";
}
