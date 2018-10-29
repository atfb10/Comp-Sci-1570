//Programmer: Daniel Money, Adam Forestier              date: 23 October 2018
//File: hw8.cpp
//Purpose: Simulates a debate between two candidates by randomly generating
//         answers to arbitrary questions and calculating a score by 
//         comparing the number of letters present in question and answer.


#include <iostream>
#include <fstream>
#include "hw8.h"

using namespace std;

int main()
{
  //Variable, array, and stream declarations
  char question[MAX_QUEST_LENGTH];
  char answer[MAX_ANS_LENGTH];
  int score=0;
  int cand1Total=0;
  int cand2Total=0;
  ifstream answerFile;
  ifstream nounFile;
  
  //Greeting
  cout<<"Welcome to the campaign debate simulator."<<endl
      <<"You will enter four questions for each candidate "<<endl
      <<"and they will recieve a score based on their answers."<<endl
      <<"Enter your questions below: "<<endl;

  for (int i=0; i<4; i++)
  {
    cout<<"Candidate #1: ";
    questionInput(question);
    selectAnswer(answer, answerFile, nounFile);
    score=calcScore(answer, question);
    cout<<"Candidate 1's answer: "<<answer
        <<"    Score: "<<score<<endl<<endl;
    cand1Total+=score;
    cout<<"Candidate #2: ";
    questionInput(question);
    selectAnswer(answer, answerFile, nounFile);
    score=calcScore(answer, question);
    cout<<"Candidate 2's answer: "<<answer
        <<"    Score: "<<score<<endl<<endl;
    cand2Total+=score;
  }

  printResults(cand1Total, cand2Total);

  cout<<"The debate is over, have a safe drive home."<<endl;

  return 0;
}
