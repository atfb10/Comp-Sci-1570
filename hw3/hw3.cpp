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
  const short EXIT_CODE = 000; // special value that exits name generator
  const short NO_BACON_BURGER = 0;
  const short ONE_BACON_OZ_BURGER = 1;
  const short TWO_BACON_OZ_BURGER = 2;
  const short THREE_BACON_OZ_BURGER = 3;
  const short NO_PICKLE_BURGER = 0;
  const short ONE_PICKLE_BURGER = 1;
  const short TWO_PICKLE_BURGER = 2;
  const short THREE_PICKLE_BURGER = 3;
  const short SINGLE_PATTY = 1; // Patty cannot be zero
  const short DOUBLE_PATTY = 2;
  const short TRIPLE_PATTY = 3;    

  // define variables
  short codeDigits; // user input for name generation 
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

  // greet Krusty. Blank line added for readability
  cout << endl;
  cout << "\t\tHello Krusty, welcome to the Burger Name Generator!" << endl;

  // continue creating names until user enters exit code
  do
  {
    /*
    This statement will be given to user until they exit the program
    Or incorrectly enter input. After one loop, their will be a message
    above this message to the user, informing them that they may exit
    the program by entering 000.
    */
    cout << "\nPlease enter a 3 digit number with no digit exceeding 3 to" 
    << " generate a burger name: ";
    cin >> codeDigits;

    // calculate and assign patty, bacon and pickle counts
    pattyCount = codeDigits/100;
    baconOunces = (codeDigits%100)/10;
    pickleCount = codeDigits % 10;

    // handle incorrect user entry

    // user does not enter patty, but also doesn't enter exit code
    if(pattyCount <= 0 && baconOunces != 0 && pickleCount != 0)
    {
      // have user re-enter code, with prompt highlighting their error
      cout << "\nError: Krusty does not allow burgers without patties." 
      << " Please enter another code with 1 to 3 in the first digit"
      << " place: ";
      cin >> codeDigits;
      
      // calculate and assign patty, bacon and pickle counts
      pattyCount = codeDigits/100;
      baconOunces = (codeDigits%100)/10;
      pickleCount = codeDigits % 10;
    }

    // user enters too many patties
    if(pattyCount > 3)
    {
      // have user re-enter code, with prompt highlighting their error
      cout << "\nError: Enter again, with only 1, 2, or 3" 
      << " in first digit place: ";
      cin >> codeDigits;
      
      // assign patty, bacon and pickle
      pattyCount = codeDigits/100;
      baconOunces = (codeDigits%100)/10;
      pickleCount = codeDigits % 10;
    }

    // user enters too many ounces of bacon
    if(baconOunces > 3)
    {
      // have user re-enter code, with prompt highlighting their error
      cout << "\nError: Enter again, with only 1, 2, or 3" 
      << " in second digit place: ";
      cin >> codeDigits;

      // calculate and assign patty, bacon and pickle counts      
      pattyCount = codeDigits/100;
      baconOunces = (codeDigits%100)/10;
      pickleCount = codeDigits % 10;
    }

    // user enters too many pickles
    if(pickleCount > 3)
    {
      // have user re-enter code, with prompt highlighting their error
      cout << "\nError: Enter again, with only 0, 1, 2 or 3 in third"
      << " digit place: ";
      cin >> codeDigits;

      // calculate and assign patty, bacon and pickle counts      
      pattyCount = codeDigits/100;
      baconOunces = (codeDigits%100)/10;
      pickleCount = codeDigits % 10;
    }

    // user enters wrong amount of digits
    if(codeDigits > 999 || (codeDigits < 100 && codeDigits > 1))
    {
      // have user re-enter code, with prompt highlighting their error
      cout << "\nError: Digits must be between 100 - 333. " 
      << "Please enter again: ";
      cin >> codeDigits;

      // calculate and assign patty, bacon and pickle counts      
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
    if(baconOunces == NO_BACON_BURGER) 
    {
      baconNameResult = "Health-Master";
    }
    else if(baconOunces == ONE_BACON_OZ_BURGER) 
    {
      baconNameResult = "Bacon";
    }
    else if(baconOunces == TWO_BACON_OZ_BURGER)
    {
      baconNameResult = "Wilbur";
    }
    else if(baconOunces == THREE_BACON_OZ_BURGER) 
    {
      baconNameResult = "Klogger";
    }

    // assign pickle aspect
    if(pickleCount == NO_PICKLE_BURGER)
    {
      pickleNameResult = "Tasteless";
    }
    else if(pickleCount == ONE_PICKLE_BURGER)
    {
      pickleNameResult = "Pickly";
    }
    else if(pickleCount == TWO_PICKLE_BURGER)
    {
      pickleNameResult = "Garden-Fresh";
    }
    else if(pickleCount == THREE_PICKLE_BURGER)
    {
      pickleNameResult = "Kermit";
    }

    /*
    find the price of the burger
    multiply number of patties by patty cost. 
    Add this to bacon ounces multiplied by bacon oz cost.
    Add this to number of pickles multipled by pickle cost
    Finally, add this to the cost of the bun, which accounts 
    for top and bottom (One bun per burger)
    */
    burgerCost = (pattyCount * PATTY_COST) + (baconOunces * BACON_COST) +
    (pickleCount * PICKLE_COST) + BUN_COST;

    // determine the statement returned to the user

    // special case of burger with lots of pickles and little meat
    if(pickleCount >= (pattyCount + baconOunces) && codeDigits > 0)
    {
      cout << "\nBurger name = " << "Krusty Veggie Burger" << endl;
    }

    // special case of person liking max for meats and little to no pickle
    else if(pattyCount + baconOunces == 6 && 
    (pickleCount == 0 || pickleCount == 1))
    {
      cout << "\nBurger name = " << "Krusty Koronary Burger" << endl;
    }

    // normal case, excluding exit code
    else if(codeDigits != 0)
    {
      cout << "\nBurger name = " << "Krusty "<< pattyNameResult << 
      " " << baconNameResult << " " << pickleNameResult 
      << " burger" << endl;
    }

    // return burger price if code digits not equal 0
    if(codeDigits != 0)
    {
      cout << "Burger price = $" << burgerCost << endl;
    }

    /*
    inform user they can keep entering new digit combinations
    Or exit by entering 000 unless they already selected that code
    This prompt will display directly above original message that 
    indicates to the user that they should enter a 3 digit number
    */
    if(codeDigits != 0)
    {
      cout << "\nPlease Enter another 3 digit combination, or 000 to exit" <<
      " the Burger Name Generator.";
    }
  } while(codeDigits != EXIT_CODE); // exit the loop, if user enters exit code

  // user has exited the burger generation process. Show Goodbye message
  cout << "\nThank you for using the Burger Name Generator. Goodbye!\n\n";

  // necessary return statement
  return 0;
}