// Programmer: ADAM FORESTIER          Date: 10/03/18
// File: hw5.cpp
// Purpose: This file includes the functions necessary
//          calculate maximum burger profit based upon 
//          two variable input by the user

#include <iostream>
#include <cmath>
using namespace std;

// global constant declarations
const char QUIT = 'n';
const short MIN_ANIMAL_PARTS = 0;
const short MIN_ANIMAL_SPECIES = 0;
const string PROGRAM_TITLE = "Krusty Burger Profit Maximizer Calculator";
const string BEG_ERR_MSG = "Error.";
const string QUIT_OPTIONS = "(y/n): ";

// function invocations and descriptions

/*
Description: The function lowerAnimalPartCount() returns a positive integer 
value, greater than zero from the user, that represents the lower boundary 
of animal parts.
Pre-Condition: None.
Post-Condition: Returned the value of the lower boundary for number 
of animal parts.
*/
short lowerAnimalPartCount();

/*
Description: The function upperAnimalPartCount() returns a positive integer 
value, greater than zero from the user, that represents the upper boundary 
of animal parts.
Pre-Condition: None.
Post-Condition: Returned the value of the upper boundary for number 
of animal parts.
*/
short upperAnimalPartCount();

/*
Description: The function lowerAnimalSpeciesCount() returns a positive integer 
value, greater than zero from the user, that represents the lower boundary 
of animal types.
Pre-Condition: None.
Post-Condition: Returned the value of the lower boundary for number 
of animal types.
*/
short lowerAnimalSpeciesCount();

/*
Description: The function upperAnimalSpeciesCount() returns a positive integer 
value, greater than zero from the user, that represents the upper boundary 
of animal types.
Pre-Condition: None.
Post-Condition: Returned the value of the upper boundary for number 
of animal types.
*/
short upperAnimalSpeciesCount();

/*
Description: The function calcProfit() computes and returns the estimated
burger profit based upon number of animal parts and number of animal types.
Pre-Condition: The paramaters must both be positive and greater than zero.
Post-Condition: Returned the value of burger profit.
*/
float calcProfit(const short numAnimalParts, const short numAnimalTypes);

/*
Description: The function printProfit() prints a table of number of animal
types input, number of animal parts input, and estimated profit for the burger
to the console screen
Pre-Condition: All of the paramters must be positive and greater than zero.
The second parameter must be greater than or equal to the first parameter and 
the fourth parameter must be greater than or equal to the second paramter.
Post-Condition: The table is outputted to the console screen. 
*/
void printProfit(const short lowerAnimalParts, const short upperAnimalParts, 
const short lowerAnimalSpecies, const short upperAnimalSpecies);

// main function
int main()
{
  // initialize main function variables
  short lowerAnimalPartsNum;
  short upperAnimalPartsNum;
  short lowerAnimalTypeNum;
  short upperAnimalTypeNum;
  char repeatInstruct;

  // force exactly 2 decimal places to be shown
  cout.setf(ios::fixed); 
  cout.setf(ios::showpoint); 
  cout.precision(2); 

  // blank line for readability
  cout << endl;

  // user greeting
  cout << "\t\tWelcome to the " << PROGRAM_TITLE << "!" << endl;

  // loop until user selects to quit by pressing n after rest of program runs
  do
  {
    // blank line for readability
    cout << endl;

    // assign values of functions that gather user input to variables
    lowerAnimalPartsNum = lowerAnimalPartCount();
    upperAnimalPartsNum = upperAnimalPartCount();
    lowerAnimalTypeNum = lowerAnimalSpeciesCount();
    upperAnimalTypeNum = upperAnimalSpeciesCount();

    /* 
    Ensure upper bounds exceed lower bounds.
    if they do not, explain error and give the user option to restart program 
    */
   if(lowerAnimalPartsNum > upperAnimalPartsNum || 
   lowerAnimalTypeNum > upperAnimalTypeNum)
   {
     // error message
     cout << BEG_ERR_MSG << " Lower boundaries must not exceed upper boundaries." <<
     endl;
   }
   // user puts in all correct entries
   else
   {
      // blank line for readability
      cout << endl;

      // improve table appearance 
      cout << "Projected Profit" << endl;
      cout << "----------------" << endl;

      /* 
      call print profit function and pass in animal part and 
      animal type boundary arguments to display results
      */   
      printProfit(lowerAnimalPartsNum, upperAnimalPartsNum, lowerAnimalTypeNum,
      upperAnimalTypeNum);
    } 

    // Ask user if they would like to run program again, or quit. 
    cout << "\nWould you like to run the " << PROGRAM_TITLE  << 
    " Again? " << QUIT_OPTIONS;
    cin >> repeatInstruct;
  } while(repeatInstruct != QUIT); // exit loop when user enters 'n'

  // goodbye message
  cout << "\nThank you for using the " << PROGRAM_TITLE << " Goodbye!\n" 
  << endl;

  // Necessary main function return statement
  return 0;
}

// function to gather user's input for lower bound number of animal parts
short lowerAnimalPartCount()
{
  // initialize variable to hold lower bound number of animal parts
  short animalParts;

  // ask for user input
  cout << "Please enter lower boundary of animal parts: ";
  cin >> animalParts;

  // make sure user enters greater than 0 animal parts
  while(animalParts <= MIN_ANIMAL_PARTS)
  {
    cout << BEG_ERR_MSG << " Only enter a positive number of animal parts: ";
    cin >> animalParts;
  }

  // return the part count 
  return animalParts;
}

// function to gather user's input for upper bound number of animal parts
short upperAnimalPartCount()
{
  // initialize variable to hold lower bound number of animal parts
  short animalParts;

  // ask for user input
  cout << "Please enter upper boundary of animal parts: ";
  cin >> animalParts;

  // make sure user enters greater than 0 animal parts
  while(animalParts <= MIN_ANIMAL_PARTS)
  {
    cout << BEG_ERR_MSG << " Only enter a positive number of animal parts: ";
    cin >> animalParts;
  }

  // return the part count 
  return animalParts;
}

// function to gather user's input for lower bound number of animal types
short lowerAnimalSpeciesCount()
{
  // initialize variable to hold lower bound number of animal types
  short animalSpecies;

  // ask user for input
  cout << "Please enter lower boundary of animal types: ";
  cin >> animalSpecies;
  
  // make sure user enters greater than 0 animal species
  while(animalSpecies <= MIN_ANIMAL_SPECIES)
  {
    cout << BEG_ERR_MSG << " Only enter a positive number of animal parts: ";
    cin >> animalSpecies;
  }

  // return the number of different types of animals
  return animalSpecies;
}

// function to gather user's input for upper bound number of animal types
short upperAnimalSpeciesCount()
{
  // initialize variable to hold upper bound number of animal types
  short animalSpecies;

  // ask user for input
  cout << "Please enter upper boundary of animal types: ";
  cin >> animalSpecies;
  
  // make sure user enters greater than 0 animal species
  while(animalSpecies <= MIN_ANIMAL_SPECIES)
  {
    cout << BEG_ERR_MSG << " Only enter a positive number of animal parts: ";
    cin >> animalSpecies;
  }

  // return the number of different types of animals
  return animalSpecies;
}

/*
function that calculates the values of Krusty's profit function
using the arguments for number of animal parts and number of different
types of animals and plugging them into Professor Frink's model

Model: f(X,Y) = X * e^(-Y * Y)/2
Where:
x = animal part count
y = different type of animal count
*/
float calcProfit(const short numAnimalParts, const short numAnimalTypes)
{
  // calculate the dividend of the exponent 
  const short logExponentDividend = (-1 * numAnimalTypes) * (numAnimalTypes);

  // return the value calculated by the formula
  return numAnimalParts * exp((logExponentDividend)/
  static_cast<float>(numAnimalParts));
}

/* 
Function to output both user input and profit results in a table
*/
 void printProfit(const short lowerAnimalParts, const short upperAnimalParts, 
 const short lowerAnimalSpecies, const short upperAnimalSpecies)
{
  /*
  outer loop controls is boundaries of type of animals
  loop from lower boundary until upper boundary is met
  */
  for(int i = lowerAnimalSpecies; i <= upperAnimalSpecies; i++)
  {
    /*
    inner loop controls is boundaries of animal parts
    loop from lower boundary until upper boundary is met
    then increment outer loop
    */
    for(short j = lowerAnimalParts; j <= upperAnimalParts; j++)
    {
      /*
      print the animal part count, animal type count, and profit
      based upon the mathmatical model given and calculated for in
      the calcProfit function
      */
      cout << i << " " << j << " $" << calcProfit(j, i);
      cout << endl; // put next line of data on new row
    }
  } 

  // function return statement
  return;
}