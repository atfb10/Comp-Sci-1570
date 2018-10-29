//Programmers: Daniel Money, Adam Forestier           date: 23 October 2018
//File: hw8.h
//Purpose: Contains global constants and function prototypes for hw8.cpp

#ifndef HW8_H
#define HW8_H

#include <fstream>

//Global constants:
const int MAX_NOUN_LENGTH=20;
const int MAX_QUEST_LENGTH=700;
const int MAX_ANS_LENGTH=700;



//Function prototypes:
//Description: questionInput() reads in from the user a string
//             into the char array question.
//Preconditions: char question[] is of adequate size to contain the string.
//Postconditions: char question[] contains the input from the user.
void questionInput(char question[]);

//Description: selectAnswer() retrieves a random answer from the data file
//             answers.dat (replacing *noun* with a random noun from file
//             nouns.dat) and places it into the char array answer[].
//Preconditions: answer[] must be of adequate size and the streams must both
//               be ready to be connected.
//Postconditions: char answer[] contains the randomly selected answer, with
//                replacement nouns.
void selectAnswer(char answer[], std::ifstream & answerFile,
                     std::ifstream & nounFile);

//Description: calcScore() calculates the difference between the number of
//             times the letter 'a' is present in the question and the answer,
//             and repeats for 'b', 'c', and so on, summing each calculation
//             to result in a total score.
//Preconditions: answer[] and question[] both must terminate in a null character.
//Postconditions: The candidate's score for the current question/answer is
//                returned.
int calcScore(const char answer[], const char question[]);

//Description: printResults() ouputs to the screen the total scores for each
//             candidate and declares the winner.
//Preconditions: None.
//Postconditions: A message is output to the screen declaring both scores
//                and the winner.
void printResults(const int finalScore1, const int finalScore2);


#endif
