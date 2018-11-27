// Programmers: ADAM FORESTIER, DANIEL MONEY    Date: December 5, 2018
// File: customer.cpp
// Purpose: This file contains the functions for the 
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
	os << c.m_name << ", " << c.m_weight << " lbs," << ", $" << c.m_money
		<< ", " << c.m_cholesterolLevel << " IBU and is "
		<< (c.m_inContest ? "IN the contest." : "NOT in the contest.");

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
	for (int i = 0; i <= customerLine; i++)
	{
		fin >> fName;
		fin >> lName;
	}

	// increment by one, to set where next contestent name should be drawn from
	if (customerLine != totalNames)
		customerLine++;

	// start naming over if it reaches end of customer list
	else
		customerLine = 0;

	// set customer member variable values
	m_name = fName + " " + lName;
	m_money = (rand() % MAX_MONEY) + MONEY_DIFF;
	m_weight = (rand() % MAX_START_WEIGHT) + WEIGHT_DIFF;
	m_cholesterolLevel = (rand() % MAX_START_CHOLESTEROL) + CHOLESTEROL_DIFF;
	m_isAlive = true;
	m_health = (rand() % MAX_HEALTH_START) + HEALTH_DIFF;
	m_inContest = true;
	m_wtGain = INITIAL_WT_GAIN;
	m_custVomits = false;
	m_tossFood = false;
	m_burgersEaten = 0;

	// close stream
	fin.close();
}

// function to have customer eat burger
void customer::eat(const burger krustyBurger)
{
	// update values of calling object
	setHealth(krustyBurger); // MUST BE FIRST
	setMoney(krustyBurger);
	setWeight(krustyBurger);
	setCholesterol(krustyBurger);
	setLife();
	if (m_isAlive)
	{
		m_health -= BURGER_HEALTH_DECREASE;
	}

	// show what the customer has eaten
	cout << krustyBurger << " has been eaten by: " << m_name;
	if (m_isAlive)
	{ 
		cout<< " and lives!" << endl;
	} 
	else
	{
		cout<<" and DIES!" << endl;
	}

	m_burgersEaten++;
	return;
}

// customer funds setter
bool customer::setMoney(const burger krustyBurger)
{
	// initialize variables
	const float burgerPrice = krustyBurger.getPrice();
	bool canPurchase = true;

	// check customers wallet balance
	if (m_money == 0)
		canPurchase = false;
	else if (m_money - burgerPrice <= 0)
		canPurchase = false;
	else
		m_money -= burgerPrice;


	return canPurchase;
}

// customer weight setter
void customer::setWeight(const burger krustyBurger)
{
	float weightGain = 0;
	short patty = krustyBurger.getPatties();
	short bacon = krustyBurger.getBacon();
	short pickle = krustyBurger.getPickles();
	bool hasCheese = krustyBurger.getCheese();
	bool hasSauce = krustyBurger.getSauce();

	// calculate the amount of weight a customer has gained from eatimg a burger
	weightGain = FIRST_WT_NUM * (patty * patty) + (SECOND_WT_NUM / THIRD_WT_NUM)
			*	(bacon * bacon) - (pickle / FOURTH_WT_NUM);

	// add to weight if burger has cheese and or sauce
	if (hasCheese)
		weightGain += CHEESE_WT_GAIN;
	if (hasSauce)
		weightGain += SAUCE_WT_GAIN;

	// add additional weight to original weight
	m_weight += weightGain;

	return;
}

// customer weight gain setter
void customer::setWtGain(const burger krustyBurger)
{
	float weightGain = 0;
	short patty = krustyBurger.getPatties();
	short bacon = krustyBurger.getBacon();
	short pickle = krustyBurger.getPickles();
	bool hasCheese = krustyBurger.getCheese();
	bool hasSauce = krustyBurger.getSauce();

	// calculate the amount of weight a customer has gained from eatimg a burger
	weightGain = FIRST_WT_NUM * (patty * patty) + (SECOND_WT_NUM / THIRD_WT_NUM) 
			*	(bacon * bacon) - (pickle / FOURTH_WT_NUM);

	// add to weight if burger has cheese and or sauce
	if (hasCheese)
		weightGain += CHEESE_WT_GAIN;
	if (hasSauce)
		weightGain += SAUCE_WT_GAIN;

	// add additional weight to original weight
	m_wtGain += weightGain;

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
	cholesterolGain = FIRST_CHOL_NUM * bacon + (PI / SECOND_CHOL_NUM) * patty +
		m_weight / ((pickle + THIRD_CHOL_NUM)*FOURTH_CHOL_NUM);

	// set new cholesterol gain
	m_cholesterolLevel += cholesterolGain;

	return;
}

// customer life setter
void customer::setLife()
{
	/*
	Check if customer has gained more than 80 lbs in contest
	Check if customer's cholesterol has exceeded more than 300
	Check if customer's health has hit 0 through a myriad of possibilities
	Kill them in these circumstances. Otherwise they survive to another round.
	*/
	if (m_health <= DEATH_HEALTH || m_cholesterolLevel > DEATH_CHOLESTEROL ||
		m_wtGain > DEATH_WT_GAIN)
	{
		m_isAlive = false;
		m_inContest = false;
	}

	return;
}

// determine whether or not customer is in contest
void customer::setInContest(const burgermeister meister)
{
	// if contestant dies or hits Krusty, he is out of contest. Else they remain
	if (!m_isAlive || meister.getAnger())
		m_inContest = false;

	return;
}

// set the contestant's health
void customer::setHealth(const burger krustyBurger)
{
	// initialize likelihood of death or sickness
	short pathogenPotency = (rand() % MAX_HEALTH_START) + HEALTH_DIFF;

	// check if burger has pathogen
	if (krustyBurger.getPathogen())
	{
		/*
		Check if pathogen is stronger than customer's health
		If so, kill them
		*/
		if (m_health <= pathogenPotency)
		{
			m_health = DEATH_HEALTH;
			m_custVomits = false;
		}
		// halve their half and make them vomit
		else
		{
			m_health /= 2;
			m_custVomits = true;
		}
	}

	return;
}



// what happens when contestant vomits
void customer::vomit(const string vomitNoises[])
{
	cout << "\t" << m_name << " vomits! " 
	     << vomitNoises[rand() % VOMIT_NOISE_RANGE] << endl;
	return;
}

// set odds of vomit
void customer::setVomit()
{
	m_custVomits = rand() % VOMIT_CHANCE;
	return;
}

// set odds of customer tossing food
void customer::setInitialToss()
{
	// initialize variable
	short chance = rand() % FOOD_FIGHT_CHANCE;

	// set odds contestant joins foodfight
	if(chance == 0 || chance == 1 || chance == 2)
		m_tossFood = false;
	else
		m_tossFood = true;
	
	return;
}

// set odds of customer tossing food after being hit by food
void customer::setSubsequentToss()
{
	// initialize variable
	short chance = rand() % FOOD_FIGHT_CHANCE;

	// set odds contestant joins foodfight
	if(chance == 0 || chance == 1)
		m_tossFood = false;
	else
		m_tossFood = true;
	
	return;
}
