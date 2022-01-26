// File Name: UnitTests.cpp
//
// Author: Vladyslav Prokopenko
// Date: 10/26/2020
// Assignment Number: 5
// CS 2308/CS 5301 Fall 2020
// Instructor: Jill Seaman

#include <iostream>
#include <sstream>
#include "MovieList.h"

using namespace std;

bool testAddToTop(ostream& testFeedback);
bool testAddBottom(ostream& testFeedback);
bool testRemove(ostream& testFeedback);
bool testRemoveFirst(ostream& testFeedback);
bool testRemoveNonExisting(ostream& testFeedback);
bool testRemoveAll(ostream& testFeedback);
bool testMoveToTop(ostream& testFeedback);
bool testMoveToTopNonExisting(ostream& testFeedback);
bool testMoveToPosition(ostream& testFeedback);
bool testMoveToPositionNonExisting(ostream& testFeedback);
bool testNextLarger(ostream& testFeedback);
bool testNextLargerNoLarger(ostream& testFeedback);
bool testDisplaySorted(ostream& testFeedback);


// Worst movies ever according to https://www.imdb.com/chart/bottom
const int N_TITLES = 5;
string titles[N_TITLES] = {
        "Disaster Movie",
        "Superbabies: Baby Geniuses 2",
        "Code Name: K.O.Z.",
        "Manos: The Hands of Fate",
        "Birdemic: Shock and Terror"};
MovieList movieQueue;


int main(){
    cout << "Add to the top: ";
    testAddToTop(cout);

    cout << "Add to the bottom and to the top: ";
    testAddBottom(cout);

    cout << "Remove a movie: ";
    testRemove(cout);

    cout << "Remove the first movie: ";
    testRemoveFirst(cout);

    cout << "Test remove a non-existing movie: ";
    testRemoveNonExisting(cout);

    cout << "Test delete all movies: ";
    testRemoveAll(cout);

    cout << "Test move to top: ";
    testMoveToTop(cout);

    cout << "Test move a non-existing movie to top: ";
    testMoveToTopNonExisting(cout);

    cout << "Test move to position: ";
    testMoveToPosition(cout);

    cout << "Test move to position non-existing: ";
    testMoveToPositionNonExisting(cout);
    
    cout << "Test next larger: ";
    testNextLarger(cout);

    cout << "Test next larger without next larger: ";
    testNextLargerNoLarger(cout);

    cout << "Test display sorted movies: ";
    testDisplaySorted(cout);


    return 0;
}


MovieList* movieQueueFromArray(const string titles[], const int SIZE){
    MovieList* movieQueue = new MovieList();
    for (int i = SIZE - 1; i >= 0; --i){
        movieQueue->addToTop(titles[i]);
    }
    return movieQueue;
}

bool testAddToTop(ostream& testFeedback){
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    stringstream s;
    movieQueue.display(s);
    string expected = "0: Disaster Movie\n"
                      "1: Superbabies: Baby Geniuses 2\n"
                      "2: Code Name: K.O.Z.\n"
                      "3: Manos: The Hands of Fate\n"
                      "4: Birdemic: Shock and Terror\n";

    string str = s.str();
    bool passed = (str == expected);
    if (passed){
        testFeedback << "Passed" << endl;
        return true;
    }
    else{
        testFeedback << "Expected" << endl << expected << endl << endl << "Got:" << endl << str << endl;
        testFeedback << "Failed" << endl;
        return false;
    }
}

bool testAddBottom(ostream& testFeedback){
    movieQueue = MovieList();
    movieQueue.addToBottom("Manos: The Hands of Fate");
    movieQueue.addToTop("Code Name: K.O.Z.");
    movieQueue.addToBottom("Birdemic: Shock and Terror");
    movieQueue.addToTop("Superbabies: Baby Geniuses 2");
    movieQueue.addToTop("Disaster Movie");

    stringstream s;
    movieQueue.display(s);
    string expected = "0: Disaster Movie\n"
                      "1: Superbabies: Baby Geniuses 2\n"
                      "2: Code Name: K.O.Z.\n"
                      "3: Manos: The Hands of Fate\n"
                      "4: Birdemic: Shock and Terror\n";

    string str = s.str();
    bool passed = (str == expected);
    if (passed){
        testFeedback << "Passed" << endl;
        return true;
    }
    else{
        testFeedback << "Expected" << endl << expected << endl << endl << "Got:" << endl << str << endl;
        testFeedback << "Failed" << endl;
        return false;
    }
}

bool testRemove(ostream& testFeedback){
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool removed = movieQueue.remove("Manos: The Hands of Fate");

    stringstream s;
    movieQueue.display(s);
    string expected = "0: Disaster Movie\n"
                      "1: Superbabies: Baby Geniuses 2\n"
                      "2: Code Name: K.O.Z.\n"
                      "3: Birdemic: Shock and Terror\n";
    bool expectedRemove = true;

    string str = s.str();
    bool passed = (str == expected) && (removed == expectedRemove);
    if (passed){
        testFeedback << "Passed" << endl;
        return true;
    }
    else{
        if (str != expected)
            testFeedback << "Expected" << endl << expected << endl << endl << "Got:" << endl << str << endl;
        if (removed != expectedRemove)
            testFeedback << "Expected for remove to return " << expectedRemove << ", but returned " << removed << endl;
        testFeedback << "Failed" << endl;
        return false;
    }
}

bool testRemoveFirst(ostream& testFeedback){
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool removed = movieQueue.remove("Disaster Movie");

    stringstream s;
    movieQueue.display(s);
    string expected = "0: Superbabies: Baby Geniuses 2\n"
                      "1: Code Name: K.O.Z.\n"
                      "2: Manos: The Hands of Fate\n"
                      "3: Birdemic: Shock and Terror\n";
    bool expectedRemove = true;

    string str = s.str();
    bool passed = (str == expected) && (removed == expectedRemove);
    if (passed){
        testFeedback << "Passed" << endl;
        return true;
    }
    else{
        if (str != expected)
            testFeedback << "Expected" << endl << expected << endl << endl << "Got:" << endl << str << endl;
        if (removed != expectedRemove)
            testFeedback << "Expected for remove to return " << expectedRemove << ", but returned " << removed << endl;
        testFeedback << "Failed" << endl;
        return false;
    }
}

bool testRemoveNonExisting(ostream& testFeedback){
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool removed = movieQueue.remove("Awesome Movie");

    stringstream s;
    movieQueue.display(s);
    string expected = "0: Disaster Movie\n"
                      "1: Superbabies: Baby Geniuses 2\n"
                      "2: Code Name: K.O.Z.\n"
                      "3: Manos: The Hands of Fate\n"
                      "4: Birdemic: Shock and Terror\n";
    bool expectedRemove = false;

    string str = s.str();
    bool passed = (str == expected) && (removed == expectedRemove);
    if (passed){
        testFeedback << "Passed" << endl;
        return true;
    }
    else{
        if (str != expected)
            testFeedback << "Expected" << endl << expected << endl << endl << "Got:" << endl << str << endl;
        if (removed != expectedRemove)
            testFeedback << "Expected for remove to return " << expectedRemove << ", but returned " << removed << endl;
        testFeedback << "Failed" << endl;
        return false;
    }
}

bool testRemoveAll(ostream& testFeedback){
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    for (int i = 0; i < N_TITLES; ++i){
        movieQueue.remove(titles[i]);
    }

    stringstream s;
    movieQueue.display(s);
    string expected = "";

    string str = s.str();
    bool passed = (str == expected);
    if (passed){
        testFeedback << "Passed" << endl;
        return true;
    }
    else{
        testFeedback << "Expected" << endl << expected << endl << endl << "Got:" << endl << str << endl;
        testFeedback << "Failed" << endl;
        return false;
    }
}

bool testMoveToTop(ostream& testFeedback){
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool moved = movieQueue.moveToTop("Code Name: K.O.Z.");

    stringstream s;
    movieQueue.display(s);
    string expected = "0: Code Name: K.O.Z.\n"
                      "1: Disaster Movie\n"
                      "2: Superbabies: Baby Geniuses 2\n"
                      "3: Manos: The Hands of Fate\n"
                      "4: Birdemic: Shock and Terror\n";
    bool expectedMoved = true;

    string str = s.str();
    bool passed = (str == expected) && (moved == expectedMoved);
    if (passed){
        testFeedback << "Passed" << endl;
        return true;
    }
    else{
        if (str != expected)
            testFeedback << "Expected" << endl << expected << endl << endl << "Got:" << endl << str << endl;
        if (moved != expectedMoved)
            testFeedback << "Expected for move to return " << expectedMoved << ", but returned " << moved << endl;
        testFeedback << "Failed" << endl;
        return false;
    }
}

bool testMoveToTopNonExisting(ostream& testFeedback){
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool moved = movieQueue.moveToTop("Not even a movie");

    stringstream s;
    movieQueue.display(s);
    string expected = "0: Disaster Movie\n"
                      "1: Superbabies: Baby Geniuses 2\n"
                      "2: Code Name: K.O.Z.\n"
                      "3: Manos: The Hands of Fate\n"
                      "4: Birdemic: Shock and Terror\n";
    bool expectedMoved = false;

    string str = s.str();
    bool passed = (str == expected) && (moved == expectedMoved);
    if (passed){
        testFeedback << "Passed" << endl;
        return true;
    }
    else{
        if (str != expected)
            testFeedback << "Expected" << endl << expected << endl << endl << "Got:" << endl << str << endl;
        if (moved != expectedMoved)
            testFeedback << "Expected for move to return " << expectedMoved << ", but returned " << moved << endl;
        testFeedback << "Failed" << endl;
        return false;
    }
}

bool testMoveToPosition(ostream& testFeedback){
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool moved = movieQueue.moveToPosition("Disaster Movie", 3);

    stringstream s;
    movieQueue.display(s);
    string expected = "0: Superbabies: Baby Geniuses 2\n"
                      "1: Code Name: K.O.Z.\n"
                      "2: Manos: The Hands of Fate\n"
                      "3: Disaster Movie\n"
                      "4: Birdemic: Shock and Terror\n";
    bool expectedMoved = true;

    string str = s.str();
    bool passed = (str == expected) && (moved == expectedMoved);
    if (passed){
        testFeedback << "Passed" << endl;
        return true;
    }
    else{
        if (str != expected)
            testFeedback << "Expected" << endl << expected << endl << endl << "Got:" << endl << str << endl;
        if (moved != expectedMoved)
            testFeedback << "Expected for move to return " << expectedMoved << ", but returned " << moved << endl;
        testFeedback << "Failed" << endl;
        return false;
    }
}

bool testMoveToPositionNonExisting(ostream& testFeedback){
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    bool moved = movieQueue.moveToTop("NONAME");

    stringstream s;
    movieQueue.display(s);
    string expected = "0: Disaster Movie\n"
                      "1: Superbabies: Baby Geniuses 2\n"
                      "2: Code Name: K.O.Z.\n"
                      "3: Manos: The Hands of Fate\n"
                      "4: Birdemic: Shock and Terror\n";
    bool expectedMoved = false;

    string str = s.str();
    bool passed = (str == expected) && (moved == expectedMoved);
    if (passed){
        testFeedback << "Passed" << endl;
        return true;
    }
    else{
        if (str != expected)
            testFeedback << "Expected" << endl << expected << endl << endl << "Got:" << endl << str << endl;
        if (moved != expectedMoved)
            testFeedback << "Expected for move to return " << expectedMoved << ", but returned " << moved << endl;
        testFeedback << "Failed" << endl;
        return false;
    }
}

bool testNextLarger(ostream& testFeedback) {
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    string nextLargest = movieQueue.nextLarger("Manos: The Hands of Fate");
    string expected = "Superbabies: Baby Geniuses 2";
    if (nextLargest != expected){
        cout << "Expected next largest: " << expected << endl << "Got: " << nextLargest << endl;
        cout << "Failed" << endl;
        return false;
    }
    else{
        cout << "Passed" << endl;
        return true;
    }
}

bool testNextLargerNoLarger(ostream& testFeedback) {
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    string nextLargest = movieQueue.nextLarger("Z");
    string expected = "";
    if (nextLargest != expected){
        cout << "Expected next largest: " << expected << endl << "Got: " << nextLargest << endl;
        cout << "Failed" << endl;
        return false;
    }
    else{
        cout << "Passed" << endl;
        return true;
    }
}

bool testDisplaySorted(ostream& testFeedback){
    movieQueue = *movieQueueFromArray(titles, N_TITLES);
    stringstream s, s1;
    movieQueue.displaySorted(s);
    movieQueue.display(s1);
    string expected = "0: Birdemic: Shock and Terror\n"
                      "1: Code Name: K.O.Z.\n"
                      "2: Disaster Movie\n"
                      "3: Manos: The Hands of Fate\n"
                      "4: Superbabies: Baby Geniuses 2\n";

    string expected1 = "0: Disaster Movie\n"
                       "1: Superbabies: Baby Geniuses 2\n"
                       "2: Code Name: K.O.Z.\n"
                       "3: Manos: The Hands of Fate\n"
                       "4: Birdemic: Shock and Terror\n";

    string str = s.str(), str1 = s1.str();
    bool passed = (str == expected) && (str1 == expected1);
    if (passed){
        testFeedback << "Passed" << endl;
        return true;
    }
    else{
        if (str != expected)
            testFeedback << "Expected sorted" << endl << expected << endl << endl << "Got:" << endl << str << endl;

        if (str1 != expected1)
            testFeedback << "Expected an original array to be unsorted" << endl << expected1 << endl << endl <<
                            "Got:" << endl << str1 << endl;

        testFeedback << "Failed" << endl;
        return false;
    }
}
