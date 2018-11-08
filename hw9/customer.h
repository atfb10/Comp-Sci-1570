// Programmer: ADAM FORESTIER             Date: November 9, 2018
// File: customer.h
// Purpose: This file contains the header information for the 
//          customer class.


#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "burger.h"
using namespace std;

// global constants related to customers
const short MAX_MONEY = 51; // simply add difference to get desired range
const short MAX_WEIGHT = 161;
const short MAX_CHOLESTEROL = 271;
const short MONEY_DIFF = 25;
const short WEIGHT_DIFF = 90;
const short CHOLESTEROL_DIFF = 30;
const float PI = 3.14;

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
Pre-Condition: The stream must be connected.
Post-Condition: A customer object is created and initialized.
*/

/*
Description: The function eat() updates the customer's member variables based
upon the values for the burger parameter's member variables.
Pre-Condition: None.
Post-Condition: Member variables for money, weight, cholesterol, and life are 
updated for an object of the customer class. 
*/

/*
Description: The function setMoney() updates the amount of money a customer has
after eating a burger.
Pre-Condition: Must be called within the eat() function.
Post-Condition: Member variable containing customer's money is set.
*/

/*
Description: The function setMoney() updates the weight of a customer
after eating a burger.
Pre-Condition: Must be called within the eat() function.
Post-Condition: Member variable containing customer's weight is set.
*/

/*
Description: The function setCholesterol() updates the cholesterol of a 
customer after eating a burger.
Pre-Condition: Must be called within the eat() function.
Post-Condition: Member variable containing customer's cholesterol is set. 
*/

/*
Description:The function setLife() updates whether or not a customer is alive
after eating a burger.
Pre-Condition: Must be called within the eat() function.
Post-Condition: Member variable containing whether or not a customer is alive
is set.
*/

/*
Description: The overload of the insertion operator allows for an object 
of the customer class to be output.
Pre-Condition: None.
Post-Condition: Object of the customer class may be output.
*/

class customer 
{
  private:
    string m_name;
    float m_money;
    short m_weight;
    short m_cholesterolLevel;
    bool m_isAlive; 

  public: 
    customer(); // default constructor
    void eat(const burger krustyBurger);
    bool setMoney(const burger krustyBurger);
    void setWeight(const burger krustyBurger);
    void setCholesterol(const burger krustyBurger);    
    void setLife(const burger krustyBurger);
    friend ostream& operator<<(ostream & os, const customer & c);
};

#endif