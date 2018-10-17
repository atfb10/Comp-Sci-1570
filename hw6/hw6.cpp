// Programmer: ADAM FORESTIER	   Date: 10/11/2018
// File: hw6.cpp				         Section: E
// Purpose: This file contains the main function to 
//          display menu to user, run program, quit 
//          program, and utilize math functions.

#include <iostream>
#include <cstdlib>
#include "math_func.h"
using namespace std;

int main()
{
  // initialize main function variables
  bool validPair;
  short menuOptions;
  bool quit = false;
  long integerVal;
  short baseVal;
  bool intSet = false;
  bool baseSet = false;
  bool isBaseNum;
  long decimalVal;

  // set the seed for the random number generator
  srand(SEED_INSTRUCTION);

  // greet the user after a blank line for readability
  cout << endl;
  cout << "\t\tWelcome to the number system calculator!\n" << endl;

  // allow program to rerun until user elects go quit
  do
  {
    // create menu with options displayed for user to perform
    cout << "Options" << endl;
    cout << "-------" << endl;
    cout << "1. Enter a non-negative integer, x[" << MAX_DIGITS 
    << "-digit or less]" << endl;
    cout << "2. Enter an integer base. n [" << MIN_BASE << " <= n < " 
    << MAX_BASE << "]" << endl;
    cout << "3. Verify x is a valid base n number" << endl;
    cout << "4. Force validation with new smallest, valid base assignment" 
    << endl;
    cout << "5. Force validation with new (random digits in) x" << endl;
    cout << "6. Convert x to base " << CONVERT_TO_DEC << endl;
    cout << "7. Quit" << endl;

    // ask user what they would like to do
    cout << "\nWhich action would you like to perform? ";
    cin >> menuOptions;

    // blank line for readability
    cout << endl;

    // perform actions based upon user menu selection
    switch(menuOptions)
    {
      // user is able to enter original integer x
      case ENTER_INT :
      {
        // assign int value to be what the user inputs
        integerVal = getInt();
        intSet = true;

        // line for readability 
        cout << endl;

        break;
      } 
      
      // user is able to enter a base number n
      case ENTER_BASE_NUM :
      {
        // assign int value to be what the user inputs
        baseVal = getBase();       
        baseSet = true; 

        // line for readability 
        cout << endl;

        break;
      }

      // check to see if integer is a number in base
      case VERIFY_BASE_NUM : 
      {
        // ensure steps 1 and 2 were completed prior
        if(intSet && baseSet)
        {
          // see if integer x is base num n
          isBaseNum = isBase(integerVal, baseVal);

          // If isBaseNum is true, inform user the int x is a valid base n
          if(isBaseNum)
          {
            cout << integerVal << " is a valid base " << baseVal << " number." 
            << endl;

            // set valid pair to be true, meaning x is a base of n
            validPair = true;
          }
          // otherwise, tell them it is not valid base
          else
          {
            cout << integerVal << " is NOT a valid base " << baseVal << " number." 
            << endl;

            // set valid pair to be false, meaning x is NOT a base of n
            validPair = false;
          }
        }

        // if option 1 and 2 were not completed prior
        else
        {
          cout << "Option " << ENTER_INT << " and " << ENTER_BASE_NUM 
          << " must be completed prior to " << VERIFY_BASE_NUM << ".";
        }

        // line for readability 
        cout << endl;

        break;
      }

      /*
      converts base number to minimum valid base number if not valid
      */
      case ASSIGN_BASE_NUM :
      {
        // ensure steps 1 and 2 were completed prior
        if(intSet && baseSet)
        {
          // see if integer x is base num n
          isBaseNum = isBase(integerVal, baseVal);

          // if already valid, tell user
          if(isBaseNum)
          {
            // set valid pair to be true, meaning x is a base of n
            validPair = true;

            // base is already valid
            cout << integerVal << " is already a valid number for base "
            << baseVal << ". Base number not changed." << endl;
          }

          // otherwise, set the base number to the new minimum valid base
          else
          {
            // new, minimum valid baseVal
            validBase(integerVal, baseVal);

            // set valid pair to be true, meaning x is a base of n
            validPair = true;

            // show user the new base
            cout << "The new base = " << baseVal << endl;
          }
        }

        // if option 1 and 2 were not completed prior
        else
        {
          cout << "Option " << ENTER_INT << " and " << ENTER_BASE_NUM 
          << " must be completed prior to " << ASSIGN_BASE_NUM << ".";
        }

        // line for readability 
        cout << endl;

        break;
      }
      
      // creates a random number that is in the range of the user selected base
      case RANDOM_DIGITS_IN_BASE : 
      {
        // ensure options 1 and 2 were completed prior
        if(intSet && baseSet)
        {
          // see if integer x is base num n
          isBaseNum = isBase(integerVal, baseVal);

          // if already valid, tell user
          if(isBaseNum)
          {
            // set valid pair to be true, meaning x is a base of n
            validPair = true;

            // integer is already valid
            cout << integerVal << " is already a valid number for base "
            << baseVal << ". Integer value not changed." << endl;
          }

          /* 
          otherwise, randomly generate new digits to replace the existing
          digits that are greater than or equal to the base
          */
          else
          {
            // change the integer value to be valid
            validInt(integerVal, baseVal);

            // say that pair is valid
            validPair = true;

            // show user the new integer
            cout << "The new integer = " << integerVal << endl;
          }
        }

        // if option 1 and 2 were not completed prior
        else
        {
          cout << "Option " << ENTER_INT << " and " << ENTER_BASE_NUM 
          << " must be completed prior to " << RANDOM_DIGITS_IN_BASE << ".";
        }

        // line for readability 
        cout << endl;

        break;  
      }
      
      // converts integer to decimal
      case CONVERT_TO_DEC : 
      {
        // ensure steps 1 and two are completed prior
        if(intSet && baseSet)
        {
          // make sure that int x is valid base n integer
          isBaseNum = isBase(integerVal, baseVal);

          // pair's validity is determined by isBaseNum
          validPair = isBaseNum;

          // perform calculation if valid pair
          if(validPair)
          {
            decimalVal = decVal(integerVal, baseVal);

            // tell user the value
            cout << "In base number " << baseVal << ", the number " << 
            integerVal << " = " << decimalVal << endl; 
          }

          // otherwise, tell them to make it is not a valid pair
          else
          {
            cout << integerVal << " is not a valid base " << baseVal 
            << " number. Please alter either one of the values through "
            << "one of the menu options before attempting to convert the" 
            << " value to a decimal." << endl;
          }
        }

        // if option 1 and 2 were not completed prior
        else
        {
          cout << "Option " << ENTER_INT << " and " << ENTER_BASE_NUM 
          << " must be completed prior to " << CONVERT_TO_DEC << ".";
        }

        // line for readability 
        cout << endl;

        break;
      }
      
      // exits the program
      case EXIT : 
      {
        // set quit to be true in order to exit program
        quit = true;
        break;
      }
      
      // this case handles if user selects any option besides what is on menu
      default : 
      {
        // tell user to select valid options
        cout << "Must only select options " << FIRST_MENU_OPTION << " through " 
        << LAST_MENU_OPTION << endl;

        break;
      }
    }
  } while(!quit); // exit menu when user elects to quit

  // goodbye message
  cout << "Thank you for using the number system calculator. Goodbye!\n" << endl;

  // necessary return statement
  return 0;
}