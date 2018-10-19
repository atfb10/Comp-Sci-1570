// Programmer: ADAM FORESTIER	   Date: 10/22/2018
// File: burger_name_funcs.cpp	   Section: E
// Purpose: This file contains functions to generate burger
//          names based upon random ingredient values,
//          add said burgers to an array, display the list
//          of burger names and subsequent ingredients and
//          delete burgers from the list.

#include <iostream>
#include <cstdlib>
#include <string>
#include "burger_name_funcs.h"
using namespace std;

// overload << operator to allow for printing of burger name
ostream & operator <<(ostream & os, const burger & b)
{
  // format output of burgers when printed
  os << b.m_name << endl;
  os << "\t" << b.m_patties << " Patt" << (b.m_patties == 1 ? "y, " : "ies, ")
     << b.m_baconOz << " bacon ounc" << (b.m_baconOz == 1 ? "e, " : "es, ")
     << b.m_pickles << " pickl" << (b.m_pickles == 1 ? "e" : "es")
     << endl;

  // return statement
  return os;
}

// function to create burger name based upon random numbers generated
string generateBurgerName(short pattyInp, short baconInp, short pickleInp)
{
  // initialize burger name variable to return
  string burgerName, pattyName, baconName, pickleName;

  // special meat burger case
  if((pattyInp + baconInp == SPECIAL_MEATY_BURGER) && (pickleInp == MIN_PICKLE
  || pickleInp == LOWER_MID_PICKLE))
  {
    burgerName = SPECIAL_MEAT_BURGER;
  }
  // special veggie burger case
  else if(pickleInp > pattyInp + baconInp)
  {
    burgerName = SPECIAL_VEGGIE_BURGER;
  }
  // normal cases
  else
  {
    // patty cases
    switch(pattyInp)
    {
      case MIN_PATTY :
      {
        pattyName = ONE_PATTY;
        break;
      }
      case MID_PATTIES :
      {
        pattyName = TWO_PATTIES;
        break;
      }
      case MAX_PATTIES :
      {
        pattyName = THREE_PATTIES;
        break;
      }
    }

    // bacon cases
    switch(baconInp)
    {
      case MIN_BACON :
      {
        baconName = NO_BACON;
        break;
      }
      case LOWER_MID_BACON :
      {
        baconName = ONE_BACON;
        break;
      }
      case UPPER_MID_BACON :
      {
        baconName = TWO_BACON;
        break;
      }
      case MAX_BACON :
      {
        baconName = THREE_BACON;
        break;;
      }
    }

    // pickle cases
    switch(pickleInp)
    {
      case MIN_PICKLE :
      {
        pickleName = NO_PICKLE;
        break;
      }
      case LOWER_MID_PICKLE :
      {
        pickleName = ONE_PICKLE;
        break;
      }
      case UPPER_MID_PICKLE :
      {
        pickleName = TWO_PICKLES;
        break;
      }
      case MAX_PICKLE :
      {
        pickleName = THREE_PICKLES;
        break;;
      }
    }

  // concatenate each ingredient name
  burgerName = BEG_BURGER_NAME + " " + pattyName + " " + baconName
  + " " + pickleName + " " + END_BURGER_NAME;
  }

  // return the burger name created
  return burgerName;
}

// function to see if name exists in an array
bool exists(const string name, const burger burgers[], const short len)
{
  // initialize variables
  bool existing = false;
  short i = 0;

  // check if name exists in array, if so, set existing to true
  while(i < len && !existing)
  {
    // name argument equals name in array, then it exists
    if(name == burgers[i].m_name)
      existing = true;

    // increment counter with each pass
    i++;
  }

  // return boolean value
  return existing;
}

// function to sort string burgers by name in a burger array
void sort(burger burgers[], const short len)
{
  // initialize variables for function
  burger temp;
  long comparison;

  // through each index position
  for(int i = 0; i < len; i++)
  {
    // compare current index position to next position
    for(int j = 0; j < len - i - 1; j++)
    {
      // if index value is greater than next index value, swap their positions
      comparison = burgers[j].m_name.compare(burgers[j+1].m_name);
      if(comparison > 0)
      {
        temp = burgers[j];
        burgers[j] = burgers[j + 1];
        burgers[j + 1] = temp;
      }
    }
  }

  // standard function return
  return;
}

// function to print all burgers in a burger array
void printBurgers(const burger burgers[], const short len)
{
  // loop through array of burgers and print each one
  for(int i = 0; i < len; i++)
  {
    cout << burgers[i] << endl;
  }

  // standard function return statement
  return;
}

// function to see if burger exists in array
bool burgerInArr(const short pattyCount, const short baconCount,
const short pickleCount, const burger burgers[], const short len)
{
  // initialize variables
  bool found = false;
  short i = 0;

  // check if burger with ingredient inputs exists in array
  while(i < len && !found)
  {
    if(pattyCount == burgers[i].m_patties && baconCount ==
       burgers[i].m_baconOz && pickleCount == burgers[i].m_pickles)
       {
         found = true;
       }
    i++;
  }

  // return whether or not burger is found
  return found;
}

// function to move specified burger to end of array and shift array
void moveToEnd(const short pattyCount, const short baconCount,
const short pickleCount, burger burgers[], const short len)
{
  burger temp;

  // find the burger to be deleted and move to end
  for(int i = 0; i < len; i++)
  {
    if(pattyCount == burgers[i].m_patties && baconCount ==
       burgers[i].m_baconOz && pickleCount == burgers[i].m_pickles)
       {
         temp = burgers[i];
         burgers[i] = burgers[i + 1];
         burgers[i + 1] = temp;
       }
  }
  
}

// function to generate random numbers for bacon oz and pickle count
short randomIngredient()
{
  return rand() % MAX_TOPPING;
}

// function to generate random numbers for patty count
short randPatty()
{
  // initialize variable to return randomly generated number
  short num = rand() % MAX_TOPPING;

  // make sure there is at least 1 patty on the burger
  while(num == NO_PATTY_GENERATED)
  {
    // continue making random numbers until number other than 0 is generated
    num = rand() % MAX_TOPPING;
  }

  // return the number with value
  return num;
}

// function to print menu onto console for user
void printMenu()
{
  cout << "Options" << endl;
  cout << "-------" << endl;
  cout << "1. Generate Burger Name" << endl;
  cout << "2. Print Burger Name List" << endl;
  cout << "3. Delete Burger Name from List" << endl;
  cout << "4. Quit" << endl;
}