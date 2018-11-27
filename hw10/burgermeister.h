// Programmers: ADAM FORESTIER, DANIEL MONEY    Date: December 5, 2018
// File: customer.cpp
// Purpose: This file contains the header information for the 
//          burgermeister class.

#ifndef BURGERMEISTER_H
#define BURGERMEISTER_H
#include <string>
#include "burger.h"
using namespace std;

// burgermeister constants
const float MEISTER_STARTING_MONEY = 100;
const short DEATH_PAYMENT = 35;
const short SICK_PAYMENT = 5;
const short BURGERMEISTER_SEAT = 15;

// burgermeister class

/*
Description: The function burgermeister() allows for the initialization
of an object of a burger class by directly entering a name as an argument.
Pre-Condition: None.
Post-Condition: An object of burgermeister class has been initialized.
*/

/*
Description: Value of member variable isAngry of calling object is returned.
Pre-Condition:None.
Post-Condition: Boolean value of whether or not burger meister is angry is
returned.
*/

/*
Description: The overload of the += operator for the burgermeister class allows
for the member variable meister money to be increased.
Pre-Condition: None.
Post-Condition: Member variable meister money is increased.
*/

/*
Description: The function increaseMeisterMoney() increases the value of the
calling object's member variable m_meisterMoney by the amount a burger costs.
Pre-Condition: None.
Post-Condition: Calling object's money amount is increased.
*/

/*
Description: The function increaseMeisterMoney() increases the value of the
calling object's member variable m_meisterMoney by the amount a customer has
remaining.
Pre-Condition: None.
Post-Condition: Calling object's money amount is increased.
*/

/*
Description: The function setMeisterMoney() decreases the meister's money
by the amount passed to it, due to either a contestant vomit or death
Pre-Condition: A short must be passed
Post-Condition: The meister's money is decreased by either the death or sick
payment amount.
*/
/* 
Description: The function setAnger() sets the member variable m_isAngry of the
calling object to true.
Pre-Condition: None.
Post-Condition: Member variable m_isAngry set to true.
*/

/* 
Description:The function resetAnger() sets the member variable m_isAngry of the
calling object to false.
Pre-Condition: None.
Post-Condition: Member variable m_isAngry set to false.
*/

/*
Description: The overload of the -= operator for the burgermeister class allows
for the member variable meister money to be decreased.
Pre-Condition: None.
Post-Condition: Member variable meister money is decreased.
*/

class burgermeister
{
private:
	string m_meisterName;
	float m_meisterMoney;
	bool m_isAngry;

public:
	burgermeister(string mName) : m_meisterName(mName),
		m_meisterMoney(MEISTER_STARTING_MONEY), m_isAngry(false) {}
	bool getAnger() const { return m_isAngry; }
	void increaseMeisterMoney(const burger krustyBurger);
	void increaseMeisterMoney(const float money);
	void setAnger() { m_isAngry = true; return; };
	void resetAnger() { m_isAngry = false; return; }
	void operator+=(const float money);
	void operator-=(const float money);
};

#endif
