// File Name: assign1.cpp
//
// Author: Yessica Gaona Morales
// Date: 9/9/2020
// Assignment Number: 1
// CS 2308 Fall 2020
//
// Uses loops and several functions to display an array of structs, find the total size, and lowest average size.


#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


struct Folders {	// declaring global struct
	int fileNum;
	string name;
	int numFiles;
	double size;
};
const int ASIZE = 10;	// size of the array

void display(struct myArray[ASIZE]);	//declaring display function with parameters
void editFolders(struct myArray[ASIZE]);
double totalSize(struct myArray[ASIZE]);
int  lowestAvgSize(struct myArray[ASIZE]);

void display(Folders myArray[])	//display function with struct array passed as argument
{
	cout << left
		<< setw(3) << "N"
		<< setw(15) << "Name"
		<< setw(10) << "Num files"
		<< setw(10) << "Size(Mb)"
		<< endl;

	for (int i = 0; i < ASIZE; i++)
	{
		cout << fixed << setprecision(2);
		cout << setw(3) << myArray[i].fileNum << setw(15) << myArray[i].name << setw(10) << myArray[i].numFiles << setw(10) << myArray[i].size << endl;
	}
}

double totalSize(Folders myArray[]) {

	double totalSize = 0;
	for (int i = 0; i < ASIZE; i++) {
		totalSize += myArray[i].size;
	}
	return totalSize;
}

int lowestAvgSize(Folders myArray[]) {

	double avgSize;
	int intFiles = myArray[0].numFiles;
	double numberFiles = static_cast<double>(intFiles);
	double lowestSize = myArray[0].size / numberFiles;
	int folderIndex = 0;

	for (int i = 1; i < ASIZE; i++) {
		intFiles = myArray[i].numFiles;
		numberFiles = static_cast<double>(intFiles);
		avgSize = myArray[i].size / numberFiles;
		if (avgSize < lowestSize) {
			lowestSize = avgSize;
			folderIndex = i;
		}
	}
	return folderIndex;
}


void editFolders(Folders folderArray[])
{
	int userNumber;
	double fileSize;

	Folders editedArray[ASIZE];

	for (int i = 0; i < ASIZE; i++) {
		editedArray[i].fileNum = folderArray[i].fileNum;
		editedArray[i].name = folderArray[i].name;
		editedArray[i].numFiles = folderArray[i].numFiles;
		editedArray[i].size = folderArray[i].size;
	}

	display(editedArray);
	cout << "Enter the folder number (0 to quit):" << endl;
	cout << "Total size of all folders: " << totalSize(editedArray) << endl;
	cout << "Folder with the lowest average file size: " << editedArray[lowestAvgSize(editedArray)].name << endl;
	
	for (; ; ) {
		//cout << "Enter the folder number (0 to quit): ";
		cin >> userNumber;
		if (userNumber < 0 || userNumber > 10) {
			cout << "Invalid folder number\n";
			break;
		}
		if (userNumber == 0) {
			break;
		}
		else {
			userNumber -= 1;
		}
		cout << endl;
		cout << "Enter the file size: ";
		cin >> fileSize;
		cout << endl;

		editedArray[userNumber].numFiles += 1;
		editedArray[userNumber].size += fileSize;

		display(editedArray);
		cout << "Total size of all folders: " << totalSize(editedArray) << endl;
		cout << "Folder with the lowest average file size: " << editedArray[lowestAvgSize(editedArray)].name << endl;
	}

}


int main()	// main function initializes struct array and calls other functions 
{
	Folders folderArray[ASIZE] = {
		{ 1, "Documents", 5, 12.38 },
		{ 2, "Downloads", 11, 17.22 },
		{ 3, "Pictures", 27, 30.26 },
		{ 4, "Videos", 6, 22.75 },
		{ 5, "Projects", 3, 7.94 },
		{ 6, "Labs", 6, 1.44 },
		{ 7, "Music", 45, 102.73 },
		{ 8, "Favorites", 4, 2.10 },
		{ 9, "Contacts", 35, 3.51 },
		{ 10, "Miscellaneous", 1, 2.23 }
	};


	editFolders(folderArray);

	return 0;
}