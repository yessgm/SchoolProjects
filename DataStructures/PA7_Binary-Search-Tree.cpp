//
// Author : Yessica Gaona Morales
//
// Due Date : April 30, 2021
// Optional Program .
//
// Spring 2021 - CS 3358 - 252
//
// Instructor: Husain Gholoom.
//
// This program modifies the BST program that appears in the class notes. The
// program creates a BST implemented with an array and in addition
// to the program in the notes, this one has then has:
// 1. a fn that traverses and displays the BST in pre-order format
// 2. a fn that traverses and displays the BST in post-order format
// 3. a fn that counts and displays the number of leafs in the tree
// 4. a fn that displays only the leafs in the tree
// 5. a fn that searches for a specific element and displays its location
// 6. a fn that deletes an element of the tree
// 7. a fn that displays the final tree in pre-order format

#include<iostream>
using namespace std;

class BinarySearchTree {
public:
  int size;
  int* array;
  void insertElement(int x);
  void searchElement(int x);
  void preOrder(int x);
  void postOrder(int x);
  void treeLeafsCount();
  void displayLeafValues();
  void deleteElement(int x);
  void displayTree(int x);
  int extendSize(int x);
  BinarySearchTree(int x) { // constructor
    size = x; // declare the size of the array
    int newSize = extendSize(size);
    array = new int[newSize];
    for (int x = 0; x < size; x++) {
      array[x] = NULL; // creates 'size' empty nodes
    }
  }
};

// extendSize(): this function appears in the program given in the notes. It
//    extends the size of the BTS, and is used int the constructor.
// x: the size by which we wish to extend the array.
// returns size of to be extended.
int BinarySearchTree::extendSize(int x) {
    int value = 0;
    for (int y = 0; y < x + 1; y++) {
        value = (2 * value) + 2;
    }
    return value;
}

// insertElement(): inserts a given element 'x' into the BST and assigns it to
//    a position based on its magnitude compared to the other nodes in the tree.
void BinarySearchTree::insertElement(int x) {
  int currentIndex = 0;  // start at the begining
  cout << "Adding: " << x;
  while (true) {    // if tree is empty
    if (array[currentIndex] == NULL) {
      array[currentIndex] = x;
      cout << " Inserted at index: " << currentIndex << endl;
      break;
    } else if (array[currentIndex] <= x) {
      if (array[currentIndex] == x) {
        cout << "ERROR!-- Repeating element" << endl;
        break;
      } else
        cout << " Right -";
      currentIndex = (2 * currentIndex + 2);
    } else {
      cout << " Left -";
    currentIndex = (2 * currentIndex + 1);
    }
  }
}

// searchElement(): Searches for an element in the tree.
// x: target element
void BinarySearchTree::searchElement(int x) {
    int currentIndex = 0;
    while (true) {
        if (array[currentIndex] == NULL) {
            cout << x <<" is not Found" << endl;
            break;
        }
        if (array[currentIndex] == x) {
            cout << x << " is found at index " << currentIndex << endl;
            break;
        } else if (array[currentIndex] < x) {
            currentIndex = (2 * currentIndex + 2);
        } else if (array[currentIndex] > x) {
            currentIndex = (2 * currentIndex + 1);
        }
    }
}

// preOrder(): Traverses and displays the BST in pre-order form.
// x: the root index of the tree.
void BinarySearchTree::preOrder(int x){
  if (array[x] != NULL){
    cout << array[x] << endl;
    preOrder(2 * x + 1);
    preOrder(2 * x + 2);
  }
}

// postOrder(): Traverses and displays the BST in post-order form.
// x: the root index of the tree.
void BinarySearchTree::postOrder(int x){
  if (array[x] != NULL){
    postOrder(2 * x + 1);
    postOrder(2 * x + 2);
    cout << array[x] << endl;
  }

}

// treeLeafsCount(): Counts the number of leafs in the tree.
void BinarySearchTree::treeLeafsCount(){
  bool isParent; // if node is a parent = true, else = false
  int counter = 0; // keeps track of index

  for (int i = 0; i<size ; i++){
    isParent = false;
    if(array[i] != NULL){
      if (array[2 * i + 2] != NULL){ isParent = true; }
      if (array[2 * i + 1] != NULL){ isParent = true; }
      if (isParent == false){ // if not parent, it is a leaf
        counter++;
      }
    }
  }
  cout << counter;
}

// displayLeafValues(): Displays only the leafs of the tree.
void BinarySearchTree::displayLeafValues(){
  bool isParent; // if node is a parent = true, else = false

  for (int i = 0; i<size ; i++){
    isParent = false;
    if(array[i] != NULL){
      if (array[2 * i + 2] != NULL){ isParent = true; }
      if (array[2 * i + 1] != NULL){ isParent = true; }
      if (isParent == false){
        cout << array[i] << endl;
      }
    }
  }
}

// deleteElement(): Deletes an element from the tree.
// x: element to be deleted.
void BinarySearchTree::deleteElement(int x){
  int position;
  int currentIndex = 0;
  while (true){
    if (array[currentIndex] == NULL){
      if (x!=0)
      cout << x << " is not found\n";
      return;

    }
    if(array[currentIndex]== x){
      cout << x << " is deleted\n";
      position = currentIndex;
      break;
    }
    else if (array[currentIndex] < x){ currentIndex = 2 * currentIndex + 2; }
    else if (array[currentIndex] > x){ currentIndex = 2 * currentIndex + 1; }
  }

  if(2 * position + 2 != NULL){
    array[position] = array[2 * position + 2];
    deleteElement(array[2 * position + 2]);
  }
  if(2 * position + 1 != NULL){
    array[position] = array[2 * position + 1];
    deleteElement(array[2 * position + 1]);
  }
  if((2 * position + 2 == NULL) && (2 * position + 1 != NULL)){
    array[position] = NULL;
  }
}

// displayTree(): Displays BST as shown in the notes. (pre-order as imstructed)
// x: root of the BST.
void BinarySearchTree::displayTree(int x){
  if (array[x] != NULL){
    cout << array[x] << " at index: " << x << endl;
    displayTree(2 * x + 1);
    displayTree(2 * x + 2);
  }
}

int main(){

    BinarySearchTree tree(20);
    //tree.size = 20;
    cout << "Binary Search Tree by Yessica Gaona Morales.\n\n";
    cout << "Inserting Nodes.\n\n";
    tree.insertElement(4);
    tree.insertElement(6);
    tree.insertElement(9);
    tree.insertElement(3);
    tree.insertElement(2);
    tree.insertElement(8);

    cout << "\nBuilding BST is completed.\n\n";
    // Pre-Order Traversal .
    cout << "Pre-Order Traversal of the BST :\n";
    tree.preOrder(0);

    // Post-Order Traversal .
    cout << "\nPost-Order Traversal of the BST :\n";
    tree.postOrder(0);

    // Counting Number of Leafs .
    cout << "\n\nNumber of Leafs = ";
    tree.treeLeafsCount();

    // Display leaf values of BST
    cout << "\n\nHere are the leaf values in the BST:\n\n";
    tree.displayLeafValues();

    // Searching for an element in BST
    cout << "\n\nSearching for 9 in the BST:\n\n";
    tree.searchElement(9);

    // Searching for an element in BST
    cout << "\n\nSearching for 5 in the BST:\n\n";
    tree.searchElement(5);

    // Deleting an element
    cout << "\n\nDeleting 7 from the BST:\n\n";
    tree.deleteElement(7);

    // Deleting an element
    cout << "\n\nDeleting 2 from the BST:\n\n";
    tree.deleteElement(2);

    // Display final tree
    cout << "\n\nDisplaying final BST:\n\n";
    tree.displayTree(0);

    cout << "\n\n\nYessica Gaona Morales - April 30 , 2021\n\n";
}
