#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// Question.h
class Question {
public:
    string stem;
    string answers[4];
    string key;
    char answerKey;
    Question();
    Question(string stem1, string answers1[], string key1);
    void setStem(string stem1);
    string getStem();
    void setAnswers(string answers1[]);
    string getAnswer(int i);
    void setKey(string key1);
    string getKey();
    void swapAnswers(int a, int b);
    string ask(int questionNum, Question array1[]);
};

//Question.cpp
//Construct question with no values
Question::Question() {
    stem = "";
    for (int i = 0; i < 4; i++)
        answers[i] = "";
    key = "X";  
    answerKey = key[0];
}
//Construct question given its 3 components
Question::Question(string stem1, string answers1[], string key1) {
    stem = stem1;
    for (int i = 0; i < 4; i++)
        answers[i] = answers1[i];
    key = key1;
}
//Set the stem question
void Question::setStem(string stem1) {
    stem = stem1;
}
//Return stem question
string Question::getStem() {
    return stem;
}
//Set the 4 answers given an array
void Question::setAnswers(string answers1[]) {
    for (int i = 0; i < 4; i++)
        answers[i] = answers1[i];
}
//Return single answer at index i
string Question::getAnswer(int i) {
    return answers[i];
}
//Set the key letter
void Question::setKey(string key1) {
    key = key1;
}
//Return the key letter
string Question::getKey() {
    return key;
}
//Swap answers given integers a and b
void Question::swapAnswers(int a, int b) {
    int indexA = a % 4;
    int indexB = b % 4;
    swap(answers[indexA], answers[indexB]);
    //code to update the key
}
//Compute and return stem and answers
string Question::ask(int questionNum, Question array1[]) {
    string QA;
    string option1, option2, option3, option4;
   
    option1 = "A. " + array1[questionNum].answers[0] + "\n";
    option2 = "B. " + array1[questionNum].answers[1] + "\n";
    option3 = "C. " + array1[questionNum].answers[2] + "\n";
    option4 = "D. " + array1[questionNum].answers[3] + "\n";
    QA = array1[questionNum].stem + "\n" + option1 + option2 + option3 + option4;
    return QA;
}

// quizDriver
int main()
{
    ifstream quiz;
    quiz.open("questions.txt");

    //read questions from text file and store into array
    Question questions[5];
    Question q1;
    for (int i = 0; i < 5; i++) {
        getline(quiz, questions[i].stem);
        quiz >> ws;
        getline(quiz, questions[i].answers[0]);
        quiz >> ws;
        getline(quiz, questions[i].answers[1]);
        quiz >> ws;
        getline(quiz, questions[i].answers[2]);
        quiz >> ws;
        getline(quiz, questions[i].answers[3]);
        quiz >> ws;
        getline(quiz, questions[i].key);
        quiz >> ws;
    }

    // ask questions
    Question q2;
    for (int i = 1; i < 6; i++) {
        q2.ask(i, questions);
    }

    return 0;

}



