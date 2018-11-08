// Programmer: ADAM FORESTIER             Date: November 9, 2018
// File: hw9.cpp
// Purpose: This file contains the main function that will simulate
//          a Krusty burger eating contest in Springfield

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include "burger.h"
#include "customer.h"
using namespace std;

// driver code
int main()
{
  // seed randon number generator
  srand(time(NULL));

  // Initialize objects of burger and customer classes
  burger firstBurger = burger(); 
  burger secondBurger = burger(3, 2, 1, true, false, true);
  customer firstCustomer = customer();
  customer secondCustomer = customer();

  // greet user
  cout << endl;
  cout << "\t\tWelcome to the " << CONTEST_NAME << "!" << endl;

  // show the burgers created
  cout << firstBurger << endl;
  cout << secondBurger << endl;

  // show the customers created
  cout << firstCustomer << endl;
  cout << secondCustomer << endl;

  // force customers to eat krusty's burgers
  firstCustomer.eat(firstBurger);
  secondCustomer.eat(secondBurger);

  // show the customers after eating the burgers
  cout << firstCustomer << endl;
  cout << secondCustomer << endl;

  // exit message
  cout << "\nThank you for watching the " << CONTEST_NAME << "!"
       << " We hope to see you again next year." << endl;

  return 0;
}