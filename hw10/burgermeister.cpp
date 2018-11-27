// Programmers: ADAM FORESTIER, DANIEL MONEY    Date: December 5, 2018
// File: burger.cpp
// Purpose: This file contains the functions for the burgermeister
//          class.

#include "burgermeister.h"
using namespace std;

// overload of the += operator for objects of the burgermeister class
void burgermeister::operator+=(const float money)
{
	m_meisterMoney += money;
	return;
}

// overload of the -= operator for objects of the burgermeister class
void burgermeister::operator-=(const float money)
{
	/*
	If meister's money - money < $0, money stays same
	Otherwise meister loses value of argument passed
	*/
	m_meisterMoney - money < 0 ? m_meisterMoney = m_meisterMoney :
		m_meisterMoney -= money;
	return;
}

// increase the burgermeister's money based upon a customer paying for a burger
void burgermeister::increaseMeisterMoney(const burger krustyBurger)
{
	m_meisterMoney += krustyBurger.getPrice();
}

// increase burgermeister's money based upon a customer hitting him w/ a patty
void burgermeister::increaseMeisterMoney(const float money)
{
	m_meisterMoney += money;
	return;
}
