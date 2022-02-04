//
// Author : Yessica Gaona Morales
//
// Due Date : 4/12/2021
//
// Programming Assignment Number 5
//
// Spring 2021 - CS 3358 - 252
//
// Instructor: Husain Gholoom.
//
// This C++ program does the following :
// 1. Accepts array size ( n ) from the keyboard (w/ n>=5).
// 2. Populates the created array with random int values between [100, 5896].
// 3. Displays the generated array.
// 4. Contains a fn that uses recursion to display the array in reverse order
// 5. Contains a fn that uses recursion to display squares of integers in
//    ascending order, starting from 1 to n.
// 6. Contains a recursive fn that takes the first int in the array and
//    returns the sum of the digits of that integer.
// 7. Contains a fn that uses recursion in to determine whether or not the last
//    number in the array is prime.

#include <iostream>
#include <time.h>
using namespace std;

void displayBackwards(int arr[], int i);
void displaySquares(int size, int i);
int sumDigits(int num );
bool isLastPrime(int last, int i);

// main: The driver function that creates the array and calls on the others
//       to perform their given task.
// returns - nothing
int main()
{
  cout << "*** Welcome to My Recursion APP ***\n\n";
  cout << "Enter the array size. ( Must be >= 5 ) - - >  ";

  int input;  // holds user input for array size
  try {
    cin >> input;
    throw input; // catch if input is not >=5, or wrong type
  } catch (int e){
    if(e < 5){ cout << "\n\nInvalid array size. Size must be >= 5."; }
  } catch (...){ cout << "\n\nInvalid array size. Size must be >= 5."; }

  const int SIZE = input; // size of the array
  int array[SIZE]; // integer array of size user input

  srand(time(NULL));  // seed for random number generator
  cout << "\nThe generated array is : ";
  for (int i=0; i<SIZE; i++){
    int randNum = rand();
    array[i] = (randNum % 5797) + 100;  // number will be between [100, 5797]
    cout << array[i] << " ";  // display array elements
  }

  // Recursive function calls:
  cout << "\n\nReversed Array is : ";
  displayBackwards(array, input);

  cout << "\n\nTable of square values from 1 to " << SIZE << " is :\n\n";
  displaySquares(input, 1);

  cout << "\n\nSum of " << *array << " digits is : " << sumDigits(*array);

  cout << "\n\nIs " << array[SIZE - 1] << " a Prime Number : " << array[SIZE - 1];
  if (isLastPrime(array[SIZE -1], 2) == true){ cout << " is a prime number"; }
  else{ cout << " is not a prime number"; }

  cout << "\n\n\nYessica Gaona Morales - Tweak Programming Director\nApril 2021\n\n";
}

// displayBackwards: Displays given array of size n in reverse recursively.
// arr: The given array to be displayed.
//size: The size of the given array.
void displayBackwards(int arr[], int size){
  if (size == 0){ return; }
  cout << arr[size-1] << " ";
  size--;
  displayBackwards(arr, size);
}

// displaySquares: Displays the number and its square of every number starting
//       from 1 to n recursively.
// size: The size of the array (n).
// i: Index of element to be squared, base 1.
void displaySquares(int size, int i){
  if (i ==1){ cout << "N\tN Squared:\n"; }
  if (i == size+1){ return; }
  cout << i << "\t" << i*i << "\n";
  i++;
  displaySquares(size, i);
}

// sumDigits: Sums every digit in the given number recursively.
// num: Given number whose digit sum is to be found.
// returns - The sum of the digits, or 0 if number has no digits.
int sumDigits(int num ){
  if (num == 0){ return 0; }
  return (num % 10 + sumDigits(num / 10));
}

// isLastPrime: Checks if given number is prime recursively by repeated division
//     starting at 2 and incrementing until number is reached, or divisor found.
// last: The last number of the array whose primeness is in question.
// i: Index of the element that is being diveded by.
// returns - True if prime, false if number is not prime.
bool isLastPrime(int last, int i){
  if (last <= 2){
    if (last==2){ return true; }
    else { return false; }
  }
  if (last % i == 0){ return false; }
  if (i * i > last) { return true; }
  return isLastPrime(last, i + 1);
}
