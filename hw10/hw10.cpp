// Programmers: ADAM FORESTIER, DANIEL MONEY    Date: December 5, 2018
// File: hw10.cpp
// Purpose: This file contains the main function that will simulate
//          a Krusty burger eating contest in Springfield

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include "burger.h"
#include "customer.h"
#include "burgermeister.h"
using namespace std;

// driver code
int main()
{
	// initialize variables and objects for the main function
	burgermeister krusty = burgermeister("Krusty");
	customer contestants[NUM_CONTESTANTS];
	short custCounter = 0;
	short roundCount = 1;
	bool endContest = false;
	burger krustyBurger;
	string vomitNoises[4] = { "BLARGHHGAGGHH", "GLURPPUGGHGH", "BLERHCHHH",
													 "BAAGHHHLRRRLRLR" };
	short j, k;
	burger toToss;
	short burgersEaten;
	bool someoneVomited=false;
	bool firstAlive=false;
	customer winner;
	short ctr=0;

	// seed randon number generator
	srand(time(NULL));

	// add citizens of Springfield to the contest
	for (short i = 0; i < NUM_CONTESTANTS; i++)
	{
		contestants[custCounter] = customer();
		custCounter++;
	}

	// greet user
	cout << endl;
	cout << "\t\tWelcome to the " << CONTEST_NAME << "!" << endl<<endl;
	cout << "\t\tThe Contestants are..." << endl;
	
	// DO NOT RUN UNTIL END CONTEST IS SET TO TRUE!!!!!!!!!!!!!!!!!!!!
	// continue the contest until no one can eat another burger
	do
	{
		cout<<endl<<"Current status of contestants:" << endl;
    for (int i = 0; i < NUM_CONTESTANTS; i++)
		{
		cout << contestants[i] << endl;
		}

		cout << endl << endl <<"-------------------- ROUND #" << roundCount 
		     <<" ---------------------"<<endl<<endl;

		burgersEaten=0;

		// loop through each customer in contest
		for (short i = 0; i < NUM_CONTESTANTS; i++)
		{
			// Make sure customer is still in contest
			if (contestants[i].getInContest())
			{
				// make krusty burger for customer
				krustyBurger = burger();

				// make sure the contestent can afford the burger and is in contest
				if (contestants[i].getInContest() && 
					contestants[i].getMoney() > krustyBurger.getPrice())
				{
					// feed the poor sap the burger
					contestants[i].eat(krustyBurger);

                    // increase burgersEaten this round counter by 1
					burgersEaten++;

					// pay krusty for the burger price eaten
					krusty.increaseMeisterMoney(krustyBurger);

					/* 
					If the customer vomited, run the vomit chain simulation
					Variables k and j used to run the array up and down without losing 
					place in the eating phase of the contest
					*/ 
					j = i; 
					k = i;
					
					// Down the array
					while (contestants[k].getVomit() && contestants[k].getLife()
						&& k >= 0)
					{
						someoneVomited=true;
						contestants[k].vomit(vomitNoises);
						contestants[k].resetVomit();
            if (contestants[k].getVomit())
            {
             	krusty -= SICK_PAYMENT;
            }
						k--; // next contestant

						if (k >= 0)
						{
							contestants[k].setVomit();
						}
					}

					/*
					Once vomiting stops, initiate foodfight should the conditions arise
					*/
					if (someoneVomited && k!=-1)
					{
						contestants[k].setInitialToss();
					  someoneVomited=false;

						while(krusty.getAnger() == false && contestants[k].getLife() && 
									contestants[k].getFoodFight())
						{
							/* 
							increase health of contestant and lower money for throwing burger
							pay krusty for burger thrown
							*/
							toToss = burger();
							contestants[k].increaseHealth();
							contestants[k].setMoney(toToss);
							krusty.increaseMeisterMoney(toToss);

							// position of person hit
							short hitPerson = rand() % NUM_CONTESTANTS + RANGE_TO_HIT;

							/*
							If krusty is hit 
							Kick person out of contest
							Give krusty all of their money
							*/
							if(hitPerson == BURGERMEISTER_SEAT)
							{
								krusty.increaseMeisterMoney(contestants[k].getMoney());
								contestants[k].hitKrusty();
								krusty.setAnger();
							}
							// krusty is not hit
							else
							{
								// show who hit who
								cout << "\t\t" << contestants[k].getName() << " hits "  
										<< contestants[hitPerson].getName() << " with a burger!"
										<< endl;

								// set k to hit person
								k = hitPerson;
								/* 
								ensure hit person is still alive for foodfight to continue
								*/
								if(contestants[k].getLife())
								{
									// determine whether or not they choose to throw a burger
									contestants[k].setSubsequentToss();
								}
							}
						}
					}

					/* 
					Reset krusty to not be angry after throwing contestant out and taking
					their money 
					*/
					krusty.resetAnger();

					// at conclusion of foodfight, reset all customers to not toss their 
					// food
					for(short p = 0; p < NUM_CONTESTANTS; p++)
					{
						contestants[p].resetToss();
					}

					// Up the array if puking is still going on
					while (contestants[j].getVomit() && contestants[j].getLife()
						   && j < NUM_CONTESTANTS)
					{
						someoneVomited=true;
						contestants[j].vomit(vomitNoises);
						contestants[j].resetVomit();
            if (contestants[j].getVomit())
            {
              krusty -= SICK_PAYMENT;
            }
						j++; //next contestant

						if (j < NUM_CONTESTANTS)
						{
							contestants[j].setVomit();
						}
					}

					/*
					Once vomiting stops, initiate foodfight should the conditions arise
					*/
					if (someoneVomited && j!=NUM_CONTESTANTS)
					{	
						contestants[j].setInitialToss();

						while(krusty.getAnger() == false && contestants[j].getLife() && 
									contestants[j].getFoodFight())
						{
							/* 
							increase health of contestent and lower money for throwing burger
							pay krusty for burger thrown
							*/
							toToss = burger();
							contestants[j].increaseHealth();
							contestants[j].setMoney(toToss);
							krusty.increaseMeisterMoney(toToss);

							// position of person hit
							short hitPerson = rand() % NUM_CONTESTANTS + RANGE_TO_HIT;

							/*
							If krusty is hit 
							Kick person out of contest
							Give krusty all of their money
							*/
							if(hitPerson == BURGERMEISTER_SEAT)
							{
								krusty.increaseMeisterMoney(contestants[j].getMoney());
								contestants[j].hitKrusty();
								krusty.setAnger();
							}
							// krusty is not hit
							else
							{
								// show who hit who
								cout << "\t\t" << contestants[j].getName() << " hits "  
										<< contestants[hitPerson].getName() << " with a burger!"
										<< endl;

								// set j to hit person
								j = hitPerson;

								/* 
								ensure hit person is still alive for foodfight to continue
								*/
								if(contestants[j].getLife())
								{
									// determine whether or not they choose to throw a burger
									contestants[j].setSubsequentToss();
								}
							}
						}
					}

					/* 
					Reset krusty to not be angry after throwing contestant out and taking
					their money 
					*/
					krusty.resetAnger();

					// at conclusion of foodfight, reset all customers to not toss their 
					// food
					for(short p = 0; p < NUM_CONTESTANTS; p++)
					{
						contestants[p].resetToss();
					}

					// if contestant has died, make krusty pay for funeral and flowers
					if (!(contestants[i].getLife()))
					{
						krusty -= DEATH_PAYMENT;
					}
				}
			}
		}

		roundCount++;

		// end the contest
		if (burgersEaten==0)
		{
			cout<<"No remaining contestants could eat a burger!"<<endl;
			endContest=true;
		}

	} while (!endContest);

	// declare winner
  while (!firstAlive && ctr<NUM_CONTESTANTS) //finds first possible winner
	{
		if (contestants[ctr].getInContest())
		{
			winner=contestants[ctr];
			firstAlive=true;
		}
		ctr++;
	}
	// compares all further possible winners to the first
	for (short i=ctr; i < NUM_CONTESTANTS; i++)
	{
		if (contestants[i].getInContest())
		{
			if (contestants[i].getBurgersEaten()>winner.getBurgersEaten())
			{
				winner = contestants[i];
			}
			else if (contestants[i].getBurgersEaten()==winner.getBurgersEaten())
			{
				if (contestants[i].getWtGain()>winner.getWtGain())
				{
					winner = contestants[i];
				}
			}
		}
	}
	//if no one is still in the contest, outputs that fact
	if (!firstAlive)
	{
		cout<<"No winner declared, all contestants are either dead"
				<<" or kicked out of the contest!" << endl;
	}
	// outputs the winner if there is one
  else
	{
  	cout<<"The winner is: "<<winner.getName()<<endl<<endl;
	}

	// exit message
	cout << "\nThank you for watching the " << CONTEST_NAME << "!"
		<< " We hope to see you again next year." << endl;

	return 0;
}
