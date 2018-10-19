// Programmer: ADAM FORESTIER	   Date: 10/22/2018
// File: burger_name_funcs.h	   Section: E
// Purpose: This file contains the header information
//          for the hw7.cpp file and burger_name_funcs.cpp
//          file. Global constants are defined, structs are
//          defined, and function prototypes with their descriptions
//          are included.

#ifndef BURGER_NAME_FUNCS_H
#define BURGER_NAME_FUNCS_H
using namespace std;

// global constants
const string BEG_BURGER_NAME = "Krusty";
const string END_BURGER_NAME = "Burger";
const short GEN_BURGER_NAME = 1;
const short PRINT_BURGER_LIST = 2;
const short DELETE_BURGER_NAME = 3;
const short QUIT = 4;
const short MAX_TOPPING = 4; // 4 so that the range of toppings will be 0-3
const short NO_PATTY_GENERATED = 0;
const string ONE_PATTY = "Single";
const string TWO_PATTIES = "Double";
const string THREE_PATTIES = "Triumph";
const string NO_BACON = "Health-Master";
const string ONE_BACON = "Bacon";
const string TWO_BACON = "Wilbur";
const string THREE_BACON = "Klogger";
const string NO_PICKLE = "Tasteless";
const string ONE_PICKLE = "Pickly";
const string TWO_PICKLES = "Garden-Fresh";
const string THREE_PICKLES = "Kermit";
const string SPECIAL_VEGGIE_BURGER = "Krusty Veggie Burger";
const string SPECIAL_MEAT_BURGER = "Krusty Koronary Burger";
const short MIN_PATTY = 1;
const short MID_PATTIES = 2;
const short MAX_PATTIES = 3;
const short MIN_BACON = 0;
const short LOWER_MID_BACON = 1;
const short UPPER_MID_BACON = 2;
const short MAX_BACON = 3;
const short MIN_PICKLE = 0;
const short LOWER_MID_PICKLE = 1;
const short UPPER_MID_PICKLE = 2;
const short MAX_PICKLE = 3;
const short SPECIAL_MEATY_BURGER = 6;
const short BURGER_ARRAY_SIZE = 37;
const short MAX_ARRAY_INDEX = 36;
const short NO_BURGERS_IN_LIST = 0;
const string NO_DELETE_MSG = "Burger deletion cannot occur.";
const string DELETE_INPUT_INSTRUCT = "Please Enter Number of ";

// struct definitions

/*
Structure for a krusty burger.
Burger type needs name, patty, bacon and pickle count.
*/
struct burger
{
  string m_name;
  short m_patties;
  short m_baconOz;
  short m_pickles;
};

// function prototypes

/*
Description: The function <<() overloads the insertion
operator to allow for outputting of the defined burger structure.
Pre-Condition: The stream passed must be connected.
Post-Condition: << Operator is overloaded to be able to output burger type.
*/
ostream & operator <<(ostream & os, const burger & b);

/*
Description: The function generateBurgerName() takes in arguments for number
of patties, bacon ounces, and pickles; based upon these arguments, a string
type is returned that refers to the burger's generated name
Pre-Condition: The argument pattyInp must be a value between 1 and 3, the
argument baconInp must be a value between 0 and 3, and the argument pickleInp
must be a value between 0 and 3
Post-Condition: Burger name is returned.
*/
string generateBurgerName(short pattyInp, short baconInp, short pickleInp);

/*
Description: The function sort() sorts an array of strings alphabetically
using bubble sort
Pre-Condition: Argument Len must be less than or equal to the array size.
Post-Condition: The string array is sorted alphabetically.
*/
void sort(burger burgers[], const short len);

/*
Description: The function exists() checks to see if a burger name already
exists in an array of burgers. If it does, it returns true, otherwise returns
false.
Pre-Condition: Argument Len must be less than or equal to the array size.
Post-Condition: True is returned if the argument name exists in the array
argument of burgers[], otherwise false is returned.
*/
bool exists(const string name, const burger burgers[], const short len);

/*
Description: The function printBurgers() prints an array of the type burger
to the console.
Pre-Condition: Argument Len must be less than or equal to the array size.
Post-Condition: Array of the type burger is printed to the console.
*/
void printBurgers(const burger burgers[], const short len);

/*
Description: The function burgerInArr() checks to see if a burger is an array
burgers, based upon the following arguments: pattyCount, baconCount, and
pickleCount. If so true is returned; if not found false is returned.
Pre-Condition: Argument Len must be less than or equal to the array size.
Post-Condition: True is returned if a burger with the inputted parameters
exists in the burger array parameter with length of the len parameter.
Otherwise false is returned.
*/
bool burgerInArr(const short pattyCount, const short baconCount,
const short pickleCount, const burger burgers[], const short len);

/*
Description: The function moveToEnd() removes a burger to the end of an array
of burgers and shifts the rest of the array over, based upon the following 
arguments: pattyCount, baconCount, and pickleCount.
Pre-Condition: Argument Len must be less than or equal to the array size.
Post-Condition: Burger is deleted if a burger with the inputted parameters
exists in the burger array parameter with length of the len parameter.
*/
void moveToEnd(const short pattyCount, const short baconCount,
const short pickleCount, burger burgers[], const short len);

/*
Description: The function randNum() pseudo-randomly generates a number between
0 and 3 and returns the generated value.
Pre-condition: None.
Post-Condition: Generated number between 0 and 3 is returned.
*/
short randomIngredient();

/*
Description: The function randPatty() pseudo-randomly generates a number between
1 and 3 and returns the generated value.
Pre-condition: None.
Post-Condition: Generated number between 1 and 3 is returned.
*/
short randPatty();

/*
Description: The function printMenu() prints a menu of options for the user
onto the console.
Pre-Condition: None.
Post-Condition: Menu of options is printed onto console
*/
void printMenu();


#endif
