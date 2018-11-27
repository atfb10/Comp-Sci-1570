// Programmers: ADAM FORESTIER, DANIEL MONEY    Date: December 5, 2018
// File: burger.cpp
// Purpose: This file contains the functions for the burger
//          class.

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "burger.h"
using namespace std;

// overload insertion operator to allow printing of burger
ostream& operator<<(ostream & os, const burger & b)
{
	// burger output format
	os << b.m_name;

	return os;
}

// default burger constructor
burger::burger()
{
	// function variables
	short numPatty;
	short pathogenVal;

	// randomly generate patty amount ensure there is at least one patty
	numPatty = rand() % MAX_TOPPING;

	while (numPatty == NO_PATTY_GENERATED)
	{
		numPatty = rand() % MAX_TOPPING;
	}

	m_burger = numPatty;

	// randomly assign topping amounts to bacon and pickle
	m_bacon = rand() % MAX_TOPPING;
	m_pickle = rand() % MAX_TOPPING;

	// determine if burger has cheese and or sauce
	m_hasCheese = rand() % TOPPING_OR_NO;
	m_hasSauce = rand() % TOPPING_OR_NO;

	// determine if burger has pathogen. 0-8 = safe, 9 = death
	pathogenVal = rand() % GEN_PATHOGEN;

	if (pathogenVal < DEADLY_PATHOGEN)
		m_hasPathogen = false;
	else
		m_hasPathogen = true;

	// initialize burger name based upon randomly generated burger information
	m_name = generateBurgerName();

	// give price to burger based upon randonly generated burger input
	m_price = calcBurgerPrice();
}

// function to create burger
string burger::generateBurgerName()
{
	// initialize variables
	string burgerName, pattyName, baconName, pickleName;
	short pattyInp = m_burger;
	short baconInp = m_bacon;
	short pickleInp = m_pickle;

	// special meat burger case
	if ((pattyInp + baconInp == SPECIAL_MEATY_BURGER) && (pickleInp == MIN_PICKLE
		|| pickleInp == LOWER_MID_PICKLE))
	{
		burgerName = SPECIAL_MEAT_BURGER;
	}
	// special veggie burger case
	else if (pickleInp > pattyInp + baconInp)
	{
		burgerName = SPECIAL_VEGGIE_BURGER;
	}
	else if ((pickleInp + pattyInp + baconInp) == SPECIAL_TOTAL_BURGER)
	{
		burgerName = SPECIAL_MAXED_BURGER;
	}
	// normal cases
	else
	{
		// patty cases
		switch (pattyInp)
		{
		case MIN_PATTY:
		{
			pattyName = ONE_PATTY;
			break;
		}
		case LOWER_MID_PATTIES:
		{
			pattyName = TWO_PATTIES;
			break;
		}
		case UPPER_MID_PATTIES:
		{
			pattyName = THREE_PATTIES;
			break;
		}
		case MAX_PATTIES:
			pattyName = FOUR_PATTIES;
			break;
		}

		// bacon cases
		switch (baconInp)
		{
		case MIN_BACON:
		{
			baconName = NO_BACON;
			break;
		}
		case LITTLE_BACON:
		{
			baconName = ONE_BACON;
			break;
		}
		case LOWER_MID_BACON:
		{
			baconName = TWO_BACON;
			break;
		}
		case UPPER_MID_BACON:
		{
			baconName = THREE_BACON;
			break;
		}
		case MAX_BACON:
			baconName = FOUR_BACON;
			break;
		}

		// pickle cases
		switch (pickleInp)
		{
		case MIN_PICKLE:
		{
			pickleName = NO_PICKLE;
			break;
		}
		case LITTLE_PICKLE:
		{
			pickleName = ONE_PICKLE;
			break;
		}
		case LOWER_MID_PICKLE:
		{
			pickleName = TWO_PICKLES;
			break;
		}
		case UPPER_MID_PICKLE:
		{
			pickleName = THREE_PICKLES;
			break;
		}
		case MAX_PICKLE:
			pickleName = FOUR_PICKLES;
			break;
		}

		// concatenate each ingredient name to form burger name
		burgerName = BEG_BURGER_NAME + " " + pattyName + " " + baconName
			+ " " + pickleName + " " + (m_hasCheese ? CHEESE_INCLUDED + " " : "")
			+ (m_hasSauce ? SAUCE_INCLUDED + " " : "") + END_BURGER_NAME;
	}

	// return the burger name created
	return burgerName;
}

// calculate a burger's price
float burger::calcBurgerPrice()
{
	// initialize burger cost based upon bun, patties, bacon, and pickles
	float burgerPrice = BUN_PRICE + (PATTY_COST * m_burger) +
		(BACON_COST * m_bacon) + (PICKLE_COST + m_pickle);

	// add to price if cheese or sauce is on burger
	if (m_hasCheese)
		burgerPrice += CHEESE_PRICE;

	if (m_hasSauce)
		burgerPrice += SAUCE_PRICE;

	// return the burger cost
	return burgerPrice;
}