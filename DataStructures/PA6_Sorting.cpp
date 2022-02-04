// Author : Yessica Gaona Moraales
//
// Due Date : April 21, 2021
// Programming Assignment Number 6
//
// Spring 2021 - CS 3358 - 252
//
// Instructor: Husain Gholoom.
//
// This program accepts an array size of n > 4 from the user, uses generates an
// array of random characters, then main calls on other functions that use a
// different sorting algorithm to sort the array, and display it. Also uses
// a sequential search algorithm to find a char on a (un)/sorted array.

#include <iostream>
#include <time.h>
using namespace std;

void display(char* array, int size);
int sequentialSearch(char* array, int size, char target);
int selectionSort(char array[], int size);
int insertionSort(char array[], int size);
int quickSortMiddle(char array[], int left, int right, int counter);
int quickSortNextLast(char array[], int left, int right, int counter);
int quickSortFirst(char array[], int left, int right, int counter);

// main: driver for sort/search functions
int main()
{
    cout << "Searching / Sorting Benchmark\n\n\n";
    cout << "Enter the size of the array: ";

    int input;  // holds user input for array size
    try {
      cin >> input;
      cout << endl;
      throw input; // catch if input is not > 4, or wrong type
    } catch (int e){
      if(e < 5){
        cout << "\n*** Error -Invalid input - Size must be > 4 ***\n\n\n"
        << "4 - 2021\nSorting / Searching Benchmark by :\nYessica Gaona\n";
        return 0;
      }
    } catch (char e){
      cout << "\n*** Error -Invalid input - Size must be > 4 ***\n\n\n"
      << "4 - 2021\nSorting / Searching Benchmark by :\nYessica Gaona\n";
      return 0;
    }

    srand(time(NULL));  // seed for random number generator

    const int SIZE = input;
    char charArray[SIZE];
    char copy1[SIZE];
    char copy2[SIZE];
    char copy3[SIZE];
    char copy4[SIZE];
    for (int i=0; i< SIZE; i++){
      int randNum = rand();
      charArray[i] = (randNum % 60) + 65;  // char will be between [A, }]
      copy1[i] = charArray[i];
      copy2[i] = charArray[i];
      copy3[i] = charArray[i];
      copy4[i] = charArray[i];
    }
    cout << "Array elements are : ";
    display(charArray, input);

    cout << "\n\n\nSequential Search\n\n";
    double startTime = clock();
    int count = sequentialSearch(charArray, input, 80);
    double endTime = clock();
    if (count == 0){ cout << "\nChar " << 80 << " Was Not found."; }
    else { cout << "\nChar " << 80 << " Was found."; }
    cout << "\nStart Time :\t" << startTime;
    cout << "\nEnd Time :\t" << endTime;
    cout << "\nActual CPU Clock time :\t" << (endTime - startTime)/1000 << "s";
    cout << "\nTotal Number of char 80 :\t" << count;
    cout << "\nArray Elements : " ;
    display(charArray, input);

    cout << "\n\n\nSelection Sort :\n";
    startTime = clock();
    count = selectionSort(charArray, input);
    endTime = clock();
    cout << "\nStart Time :\t" << startTime;
    cout << "\nEnd Time :\t" << endTime;
    cout << "\nActual CPU Clock time :\t" << (endTime-startTime)/1000 << "s";
    cout << "\nTotal Number of Swaps :\t" << count;
    cout << "\nSorted Elements : " ;
    display(charArray, input);

    cout << "\n\n\nInsertion Sort :\n";
    startTime = clock();
    count = insertionSort(copy1, input);
    endTime = clock();
    cout << "\nStart Time :\t" << startTime;
    cout << "\nEnd Time :\t" << endTime;
    cout << "\nActual CPU Clock time :\t" << (endTime-startTime)/1000 << "s";
    cout << "\nTotal Number of Comparisons :\t" << count;
    cout << "\nSorted Elements : " ;
    display(copy1, input);

    cout << "\n\n\nQuick Sort - The middle element as a pivot :\n";
    startTime = clock();
    count = quickSortMiddle(copy2, 0, input-1, 1);
    endTime = clock();
    cout << "\nStart Time :\t" << startTime;
    cout << "\nEnd Time :\t" << endTime;
    cout << "\nActual CPU Clock time :\t" << (endTime-startTime)/1000 << "s";
    cout << "\nNumber of Recursive calls :\t" << count;
    cout << "\nSorted Elements : " ;
    display(copy2, input);

    cout << "\n\n\nQuick Sort - The next to last element as a pivot :\n";
    startTime = clock();
    count = quickSortNextLast(copy3, 0, input-1, 1);
    endTime = clock();
    cout << "\nStart Time :\t" << startTime;
    cout << "\nEnd Time :\t" << endTime;
    cout << "\nActual CPU Clock time :\t" << (endTime-startTime)/1000 << "s";
    cout << "\nTotal Number of Recursive calls :\t" << count;
    cout << "\nSorted Elements : " ;
    display(copy3, input);

    cout << "\n\n\nQuick Sort - First element as a pivot :\n";
    startTime = clock();
    count = quickSortFirst(copy4, 0, input-1, 1);
    endTime = clock();
    cout << "\nStart Time :\t" << startTime;
    cout << "\nEnd Time :\t" << endTime;
    cout << "\nActual CPU Clock time :\t" << (endTime-startTime)/1000 << "s";
    cout << "\nTotal Number of Recursive calls :\t" << count;
    cout << "\nSorted Elements : " ;
    display(copy4, input);

    cout << "\n\n\nSequential Search for Char 80 After Sort\n\n";
    startTime = clock();
    count = sequentialSearch(charArray, input, 80);
    endTime = clock();
    if (count == 0){ cout << "\nChar " << 80 << " Was Not found."; }
    else { cout << "\nChar " << 80 << " Was found."; }
    cout << "\nStart Time :\t" << startTime;
    cout << "\nEnd Time :\t" << endTime;
    cout << "\nActual CPU Clock time :\t" << (endTime-startTime)/1000 << "s";
    cout << "\nTotal Number of char 80 :\t" << count;
    cout << "\nArray Elements : " ;
    display(charArray, input);

    cout << "\n\n4 - 2021\nSorting / Searching Benchmark by :\nYessica Gaona\n";

}

// display: prints the first 20 elements of the given array
// *array: pointer to the first element of the array
// size: size of the passed array
void display(char* array, int size){
  if (size > 20){
    for (int i=0; i<20; i++){ cout << *(array + i) << " "; }
  }
  else{
    for (int i=0; i<size; i++){ cout << *(array + i) << " "; }
  }
}

// sequentialSearch: linear search algorithm for finding a char in an array
// *array: pointer to the first element of the array
// target: target character
// returns - counter: number of times the target appears in the array
int sequentialSearch(char* array, int size, char target){
  cout << "Searching for Char 80" << endl;
  int counter = 0;
  for (int i=0; i<size; i++){
    if (*(array+i) == target) { counter++; }
  }
  return counter;
}

// selectionSort: selection sort algorithm to sort give array
// array: array to be sorted
// size: size of the array
// returns- swaps: number of swaps made by the function
int selectionSort(char array[], int size){
  int swaps = 0;
  for (int i = 0; i < size - 1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[min]) { min = j; }
    }
    if (i != min) {
      swap(array[i], array[min]);
      swaps++;
    }
  }
  return swaps;
}

// insertionSort: uses insertion sorting algorithm on given array
// array: array to be sorted
// size: size of the array
// returns - comparisons: number of comparisons made by the algorithm
int insertionSort(char array[], int size){
  int value, j = 0, comparisons= 0;
  for (int i = 1; i < size; i++){
    value = array[i];
    j = i - 1;
    while (j >= 0 && array[j] > value){
      array[j + 1] = array[j];
      j--;
      comparisons++;
    }
    array[j + 1] = value;
  }
  return comparisons;
}

// quickSortMiddle: uses quick sort algorithm with middle as the pivot on array
// array: array to be sorted
// left: index to first element in an array
// right: index to last element
// returns - counter: number of recursive calls by the functions
int quickSortMiddle(char array[], int left, int right, int counter){
  int i = left, j = right;
  int pivot = array[(left + right)/2];
  while(i <= j){
    while (array[i] < pivot){ i++; }
    while (array[j] > pivot){ j--; }
    if (i <=j){
      swap(array[i], array[j]);
      i++;
      j--;
    }
    if (left < j){ quickSortMiddle(array, left, j, counter++); }
    if (i < right){ quickSortMiddle(array, i, right, counter++); }
  }
  return counter;
}

// quickSortNextLast: quick sort algorithm with next to last char as the pivot
// array: array to be sorted
// left: index to first element in an array
// right: index to last element
// returns - counter: number of recursive calls by the functions
int quickSortNextLast(char array[], int left, int right, int counter){
  int i = left, j = right, recursions = 0;
  int pivot = array[right - 1];
  while(i <= j){
    while (array[i] < pivot){ i++; }
    while (array[j] > pivot){ j--; }
    if (i <=j){
      swap(array[i], array[j]);
      i++;
      j--;
    }
    if (left < j){
      quickSortNextLast(array, left, j, counter++);
    }
    if (i < right){
      quickSortNextLast(array, i, right, counter++);
    }
  }
  return counter;
}

// quickSortFirst: uses quick sort algorithm with first char as the pivot
// array: array to be sorted
// left: index to first element in an array
// right: index to last element
// returns - counter: number of recursive calls by the functions
int quickSortFirst(char array[], int left, int right, int counter){
  int i = left, j = right, recursions = 0;
  int pivot = array[left];
  while(i <= j){
    while (array[i] < pivot){ i++; }
    while (array[j] > pivot){ j--; }
    if (i <=j){
      swap(array[i], array[j]);
      i++;
      j--;
    }
    if (left < j){
      quickSortNextLast(array, left, j, counter++);
    }
    if (i < right){
      quickSortNextLast(array, i, right, counter++);
    }
  }
  return counter;
}
