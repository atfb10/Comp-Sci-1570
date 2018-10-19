// Programmer: ADAM FORESTIER	   Date: 10/22/2018
// File: hw7.cpp				   Section: E
// Purpose: This file contains the main function to
//          display menu to user, run program, quit
//          program, and utilize math functions.

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include "burger_name_funcs.h"
using namespace std;

// main function
int main()
{
  // initialize main function variables
  bool quit = false;
  burger krustyBurger;
  burger burgerArr[BURGER_ARRAY_SIZE];
  short counter = 0;
  short menuOption = 0;
  short burgerCount = 0;
  short pattyNum = 0;
  short baconNum = 0;
  short pickleNum = 0;

  // set the seed for the random number generator
  srand(time(NULL));

  // greet the user
  cout << endl; 
  cout << "\t\tWelcome to the " << BEG_BURGER_NAME << " Burger Name Generator!"
  << endl;

  // continue to run the program until the user selects the quit option
  do
  {
    // display menu of options
    printMenu();

    // ask user what they would like to do
    cout << "\nWhat would you like to do? ";
    cin >> menuOption;

    // determine what to perform based upon user menu selection
    switch(menuOption)
    {
      // user elects to create a new burger name
      case GEN_BURGER_NAME :
      {
        // get the amount of patties, pickles & bacon from random num functions
        krustyBurger.m_patties = randPatty();
        krustyBurger.m_baconOz = randomIngredient();
        krustyBurger.m_pickles = randomIngredient();

        /*
        pass member variable values into generateBurgerName function to
        create a burger name
        */
        krustyBurger.m_name = generateBurgerName(krustyBurger.m_patties,
                                                 krustyBurger.m_baconOz,
                                                 krustyBurger.m_pickles);

        // show the user the burger name generated with its attributes
        cout << "Burger Name Generated: ";
        cout << krustyBurger;

        /*
        If the burger is not currently in the array, add it to the array.
        Increment index counter for next burger to be added.
        Do not add burger to list if its name is already in the array.
        */
       if(!(exists(krustyBurger.m_name, burgerArr, burgerCount)))
       {
        /*
        Ensure counter does not exceed max array size.
        Do not want to accidentally walk of array.
        */

        // less than 37 items in array, add to array and increment counter
        if(counter < MAX_ARRAY_INDEX)
        {
          burgerArr[counter++] = krustyBurger;

          // increase length of items currently in burger array
          burgerCount++;
        }
        // array is full, inform user
        else
        {
          cout << "Burger list is full. Please delete burgers before "
               << "attempting to add more." << endl;
        }
       }
       // tell user the burger already exists
       else
       {
         cout << krustyBurger.m_name << " has not been added to the list, "
         << "because it already exists!" << endl;
       }

        // exit switch case
        break;
      }

      // user elects to print burger name list in its entirety
      case PRINT_BURGER_LIST :
      {
        cout << endl;

        // sort the burgers
        sort(burgerArr, burgerCount);

        // print sorted list of burgers
        printBurgers(burgerArr, burgerCount);

        // exit switch statement
        break;
      }

      // user elects to delete burger name from list
      case DELETE_BURGER_NAME :
      {
        // give user instructions
        cout << "Below you will select number of ingredients, "
             << "to determine which burger to delete from list" << endl;

        // ask for burger input
        cout << DELETE_INPUT_INSTRUCT << "of Patties: ";
        cin >> pattyNum;

        // make sure user gives valid input
        while(pattyNum < MIN_PATTY || pattyNum > MAX_PATTIES)
        {
          cout << "Error. Input must be between " << MIN_PATTY << " and " <<
          MAX_PATTIES << ": ";
          cin >> pattyNum;
        }

        // ask for bacon input
        cout << DELETE_INPUT_INSTRUCT << "Bacon Ounces: ";
        cin >> baconNum;

        // make sure user gives valid input
        while(baconNum < MIN_BACON || baconNum > MAX_BACON)
        {
          cout << "Error. Input must be between " << MIN_BACON << " and " <<
          MAX_BACON << ": ";
          cin >> baconNum;
        }

        // ask for pickle input
        cout << DELETE_INPUT_INSTRUCT << "of Pickles: ";
        cin >> pickleNum;

        // make sure user gives valid input
        while(pickleNum < MIN_PICKLE || pickleNum > MAX_PICKLE)
        {
          cout << "Error. Input must be between " << MIN_PICKLE << " and " <<
          MAX_PICKLE << ": ";
          cin >> pickleNum;
        }

        // make sure burger list has at least one value
        if(burgerCount == NO_BURGERS_IN_LIST)
        {
          cout << "\n" << NO_DELETE_MSG << " No burgers in list to delete\n" 
               << endl;
        }
        // burger not found in array
        else if(!(burgerInArr(pattyNum, baconNum, pickleNum, burgerArr,
        burgerCount)))
        {
          cout << NO_DELETE_MSG << " No burgers with specified "
               << "parameters found in list." << endl;
        }
        // deletion can occur. burger with user specified parameters found
        else
        {
          moveToEnd(pattyNum, baconNum, pickleNum, burgerArr,
          burgerCount);

          // show burger removed
          cout << generateBurgerName(pattyNum, baconNum, pickleNum) 
               << " has been deleted from the list" << endl;

          // decrement counter by one
          burgerCount--;
        }
        
      break;
      }

      // user elects to quit program
      case QUIT :
      {
        // boolean variable quit is set to true to cause program to exit loop
        quit = true;
        break;
      }

      // user selects an option not available on the menu
      default :
      {
        // inform user to only select valid menu options
        cout << "Error. You must only select options " << GEN_BURGER_NAME
        << " through " << QUIT << "." << endl;
        break;
      }
    }

  } while(!quit); // exit when user selects to quit

  // goodbye message
  cout << "\nThank you for using the " << BEG_BURGER_NAME
  << " Burger Name Generator." << " Goodbye!\n" << endl;

  // necessary main function return statement
  return 0;
}
