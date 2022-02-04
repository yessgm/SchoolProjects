//	Author:	Yessica Gaona Morales
//	Due Date:  2/3/2021
//	Programming Assignment	Number: 1
//	Spring 2021 - CS3358 -	252
//
//	Instructor: Husain Gholoom.
//
// 	The	program	uses a 7 by	5 array	to store a set of random numbers.
//  The	numbers	are	between	1 and 100. The program	then displays on the screen
//  the	numbers, sum, average, smallest, largest, even,	odd, and prime
//  numbers. Finally, the program will display the array with the numbers are
//  sorted from lowest	to highest.

#include <iostream>
#include <stdlib.h>

using namespace std;

void populateArr(int arr[7][5]);
void displayArr(int arr[7][5]);
void findPrimes(int arr[7][5]);
void sortArr(int arr[7][5]);
int getNextSmallest(int arr[7][5], int target);
int timesRepeated(int arr[7][5], int target);


//**************************************************************************
//  main: Defines the array and passes it as a parameter to the other
//      functions.
//**************************************************************************
int main()
{
    cout << "This program is written by Yessica Gaona Morales.\n";
    cout << "The program uses a 7x5 array to store a set of random numbers\n";
    cout << "between 1 and 100. The program displays the numbers, sum,\n";
    cout << "average, smallest, largest, even, odd, and prime numbers.\n";
    cout << "Finally, the numbers are then displayed in ascending order.\n\n";
    cout << "The size of the array is = 35\n\n";

    int arr[7][5];
    populateArr(arr);
    displayArr(arr);
    findPrimes(arr);
    sortArr(arr);

}

//**************************************************************************
//  populateArr: Uses a random number generator to populate the array.
//  arr: address to the first element of the array.
//**************************************************************************
void populateArr(int arr[7][5])
{
    for (int i=0; i<7; i++){
        for(int j=0; j<5; j++)
            arr[i][j] = (rand() % 100 + 1);
    }
}

//**************************************************************************
//  displayArr: Displays the array, finds and displays the sum, mean,
//      smallest number, largest number of its elements and finds all of the
//      odd numbers using loops.
//  arr: address to the first element of the array.
//**************************************************************************
void displayArr(int arr[7][5])
{
    //Display array
    cout << "The 7x5 array is:\n\n";
    for (int i=0; i<7; i++){
        for (int j=0; j<5; j++)
            cout << arr[j][i] << "\t";
        cout << endl;
    }
    cout << endl;

    int sum = 0;
    float avg;
    int smallest = arr[0][0];
    int largest = arr[0][0];
    int odd;

    //find sum and use it to find avg
    for (int i=0; i<7; i++){
        for (int j=0; j<5; j++)
            sum += arr[i][j];
    }
    cout << "The Sum is: " << sum << endl << endl;

    avg = (static_cast<float>(sum))/35;

    cout << "The Average is: " << avg << endl << endl;

    //find smallest number
    for (int i=0; i<7; i++){
        for (int j=0; j<5; j++){
            if (arr[i][j] < smallest)
                smallest = arr[i][j];
        }
    }
    cout << "The Smallest is: " << smallest << endl << endl;

    //find largest number
    for (int i=0; i<7; i++){
        for (int j=0; j<5; j++){
            if (arr[i][j] > largest)
                largest = arr[i][j];
        }
    }
    cout << "The Largest is: " << largest << endl << endl;

    //find and display all even numbers
    cout << "Even Numbers are: ";
    for (int i=0; i<7; i++){
        for (int j=0; j<5; j++){
            if (arr[i][j] % 2 == 0)
                cout << arr[i][j] << " ";
        }
    }
    cout << endl << endl;

    //find and display all odd numbers
    cout << "Odd Numbers are: ";
    for (int i=0; i<7; i++){
        for (int j=0; j<5; j++){
            if (arr[i][j] % 2 == 1)
                cout << arr[i][j] << " ";
        }
    }
    cout << endl << endl;
}

//**************************************************************************
//  findPrimes: Finds and displays the prime numbers in the array.
//  arr: address to the first element of the array.
//**************************************************************************
void findPrimes(int arr[7][5]){

    cout << "All prime numbers are: ";
    bool isPrime = true;
    for (int i=0; i<7; i++){
        for (int j=0; j<5; j++){
            if ((arr[i][j]== 0) || (arr[i][j]==1))
                isPrime = false;
            else{
                //number is not divisible by a number that is greater than
                //half of it, thus we will compare only numbers less than half
                for (int k=2; k<(arr[i][j]/2); k++){
                    if ((arr[i][j] % k) == 0)
                        isPrime = false;
                }
            }
            if (isPrime == true)
                cout << arr[i][j] << " ";
            isPrime = true;
        }
    }
    cout << endl << endl;
}

//**************************************************************************
//  sortArr: Sorts array in ascending order.
//  arr: address to the first element of the array.
//**************************************************************************
void sortArr(int arr[7][5]){

    int sortedArr[7][5];
    int smallest = 0;
    int repeats;


    //code to find the next smallest element and add it to new array
    for (int i=0; i<7; i++){
        for (int j=0; j<5; j++){
            sortedArr[i][j]= getNextSmallest(arr, smallest);
            smallest = getNextSmallest(arr, smallest);
//            if(timesRepeated(arr, smallest)> 1){
//                repeats = timesRepeated(arr, smallest);
//                for (k=0; k<repeats; k++){
//                    smallest = getNextSmallest(arr, smallest);
//                }
            }
    }

    //Display sorted array
    cout << "The Array after sort is:\n\n";
    for (int i=0; i<7; i++){
        for (int j=0; j<5; j++)
            cout << sortedArr[i][j] << "\t";
        cout << endl;
    }
    cout << endl;



}

int getNextSmallest(int arr[7][5], int target){

    int nextSmallest = 100;
    //code to find the next smallest element
    for (int i=0; i<7; i++){
        for (int j=0; j<5; j++){
            if ((arr[i][j] > target) && (arr[i][j]< nextSmallest))
                nextSmallest = arr[i][j];

        }
    }
    return nextSmallest;
}

int timesRepeated(int arr[7][5], int target){
    int numOfTimesInArr = 0;
    for (int i=0; i<7; i++){
        for (int j=0; j<5; j++){
            if (arr[i][j] == target)
                numOfTimesInArr++;
        }
    }
    return numOfTimesInArr;
}
