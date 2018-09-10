// Programmer: ADAM FORESTIER          Date: 09/14/2018
// File: hw3.cpp
// Purpose: This file contains the main function to automatically
//          generate a burger name for Krusty based upon a 3
//          digit code he enters. If any of the digits exceeds 3
//          or the first digit is a 0, generate an error message.


#include <iostream>
using namespace std;

int main()
{
    // define consts
    const float PATTY_COST = 0.75;
    const float BACON_COST = 0.50;
    const float PICKLE_COST = .25;
    const float BUN_COST = 0.50;
    ///const short EXIT_CODE = 000;
    const short HEALTH_MASTER = 0;
    const short BACON = 1;
    const short WILBUR = 2;
    const short KLOGGER = 3;
    const short TASTELESS = 0;
    const short PICKLY = 1;
    const short GARDEN_FRESH = 2;
    const short KERMIT = 3;
    /*
     single and double seem redundant, but triple burger has a different name.
     If Krusty decides to change single or double to a fancy name, it can 
     be changed in one location
    */ 
    const short SINGLE_PATTY = 1; 
    const short DOUBLE_PATTY = 2;
    const short TRIPLE_PATTY = 3;    

    // define variables
    short codeDigits;
    short pattyCount;
    short baconOunces;
    short pickleCount;
    float burgerCost;
    string pattyNameResult;
    string baconNameResult;
    string pickleNameResult;    

    // force exactly 2 decimal places to be shown
    cout.setf(ios::fixed); 
    cout.setf(ios::showpoint); 
    cout.precision(2); 

    // greet Krusty. Space added for readability
    cout << endl;
    cout << "\t\tHello Krusty, welcome to the Burger Name Generator!" << endl;

    // ask Krusty for input
    cout << "\nPlease enter a 3 digit number with no digit exceeding 3 to" 
    << " generate a burger name: ";
    cin >> codeDigits;

    // assign patty, bacon and pickle
    pattyCount = codeDigits/100;
    baconOunces = (codeDigits%100)/10;
    pickleCount = codeDigits % 10;

    // continue creating names until user enters exit code
    while(codeDigits != 000)
    {
      // handle incorrect user entry

      // user does not enter patty
      if(pattyCount <= 0)
      {
        cout << "\nError: Krusty does not allow burgers without patties." 
        << " Please enter another code with 1 to 3 in the first digit"
        << " place: ";
        cin >> codeDigits;

        // break loop if user enters exit code
        if(codeDigits == 000)
        {
          break;
        }

        pattyCount = codeDigits/100;
        baconOunces = (codeDigits%100)/10;
        pickleCount = codeDigits % 100;
      }

      // user enters too many patties
      if(pattyCount > 3)
      {
        cout << "\nError: Enter again, with no 1, 2, or 3" 
        << " in second digit place: ";
        cin >> codeDigits;

        // break loop if user enters exit code
        if(codeDigits == 000)
        {
          break;
        }

        pattyCount = codeDigits/100;
        baconOunces = (codeDigits%100)/10;
        pickleCount = codeDigits % 10;
      }

      // user enters too many ounces of bacon
      if(baconOunces > 3)
      {
        cout << "\nError: Enter again, with no 1, 2, or 3" 
        << " in second digit place: ";
        cin >> codeDigits;

        // break loop if user enters exit code
        if(codeDigits == 000)
        {
          break;
        }

        pattyCount = codeDigits/100;
        baconOunces = (codeDigits%100)/10;
        pickleCount = codeDigits % 10;
      }

      // user enters too many pickles
      if(pickleCount > 3)
      {
        cout << "\nError: Enter again, with only 0, 1, 2 or 3 in third"
        << " digit place: ";
        cin >> codeDigits;

        // break loop if user enters exit code
        if(codeDigits == 000)
        {
          break;
        }

        pattyCount = codeDigits/100;
        baconOunces = (codeDigits%100)/10;
        pickleCount = codeDigits % 10;
      }

      // user enters wrong amount of digits
      if(codeDigits > 999 || codeDigits < 100)
      {
        cout << "\nError: Digits must be between 100 - 333. " 
        << "Please enter again: ";
        cin >> codeDigits;

        // break loop if user enters exit code
        if(codeDigits == 000)
        {
          break;
        }

        pattyCount = codeDigits/100;
        baconOunces = (codeDigits%100)/10;
        pickleCount = codeDigits % 10;
      }

      // assign name to burger aspect
      if(pattyCount == SINGLE_PATTY)
      {
        pattyNameResult = "Single";
      }
      else  if(pattyCount == DOUBLE_PATTY) 
      {
        pattyNameResult = "Double";
      }
      else if(pattyCount == TRIPLE_PATTY)
      {
        pattyNameResult = "Triumph";
      }

      // assign name to bacon aspect
      if(baconOunces == HEALTH_MASTER) 
      {
        baconNameResult = "Health-Master";
      }
      else if(baconOunces == BACON) 
      {
        baconNameResult = "Bacon";
      }
      else if(baconOunces == WILBUR)
      {
        baconNameResult = "Wilbur";
      }
      else if(baconOunces == KLOGGER) 
      {
        baconNameResult = "Klogger";
      }

      // assign pickle aspect
      if(pickleCount == TASTELESS)
      {
        pickleNameResult = "Tasteless";
      }
      else if(pickleCount == PICKLY)
      {
        pickleNameResult = "Pickly";
      }
      else if(pickleCount == GARDEN_FRESH)
      {
        pickleNameResult = "Garden-Fresh";
      }
      else if(pickleCount == KERMIT)
      {
        pickleNameResult = "Kermit";
      }

      // find the price of the burger
      burgerCost = (pattyCount * PATTY_COST) + (baconOunces * BACON_COST) +
      (pickleCount * PICKLE_COST) + BUN_COST;

      // determine the statement returned to the user
      if(pickleCount > (pattyCount + baconOunces))
      {
        cout << "\nBurger name = " << "Krusty Veggie Burger" << endl;
      }
      else if(pattyCount + baconOunces == 6 && 
      (pickleCount == 0 || pickleCount == 1))
      {
        cout << "\nBurger name = " << "Krusty Koronary Burger" << endl;
      }
      else 
      {
        cout << "\nBurger name = " << "Krusty "<< pattyNameResult << 
        " " << baconNameResult << " " << pickleNameResult 
        << " burger" << endl;
      }

      // return burger price
      cout << "Burger price = $" << burgerCost << endl;

      /*
        inform user they can keep entering new digit combinations
        Or exit by entering 000
      */
      cout << "\nPlease Enter another 3 digit combination, or 000 to exit" <<
      " the Burger Name Generator: ";
      cin >> codeDigits;   

      // assign patty, bacon and pickle
      pattyCount = codeDigits/100;
      baconOunces = (codeDigits%100)/10;
      pickleCount = codeDigits % 10;
    }

    // user has exited the burger generation process. Goodbye message
    cout << "\nThank you for using the Burger Name Generator. Goodbye!\n\n";

    // necessary return statement
    return 0;
}