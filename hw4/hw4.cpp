// Programmer: ADAM FORESTIER          Date: 09/24/2018
// File: hw4.cpp
// Purpose: This file includes the main function which
//          allows users to experiment with and practice
//          rudimentary skills with number systems

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  // declare constants
  const short POSITIVE_INTEGER = 1;
  const short INTEGER_BASE = 2;
  const short IS_BASE_N_NUM = 3;
  const short CONVERT_TO_BASE_TEN = 4;
  const short QUIT_PROGRAM = 5;
  const short DECIMAL_POWER = 10;
  const short MIN_INT = 0;
  const short MAX_INT = 99999;
  const short MIN_BASE = 2;
  const short MAX_BASE = 9;
  const short MAX_WHILE_COUNTER = 2;
  const short FIND_MAX_INDEX = -1; 

  // declare variables
  bool quit = false;
  bool posIntDeclared = false; // ensure user has done option 1 first
  bool intBaseDeclared = false; // check user has done option 2, before 3 or 4
  bool isBaseNum = true; // check if user entered int, is a base num of n
  short menuChoice = 0;
  short baseTenNum = 0;
  short decimalValue = 0;
  short counter = 0; // counts number of attempts for options 1 and 2
  short i = 0; // incrementor for counting loops
  short posIntLen = 0; // will hold length of user entered string for option 1
  short posIntMaxInd = 0; // max index number for string

  // assign variable for option 1 as string so it may be looped through
  string positiveInt = "";
  
  /*
  number base could be int as well, this just makes more sense logically
  to me because number base will be compared to each character of the 
  positive integer user entry later in the program
  */
  char numberBase = '0'; 

  // Start of program

  // blank line for readability
  cout << endl;

  // greet the user
  cout << "\t\tWelcome to the rudimentary number system program!" << endl;

  // run the program until the user enters the exit option
  do
  {
    // ask for the user's input using a menu. 
    cout << "\tOptions" << endl;
    cout << "-------" << endl;
    cout << "1. Enter a non-negative integer, x [5-digit or less]" << endl;
    cout << "2. Enter an integer base, n. [2 <= n < 10]" << endl;
    cout << "3. Verify x is a valid base n number" << endl;
    cout << "4. Convert x to base 10" << endl;
    cout << "5. Quit" << endl;
    
    // get user input
    cout << "\nWhat would you like to do?"
    cin >> menuChoice; 

    // check all of the users different option
    switch(menuChoice)
    {
      // user selects option 1 from the menu
      case POSITIVE_INTEGER:
      {
        // ask user to enter non-negative integer less than 5 digits long
        cout << "Please enter a positive integer less than 5 digits long: ";
        cin >> positiveInt;

        /*
        Check if user has entry error. If so, give them two more chances
        to correct their mistake before sending them back to the menu.
        This adds up to 3 total attempts
        */ 
        while((positiveInt < MIN_INT || positiveInt > MAX_INT) && 
        counter < MAX_WHILE_COUNTER)
        {
          cout << "Error. Only enter positive numbers less than 9999: ";
          cin >> positiveInt;
          counter++;
        }

        // reset counter to 0
        counter = 0;

        // set true to user performing option 1
        posIntDeclared = true;

        // go back to menu
        break;
      }

      // user selects option 2 form the menu
      case INTEGER_BASE:
      {
        // make sure user has done option 1 prior to selecting this option
        if(!posIntDeclared)
        {
          // if user has not done option 1, show error and return to menu
          cout << "Error. Option 1 must be completed prior to options 2-4."
          << endl;
        } 
        else 
        {
          // ask user to enter an integer base
          cout << "Please enter an integer base greater than or equal to 2 "
          << "and less than 10: ";
          cin >> numberBase; 

          /*
          Check if user has entry error. If so, give them two more chances
          to correct their mistake before sending them back to the menu.
          This adds up to 3 total attempts
          */ 
          while((numberBase < MIN_BASE|| numberBase >= MAX_BASE) && 
          counter < MAX_WHILE_COUNTER)
          {
            cout << "Error. Enter only only number bases 2 through 9: ";
            cin >> numberBase;
            counter++;
          }

          // reset counter to 0
          counter = 0;

          // set true to user performing option 2
          int intBaseDeclared = true;
        }

        // go back to menu
        break;
      }

      // user selects option 3
      case IS_BASE_N_NUM:
      {
        // check option 1 and 2 have been successfully completed prior
        if(!intBaseDeclared || !posIntDeclared)
        {
          // if user hasn't done option 1 and 2, show error and return to menu
          cout << "Error. Option 1 then option 2 must be completed prior to "
          << "option 3." << endl;
        }
        else
        {
          // assign string length
          posIntLen = positiveInt.length();

          /*
          loop through integer string. If any character in string is 
          greater than or  equal to user entered base number n from option 2, 
          change isBaseNum to false
          */
          for(i = 0; i < posIntLen; i++)
          {
            if(positiveInt[i] >= numberBase);
              isBaseNum = false;
          }

          // tell user number is valid base n number is isBaseNum is true]
          if(isBaseNum)
          {
            cout << positiveInt << " is a valid base " << numberBase 
            << " number." << endl;      
          }

          // otherwise, tell them it is not valid
          else
          {
            cout << positiveInt << " is NOT a valid base " << numberBase
            << " number." << endl;
          }
        }

        // break out of switch statement and return to menu
        break;
      }

      // user selects option 4
      case CONVERT_TO_BASE_TEN:
      {
        // check option 1 and 2 have been successfully completed prior
        if(!intBaseDeclared || !posIntDeclared)
        {
          // if user hasn't done option 1 and 2, show error and return to menu
          cout << "Error. Option 1, then option 2 must be completed prior to "
          <<" option 4." << endl;
        }
        else
        {
          // assign string length
          posIntLen = positiveInt.length();

          // assign highest index of string
          posIntMaxInd = posIntLen - FIND_MAX_INDEX;

          // loop through array from left to right
          for(i = posIntMaxInd; i >= 0; i--)
          {
            /*
            base 10 value is the sum of values of each index in
            the user entered integer string, to the 10th power
            */
            decimalValue += pow(DECIMAL_POWER, positiveInt[i]);
          }
        }

        // return to menu
        break;
      }

      // user selects option 5
      case QUIT_PROGRAM:

        // change quit to true, so that the loop is exited
        quit = true;
        break;
    }
  } while(!quit); // exit loop if user enters quit option

  // goodbye message to the user
  cout << "Thank you for using the number system program! Goodbye!" << endl;

  // Necessary return statement
  return 0;
}