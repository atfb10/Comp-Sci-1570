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

  /*
  Consts for dividing and modulating digit values
  Five is for the left most digit and decreases from left to right;
  meaning ONE_DIGIT const is right most digit
  */
  const short FIVE_DIGIT_DIVIDENT = 10000;
  const short FOUR_DIGIT_MOD = 10000;
  const short FOUR_DIGIT_DIVIDENT = 1000;
  const short THREE_DIGIT_MOD = 10;
  const short THREE_DIGIT_DIVIDENT = 100;
  const short TWO_DIGIT_MOD = 100;
  const short TWO_DIGIT_DIVIDENT = 10;
  const short ONE_DIGIT_MOD = 10;

  // declare variables
  bool quit = false;
  bool posIntDeclared = false; // ensure user has done option 1 first
  bool intBaseDeclared = false; // check user has done option 2, before 3 or 4
  bool isBaseNum = true; // check if user entered int, is a base num of n
  short positiveIntInput = 0;
  short numberBase = 0;
  short tenThousandsDigit = 0;
  short thousandsDigit = 0;
  short hundredsDigit = 0;
  short tensDigit = 0;
  short onesDigit = 0;
  short menuChoice = 0;
  short baseTenNum = 0;
  short decimalValue = 0;
  short counter = 0; // counts number of attempts for options 1 and 2
  short i = 0; // incrementor for counting loops
  short posIntLen = 0; // will hold length of user entered string for option 1
  short posIntMaxInd = 0; // max index number for string
 

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
        cin >> positiveIntInput;

        /*
        Check if user has entry error. If so, give them two more chances
        to correct their mistake before sending them back to the menu.
        This adds up to 3 total attempts
        */ 
        while(positiveIntInput < MIN_INT && positiveIntInput > MAX_INT && 
        counter < MAX_WHILE_COUNTER)
        {
          cout << "Error. Only enter positive numbers less than 9999: ";
          cin >> positiveIntInput;
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
          while(numberBase < MIN_BASE && numberBase > MAX_BASE && 
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
          /*
          find each digit value (left to right)
          This works because, even if there are less than 5 digits, the 
          result will be less than one. Because these variables are of 
          the short type, the decimal will be dropped and will result
          for said variable will be zero
          */
          tenThousandsDigit = positiveIntInput / FIVE_DIGIT_DIVIDENT;
          thousandsDigit = (positiveIntInput % FOUR_DIGIT_MOD) / 
          FOUR_DIGIT_DIVIDENT;
          hundredsDigit = (positiveIntInput / THREE_DIGIT_DIVIDENT)
          % THREE_DIGIT_MOD;
          tensDigit = (positiveIntInput % TWO_DIGIT_MOD) / 
          TWO_DIGIT_DIVIDENT;
          onesDigit = positiveIntInput % ONE_DIGIT_MOD;

          /*
          check to make sure all of digits are less than the base number n
          done as nested if for readability and to not exceed column 80
          */
          if(tenThousandsDigit < numberBase && thousandsDigit < numberBase)
          {
            if(hundredsDigit < numberBase && tensDigit < numberBase)
            {
              if(onesDigit < numberBase)
              {
                // set isBaseNum to true if all criteria are met
                isBaseNum = true;
              }
            }
          }

          // tell user number is valid base n number is isBaseNum is true
          if(isBaseNum)
          {
            cout << positiveIntInput << " is a valid base " << numberBase 
            << " number." << endl;      
          }

          // otherwise, tell them it is not valid
          else
          {
            cout << positiveIntInput << " is NOT a valid base " << numberBase
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
        // if option 1 and 2 are done, find the number's value in base ten
        else
        {
          // add up the values of all digits taken to power of ten
          baseTenNum = pow(10, tenThousandsDigit) + pow(10, thousandsDigit) +
          pow(10, hundredsDigit) + pow(10, tensDigit) + pow(10, onesDigit);

          // tell user the value
          cout << "The number " << positiveIntInput << " = " << baseTenNum 
          << " in base 10!" << endl;
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