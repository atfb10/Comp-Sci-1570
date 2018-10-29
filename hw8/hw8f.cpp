//Programmer: Daniel Money, Adam Forestier              date: 23 October 2018
//File: hw8f.cpp
//Purpose: Function definitions for hw8.cpp

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "hw8.h"

using namespace std;

//Gathers question input from user:
void questionInput(char question[])
{
//Including the ignore broke everything idk why
//  cin.ignore(500, '\n');
  cin.getline(question, MAX_QUEST_LENGTH-1);
  return;
}


//Selects a random answer from answers.dat, replacing nouns where necessary:
void selectAnswer(char answer[], ifstream & answerFile,
                    ifstream & nounFile)
{
  int numData;
  char noun[MAX_NOUN_LENGTH];
  int numNouns=0;
  int counter=0;

  answerFile.open("answers.dat"); //Open and close the streams every
  nounFile.open("nouns.dat");      //run to reset the random selection

  srand(time(NULL));

//Finding number of nouns total in nounFile:
  while (nounFile>>noun)
  {
    numNouns++;
  }
  nounFile.close();         //Close and reopen the noun stream 
  nounFile.open("nouns.dat");//so we are at the top of the file again

//Sets our 'cursor' in answer file to the randomly selected line
  answerFile>>numData;
  for (int i=0; i<=rand()%numData; i++)
  {                                   
    answerFile.getline(answer, MAX_ANS_LENGTH-1, '\n');
  }

//This do...while loop is where the answer and nouns are actually
//added into the array 'answers':
  do
  {      //Now that we are on the randomly selected
         //line, take the answer one char at a time 
    answerFile.get(answer[counter]);

    if (answer[counter]=='*')
    {
        //Ignores the next few characters from answerFile,
        //which will be "noun*"
      answerFile.ignore(6, '*'); 

      answer[counter]='\0'; //Set the current element to null so the chosen
                            //noun can be added using strcat function
      for (int i=0; i<rand()%numNouns; i++)
      {                     //At the conclusion of the loop the randomly
        nounFile>>noun;     //chosen noun will be in the array 'noun'
      }
      strcat(answer, noun);

      counter=strlen(answer)-1; //After using strcat, the character after
    }                         //the noun will be null, so set the counter
                              //to the index before this null (since 
                              //incrementing counter at the end of the loop
                              //will place us at the correct element to
                              //continue from).
    counter++;  
    
  } while (answer[counter-1]!='\n');
  
  answer[counter]='\0';  //Sets last element to null so outputs correctly

  answerFile.close();
  nounFile.close();
  return;
}



//Calculates and returns the score for the current quesiton/answer pair:
int calcScore(const char answer[], const char question[])
{
  int questionCount=0;
  int answerCount=0;
  int questionLen;
  int answerLen;
  int score=0;

  questionLen=strlen(question);
  answerLen=strlen(answer);

  for (int i=65; i<91; i++) //Loop through all ASCII values for each letter
  {                         //65-91 is the range of ASCII characters from a-z
    for (int j=0; j<questionLen; j++) //Counts number of current letter
    {                                      //in the question.
      //i+32 accounts for the possibility of uppercase letters.
      if (question[j]==i || question[j]==(i+32)) 
      {                                          
        questionCount++;
      }
    }
    for (int k=0; k<answerLen; k++) //Counts number of current letter
    {                                    //in the answer
      if (answer[k]==i || answer[k]==(i+32))
      {
        answerCount++;
      }
    }
    score+=(questionCount-answerCount);
    questionCount=0;
    answerCount=0;
  }                                     

  return score;
}


//Prints total scores for each candidate and declares a winner:
void printResults(const int cand1Total, const int cand2Total)
{
  cout<<"That's the end of the debate. The scores are: "<<endl
      <<"Candidate 1: "<<cand1Total<<endl
      <<"Candidate 2: "<<cand2Total<<endl
      <<"The winner is ";
  if (cand1Total<cand2Total)
  {
    cout<<"Candidate 1!"<<endl;
  }
  else if (cand2Total<cand1Total)
  {
    cout<<"Candidate 2!"<<endl;
  }
  else
  {
    cout<<" neither! It's a tie!"<<endl;
  }

  return;
}
