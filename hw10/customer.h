// Programmers: ADAM FORESTIER, DANIEL MONEY    Date: December 5, 2018
// File: customer.h
// Purpose: This file contains the header information for the 
//          customer class.


#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "burger.h"
#include "burgermeister.h"
using namespace std;

// global constants related to customers
const short MAX_MONEY = 51; // simply add difference to get desired range
const short MAX_START_WEIGHT = 161;
const short MAX_START_CHOLESTEROL = 271;
const short MAX_HEALTH_START = 100;
const short HEALTH_DIFF = 1;
const short MONEY_DIFF = 25;
const short WEIGHT_DIFF = 90;
const short CHOLESTEROL_DIFF = 30;
const float PI = 3.14;
const short NUM_CONTESTANTS = 15;
const short DEATH_CHOLESTEROL = 300;
const short DEATH_HEALTH = 0;
const short DEATH_WT_GAIN = 80;
const short INITIAL_WT_GAIN = 0;
const short BURGER_HEALTH_DECREASE = 2;
const short VOMIT_NOISE_RANGE = 4;
const short VOMIT_CHANCE = 2;
const short FOOD_FIGHT_CHANCE = 10;
const short HEALTH_INCREASE = 2;
const short RANGE_TO_HIT = 1;

// cholesterol formula constants
const float FIRST_CHOL_NUM = 2.5;
const short SECOND_CHOL_NUM = 2;
const short THIRD_CHOL_NUM = 1;
const short FOURTH_CHOL_NUM = 10;

// weight gain formula constants
const float FIRST_WT_NUM = .5;
const short SECOND_WT_NUM = 1;
const short THIRD_WT_NUM = 8;
const short FOURTH_WT_NUM = 4;
const float CHEESE_WT_GAIN = 1.2;
const float SAUCE_WT_GAIN = 2.1;

// customer class

/*
Description: The default constructor customer() initializes the member variable
values for a customer and creates an object of the class customer.
Pre-Condition: None.
Post-Condition: A customer object is created and initialized.
*/

/*
Description: The function getNAME() gets the string value of customer name
and returns that value
Pre-Condition: None.
Post-Condition: String value of name for the calling object is
returned.
*/

/*
Description: The function eat() updates the customer's member variables based
upon the values for the burger parameter's member variables. It also adds the
cost of the burger to the burgermeister's total balance.
Pre-Condition: None.
Post-Condition: Member variables for money, weight, cholesterol, and life are
updated for an object of the customer class. Member variable m_meisterMoney
updated for the object of the burgermeister class passed as an argument.
*/

/*
Description: The function getLife() gets the monetary value of money they
still have and returns that value.
Pre-Condition: None.
Post-Condition: Floating point value of money for the calling object is
returned.
*/

/*
Description: The function setMoney() updates the amount of money a customer has
after eating a burger.
Pre-Condition: None.
Post-Condition: Member variable containing customer's money is set.
*/

/*
Description: The function setWeight() updates the weight of a customer
after eating a burger.
Pre-Condition: None.
Post-Condition: Member variable containing customer's weight is set.
*/

/*
Description: The function setWtGain() updates the weight the customer has
gained since beginning the contest.
Pre-Condition: None.
Post-Condition: Member variable containing customer's weight gain is set.
*/

/*
Description: The function setCholesterol() updates the cholesterol of a
customer after eating a burger.
Pre-Condition: None.
Post-Condition: Member variable containing customer's cholesterol is set.
*/

/*
Description: The function getLife() gets the boolean value for whether
or not a contestant is alive and returns that value.
Pre-Condition: None.
Post-Condition: Boolean value of life for the calling object is returned.
*/

/*
Description:The function setLife() updates whether or not a customer is alive
after eating a burger.
Pre-Condition: None.
Post-Condition: Member variable containing whether or not a customer is alive
is set.
*/

/*
Description:The function setInContest() updates whether or not a customer is in
the burger eating contest.
Pre-Condition: None.
Post-Condition: Member variable for determining whether or not calling object
remains in the contest is set
*/

/*
Description: The function getBurgersEaten() gets the integer value of how
many burgers a customer has eaten in the contest.
Pre-Condition: None.
Post-Condition: The integer value of number of burgers eaten is returned.
returned.
*/

/*
Description:The function getWtGain() returns the float value of total weight
gained during the course of the contest for the calling customer object
Pre-Conditions: m_wtGain has a valid value
Post-Conditions: m_wtGain is returned
*/

/*
Description: The function getVomit() returns the value of the member variable
m_custVomits.
Pre-Condition: None.
Post-Condition: The value of m_custVomits is returned.
*/

/*
Description: The function setVomit() randomly sets the contestants m_custVomits 
variable to true or false, with a 50% chance of each.
Pre-Condition: None.
Post-Condition: m_custVomits is set to either true or false.
*/

/*
Description: The member variable of the calling object for the name of the 
contestant who vomited is printed to the screen along with a vomit noise.
Pre-Condition: None.
Post-Condition: Individual who vomited along with a noise is printed to console
*/

/*
Description: The function resetVomit() sets m_custVomits to false.
Pre-Condition: None.
Post-Condition: m_custVomits is set to false.
*/

/*
Description: The function getFoodFight() returns boolean value of foodfight.
Pre-Condition: None.
Post-Condition: Member variable m_tossFood's value is returned.
*/

/*
Description: The function setInitialToss() determines whether or not the first 
living customer to be hit with vomit and not vomit, starts a foodfight
Pre-Condition: None.
Post-Condition: Food fight begins or does not begin
*/

/*
Description: The function setInitialToss() determines whether or not the first 
living customer to be hit with vomit and not vomit, starts a foodfight
Pre-Condition: None.
Post-Condition: Food fight begins or does not begin
*/

/*
Description: The function setSubsequentToss() determines whether or not the 
following living customer to be hit with food continue foodfight.
Pre-Condition: None.
Post-Condition: Food continues or does not continue.
*/

/*
Description: The function resetToss() sets m_custVomits to false.
Pre-Condition: None.
Post-Condition: m_tossFood is set to false.
*/

/*
Description: The function increaseHealth() increases the calling objects 
health by 2.
Pre-condition: None
Post-Condition: Calling objects member variable health increased by 2 
*/


/*
Description: The overload of the insertion operator allows for an object
of the customer class to be output.
Pre-Condition: The stream must be connected.
Post-Condition: Object of the customer class may be output.
*/

class customer
{
private:
	string m_name;
	float m_money;
	float m_weight;
	float m_cholesterolLevel;
	bool m_isAlive;
	short m_health;
	bool m_inContest;
	float m_wtGain;
	bool m_custVomits;
	bool m_tossFood;
	short m_burgersEaten;

public:
	customer(); // default constructor
	void eat(const burger krustyBurger);
	string getName() const { return m_name; }
	float getMoney() const { return m_money; }
	bool setMoney(const burger krustyBurger);
	void setWeight(const burger krustyBurger);
	void setCholesterol(const burger krustyBurger);
	short getLife() const { return m_isAlive; }
	void setLife();
	bool getInContest() const { return m_inContest; }
	void setInContest(const burgermeister meister);
	float getWtGain() const {return m_wtGain;}
	short getBurgersEaten() const {return m_burgersEaten;}
	void setWtGain(const burger krustyBurger);
	void setHealth(const burger krustyBurger);
	bool getVomit() { return m_custVomits; }
	void setVomit();
	void vomit(const string vomitNoises[]);
	void resetVomit() { m_custVomits = false; return; }
	bool getFoodFight() { return m_tossFood; }
	void setInitialToss();
	void setSubsequentToss();
	void resetToss() { m_tossFood = false; return; }
	void hitKrusty() { m_inContest = false; m_money = 0; return; }
	void increaseHealth() { m_health += HEALTH_INCREASE; return; }
	friend ostream& operator<<(ostream & os, const customer & c);
};

#endif
