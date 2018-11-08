// Programmer: ADAM FORESTIER             Date: November 9, 2018
// File: burger.h
// Purpose: This file contains the header information for the burger
//          class.

#ifndef BURGER_H
#define BURGER_H
using namespace std;

// global constants related to burgers
const string CONTEST_NAME = "Springfield Krusty Burger Eating Contest";
const string BEG_BURGER_NAME = "Krusty";
const string END_BURGER_NAME = "Burger";
const short MAX_TOPPING = 5; // 4 so that the range of toppings will be 0-4
const short TOPPING_OR_NO = 2; 
const short GEN_PATHOGEN = 10;
const short NO_PATTY_GENERATED = 0;
const string ONE_PATTY = "Single";
const string TWO_PATTIES = "Double";
const string THREE_PATTIES = "Triumph";
const string FOUR_PATTIES = "Bloater";
const string NO_BACON = "Health-Master";
const string ONE_BACON = "Bacon";
const string TWO_BACON = "Wilbur";
const string THREE_BACON = "Klogger";
const string FOUR_BACON = "Heart-Stopper";
const string NO_PICKLE = "Tasteless";
const string ONE_PICKLE = "Pickly";
const string TWO_PICKLES = "Garden-Fresh";
const string THREE_PICKLES = "Kermit";
const string FOUR_PICKLES = "Dill";
const string CHEESE_INCLUDED = "cheesy";
const string SAUCE_INCLUDED = "saucy";
const string SPECIAL_VEGGIE_BURGER = "Krusty Veggie Burger";
const string SPECIAL_MEAT_BURGER = "Krusty Koronary Burger";
const string SPECIAL_MAXED_BURGER = "Krusty Nasty Patty";
const short MIN_PATTY = 1;
const short LOWER_MID_PATTIES = 2;
const short UPPER_MID_PATTIES = 3;
const short MAX_PATTIES = 4;
const short MIN_BACON = 0;
const short LITTLE_BACON = 1;
const short LOWER_MID_BACON = 2;
const short UPPER_MID_BACON = 3;
const short MAX_BACON = 4;
const short MIN_PICKLE = 0;
const short LITTLE_PICKLE = 1;
const short LOWER_MID_PICKLE = 2;
const short UPPER_MID_PICKLE = 3;
const short MAX_PICKLE = 4;
const short SPECIAL_MEATY_BURGER = 6;
const short SPECIAL_TOTAL_BURGER = 12;
const short DEADLY_PATHOGEN = 9;
const float PATTY_COST = .75;
const float BACON_COST = .50;
const float PICKLE_COST = .25;
const float BUN_PRICE = .50;
const float CHEESE_PRICE = .25;
const float SAUCE_PRICE = .10;

// burger class

/*
Description: The function generateBurgerName() creates a burger name
based off the values of a burger's member variables and returns the name.
Pre-Condition: None.
Post-Condition: Name of a burger is returned.
*/

/*
Description: The function calcBurgerPrice() calculates a burger's value
based upon the value's of its member functions and returns the value.
Pre-Condition: None
Post-Condition: Price of burger is returned.
*/

/*
Description: The first constructor burger() allows a user to initialize the burger
values for patty count, bacon ounce count, pickle count, whether or not it has cheese,
whether or not it has sauce, and whether or not it contains a pathogen. An object of 
the burger class is created as a result.
Pre-Condition: None.
Post-Condition: Burger object is created.
*/

/*
Description: The default constructor burger() initializes a burger object's values
and creates an object of the class burger.
Pre-Condition: None.
Post-Condition: Burger object is created
*/

/*
Description: The function getPatties() gets the value of patties on a burger
and returns that value.
Pre-Condition: None.
Post-Condition: Number of patties is returned.
*/

/*
Description: The function getBacon() gets the value of bacon ounces on a burger
and returns that value.
Pre-Condition: None.
Post-Condition: Number of bacon ounces is returned.
*/

/*
Description: The function getPickles() gets the value of pickles on a burger
and returns that value.
Pre-Condition: None.
Post-Condition: Number of pickles is returned.
*/

/*
Description: The function getCheese() determines whether or not a burger
contains cheese and returns the boolean value as such.
Pre-Condition: None.
Post-Condition: Boolean value of whether or not a burger contains cheese
is returned.
*/

/*
Description: The function getSauce() determines whether or not a burger 
contains sauce and returns the boolean value as such.
Pre-Condition:
Post-Condition: Boolean value of whether or not a burger contains sauce  
is returned.
*/

/*
Description: The function getPrice() gets the value of a burger in terms of 
price and returns that value.
Pre-Condition: None.
Post-Condition: Price of a burger is returned.
*/

/*
Description: The function getPathogen() determines whether or not a burger 
contains a pathogen and returns the boolean value as such.
Pre-Condition: None.
Post-Condition: Boolean value of whether or not a burger contains a pathogen
is returned.
*/

/*
Description: The overload of the insertion operator allows for a burger
object to be output.
Pre-Condition: None.
Post-Condition: An object of the burger class may be output.
*/

class burger
{
  private:
    short m_burger;
    short m_bacon;
    short m_pickle;
    bool m_hasCheese;
    bool m_hasSauce;
    bool m_hasPathogen;
    float m_price;
    string m_name;
    string generateBurgerName();
    float calcBurgerPrice();

  public: 
    burger(const short burger, const short baconOz, const short pickle, 
           const bool containsCheese, const bool containsSauce, const bool
           containsPathogen); 
    burger();
    short getPatties() const {return m_burger; }
    short getBacon() const { return m_bacon; }
    short getPickles() const { return m_pickle; }
    bool getCheese() const { return m_hasCheese; }
    bool getSauce() const { return m_hasSauce; }
    float getPrice() const { return m_price; }
    bool getPathogen() const { return m_hasPathogen; }
    friend ostream& operator<<(ostream & os, const burger & b);
};

#endif