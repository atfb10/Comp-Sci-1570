// Programmer: Adam Forestier		Date: 09/06/18
// File: hw2.cpp					Section: 1E
// Purpose: To calculate the likelihood of heart attack
//          based upon user's eating statistics at Krusty Burger,
//          and to compute the number of miles the user must run
//          to mitigate the negative health effects of eating at
//          this establishment.

#include <iostream>
using namespace std;

int main()
{
	// Constant Declarations
    const float AQF = 5.6;
    const float KBMF = 19.7;

    // Variable Declarations
    short burgerCount;
    short fryCount;
    short milkshakeCount;
    short queueLineLength;
    float chanceOfHeartAttack;
    short marathonCount;
    float milesAfterMarathons;
    float milesToSaveLife;

    // empty line for readability on linux machines
    cout << endl;

    // Greet the user
    cout << "\t\tHello, welcome to the Krusty Burger Heart Risk Calculator!" << endl;

    // User Inputs
    cout << "\nPlease enter the following inputs to receive your free Krusty health analysis." << endl;
    cout << "Total Krusty Burgers Eaten: ";
    cin >> burgerCount;
    cout << "Total Krusty Fry Orders Eaten: ";
    cin >> fryCount;
    cout << "Total Krusty Milkshakes Eaten: ";
    cin >> milkshakeCount;
    cout << "Total Number of People in Line: ";
    cin >> queueLineLength;

    // Calculations based upon user input

    // check if user ordered at least one of each item
    if (burgerCount == 0 || fryCount == 0 || milkshakeCount == 0)
    {
        chanceOfHeartAttack =(burgerCount + fryCount) * (static_cast<float>(milkshakeCount) / (queueLineLength + 1));
    }     
    else
    {
      chanceOfHeartAttack = (burgerCount + fryCount) * (static_cast<float>(milkshakeCount) / (queueLineLength + 1)) + AQF;
    }

    /*
     Calculate marathon plus marathon remainder, miles under 26, to save user's life.
     Note: Per assignment instructions, marathon distance has been rounded to 26 
     */
    milesToSaveLife = chanceOfHeartAttack * KBMF;
    marathonCount = milesToSaveLife / 26;
    milesAfterMarathons = milesToSaveLife - (marathonCount * 26);

    // Output calculations and data to user
    cout << "\nFor Krusty Burger eating inputs:" << endl;
    cout << "\t" << burgerCount << " burgers" << endl;
    cout << "\t" << fryCount << " fries" << endl;
    cout << "\t" << milkshakeCount << " milkshakes" << endl;
    cout << "\t" << queueLineLength << " people in queue" << endl;

    // Check if user ate anything at Krusty Burger
    if (burgerCount == 0 && fryCount == 0 && milkshakeCount == 0) 
    {
        cout << "\nYou have elected to not eat anything at Krusty Burger. Your cardiovascular health thanks you." << endl;
    } 
    else 
    {
        cout << "\nYour chance of heart attack is " << chanceOfHeartAttack << "%." << endl;
        cout << "\nYou need to run " << marathonCount << " marathons plus " << milesAfterMarathons << " miles to save your life!" << endl;
    }   

    // Exit message
    cout << "\nThank you for using the Krusty Burger Heart Risk Calculator, have a nice day!\n" << endl;

    // Necessary return to end program
    return 0;
}