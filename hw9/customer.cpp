// Programmer: ADAM FORESTIER             Date: November 9, 2018
// File: customer.cpp
// Purpose: This file contains the member functions for the 
//          customer class.


#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "customer.h"
#include "burger.h"
using namespace std;

// overload insertion operator to allow printing of customer
ostream& operator<<(ostream & os, const customer & c)
{
  os << c.m_name << " weighs " << c.m_weight << " lbs," << " has $" << c.m_money
     << ", " << c.m_cholesterolLevel << " IBU " << " and is "  
     << (c.m_isAlive ? "ALIVE." : "DEAD.");

  return os;
}

// default customer constructor
customer::customer()
{
  static short customerLine = 0; // keeps track of which names are already used
  short totalNames = 0;
  string fName, lName;

  // open connection to data file
  ifstream fin("simpson_names.dat");
  ifstream counter("simpson_names.dat");

  // find total number of customer names
  while (counter >> fName)
  {
    totalNames++;
  }

  // total will be 48, because of last names; divide by 2 to get correct number
  totalNames /= 2; 

  // close counter connections
  counter.close();

  // loop until reaching next customer in list or end of list
  for(int i = 0; i <= customerLine; i++)
  {
    fin >> fName;
    fin >> lName;
  }

  // increment by one, to set where next contestent name should be drawn from
  if(customerLine != totalNames)
    customerLine++;
  
  // start naming over if it reaches end of customer list
  else
    customerLine = 0;

  // set customer member variable values
  m_name = fName + " " + lName;
  m_money = (rand() % MAX_MONEY) + MONEY_DIFF;
  m_weight = (rand() % MAX_WEIGHT) + WEIGHT_DIFF;
  m_cholesterolLevel = (rand() % MAX_CHOLESTEROL) + CHOLESTEROL_DIFF;
  m_isAlive = true;

  // close stream
  fin.close();
}

// function to have customer eat burger
void customer::eat(const burger krustyBurger)
{
  // update values of calling object
  setMoney(krustyBurger);
  setWeight(krustyBurger);
  setCholesterol(krustyBurger);
  setLife(krustyBurger);

  return;
}

// customer funds setter
bool customer::setMoney(const burger krustyBurger)
{
  // initialize variables
  const float burgerPrice = krustyBurger.getPrice();
  bool canPurchase = true;

  // check customers wallet balance
  if(m_money == 0)
    canPurchase = false;
  if(m_money - burgerPrice <= 0)
    canPurchase = false;
  else 
    m_money -= burgerPrice;

  return canPurchase;
}

// customer weight setter
void customer::setWeight(const burger krustyBurger)
{
  short weightGain = 0;
  short patty = krustyBurger.getPatties();
  short bacon = krustyBurger.getBacon();
  short pickle = krustyBurger.getPickles();
  bool hasCheese = krustyBurger.getCheese();
  bool hasSauce = krustyBurger.getSauce();

  // calculate the amount of weight a customer has gained from eatimg a burger
  weightGain = FIRST_WT_NUM * (patty * patty) + (SECOND_WT_NUM/THIRD_WT_NUM) *
              (bacon * bacon) - (pickle / FOURTH_WT_NUM);

  // add to weight if burger has cheese and or sauce
  if(hasCheese)
    weightGain += CHEESE_WT_GAIN;
  if(hasSauce)
    weightGain += SAUCE_WT_GAIN;

  // add additional weight to original weight
  m_weight += weightGain;

  return;
}

// customer cholesterol setter
void customer::setCholesterol(const burger krustyBurger)
{
  // initialize variables
  float cholesterolGain = 0;
  short patty = krustyBurger.getPatties();
  short bacon = krustyBurger.getBacon();
  short pickle = krustyBurger.getPickles();

  // calculate cholesterol gain
  cholesterolGain = FIRST_CHOL_NUM * bacon + (PI/SECOND_CHOL_NUM) * patty + 
                    m_weight/((pickle + THIRD_CHOL_NUM)*FOURTH_CHOL_NUM);

  // set new cholesterol gain
  m_cholesterolLevel += cholesterolGain;

  return;
}

// customer life setter
void customer::setLife(const burger krustyBurger)
{
  // initialize variable
  bool isDeadly = krustyBurger.getPathogen();

  // set if customer is alive or not based upon if burger has pathogen
  if(isDeadly)
    m_isAlive = false;
  else
    m_isAlive = true;

  return;
}