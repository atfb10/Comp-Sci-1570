// Programmer: ADAM FORESTIER	   Date: 10/11/2018
// File: math_func.cpp			     Section: E
// Purpose: This file contains the functions to 
//          handle user's integer based inputs, 
//          perform number base conversions, and 
//          ensure and enforce integer base accuracy

#include <iostream>
#include <cmath>
#include "math_func.h"
using namespace std;

// get non-negative integer from user
long getInt()
{
  // initialize variable that needs to be returned
  long userInput;

  // instruct user to give input
   cout << "Please enter an integer inclusively between " << MIN_INT << " and " 
   << MAX_INT << ": ";
   cin >> userInput;

  // make sure user enters valid number
  while(userInput < MIN_INT || userInput > MAX_INT) 
  {
    cout << "Error. Only enter positive numbers less than or equal to " 
    << MAX_INT << ": ";
    cin >> userInput;
  }

   // return user's input
   return userInput;
}

// get a base number from inclusively between 2 and 9
short getBase()
{
  // initialize variable to be returned
  short baseNum;

  // instruct user to give input
  cout << "Please enter an integer base inclusively between " << MIN_BASE 
  << " and " << MAX_BASE << ": ";
  cin >> baseNum;

  // make sure user enters valid number
  while(baseNum < MIN_BASE || baseNum > MAX_BASE)
  {
    cout << "Error. Only enter numbers inclusively between " << MIN_BASE 
    << " and " << MAX_BASE << ": ";
    cin >> baseNum;  
  }

  // return the base number n user has selected
  return baseNum;
} 

/* 
See if the integer x is a valid base n number
*/
bool isBase(const long intNum, const short baseNum)
{
  // function constant declarations

  /*
  Find each digit value from right to left by calling functions
  that calculate the digit values.
  This works because, even if there are less than 5 digits, the 
  result will be less than one. Because these variables are of 
  the short type, the decimal will be dropped and will result
  for said variable will be zero.
  */
  const short onesDigit = getOnesDig(intNum);
  const short tensDigit = getTensDig(intNum);
  const short hundredsDigit = getHundredsDig(intNum);
  const short thousandsDigit = getThousandsDig(intNum);
  const short tenThousandsDigit = getTenThousandsDig(intNum);

  // initialize boolean variable to be returned
  bool isBaseNum = false;

  // check to make sure all digits are less than the base number
  if(tenThousandsDigit < baseNum && thousandsDigit < baseNum
  && hundredsDigit < baseNum && tensDigit < baseNum 
  && onesDigit < baseNum)
  {
    // if so, x is base num n
    isBaseNum = true;
  }

  // return whether or not the number is a base number
  return isBaseNum;
}

// assign new, minimum valid base if number is not already a valid base
void validBase(const long intNum, short & baseNum)
{
  // function constant declarations

  /*
  Find each digit value from right to left by calling functions
  that calculate the digit values.
  This works because, even if there are less than 5 digits, the 
  result will be less than one. Because these variables are of 
  the short type, the decimal will be dropped and will result
  for said variable will be zero.
  */
  const short onesDigit = getOnesDig(intNum);
  const short tensDigit = getTensDig(intNum);
  const short hundredsDigit = getHundredsDig(intNum);
  const short thousandsDigit = getThousandsDig(intNum);
  const short tenThousandsDigit = getTenThousandsDig(intNum);

  /* 
  Check each digit from right to left. 
  If digit exceeds, set new base to be one greater than the digit value
  */
  if(onesDigit >= baseNum)
    baseNum = onesDigit + 1;
  if(tensDigit >= baseNum)
    baseNum = tensDigit + 1;
  if(hundredsDigit >= baseNum)
    baseNum = hundredsDigit + 1;
  if(thousandsDigit >= baseNum)
    baseNum = thousandsDigit + 1;
  if(tenThousandsDigit >= baseNum)
    baseNum = tenThousandsDigit + 1;
 
  // Return statement
  return;
}

// generate random values to replace digits greater than or equal to base
void validInt(long & intNum, const short baseNum)
{
  /*
  Find each digit value from right to left by calling functions
  that calculate the digit values.
  This works because, even if there are less than 5 digits, the 
  result will be less than one. Because these variables are of 
  the short type, the decimal will be dropped and will result
  for said variable will be zero.
  */
  short onesDigit = getOnesDig(intNum);
  short tensDigit = getTensDig(intNum);
  short hundredsDigit = getHundredsDig(intNum);
  short thousandsDigit = getThousandsDig(intNum);
  short tenThousandsDigit = getTenThousandsDig(intNum);

  // check if digit exceeds or equals base. If so, randomly generate new digit
  if(onesDigit >= baseNum)
    onesDigit = randomNumber(baseNum);
  if(tensDigit >= baseNum)
    tensDigit = randomNumber(baseNum);
  if(hundredsDigit >= baseNum)
    hundredsDigit = randomNumber(baseNum);
  if(thousandsDigit >= baseNum)
    thousandsDigit = randomNumber(baseNum);
  if(tenThousandsDigit >= baseNum)
    tenThousandsDigit = randomNumber(baseNum);
  
  // set the new integer value
  intNum = onesDigit;
  intNum += tensDigit * TENS_DIGIT_MULT;
  intNum += hundredsDigit * HUND_DIGIT_MULT;
  intNum += thousandsDigit * THOUS_DIGIT_MULT;
  intNum += tenThousandsDigit * TEN_K_DIGIT_MULT;

  // return statement
  return;
}

// Convert number in its current base to the base 10 value
long decVal(const long intNum, const short baseNum)
{ 
  /*
  Find each digit value from right to left by calling functions
  that calculate the digit values.
  This works because, even if there are less than 5 digits, the 
  result will be less than one. Because these variables are of 
  the short type, the decimal will be dropped and will result
  for said variable will be zero.
  */
  const short onesDigit = getOnesDig(intNum);
  const short tensDigit = getTensDig(intNum);
  const short hundredsDigit = getHundredsDig(intNum);
  const short thousandsDigit = getThousandsDig(intNum);
  const short tenThousandsDigit = getTenThousandsDig(intNum);

  // initialize variable to be returned
  long decimalValue;

  /* 
  add up the values of all digits taken to power of ten
  once they have been converted to base ten.
  This is done by taking digit place times the power of 
  the number base with the exponent ranging from 4 - 0.
  This meets the criteria of 5 digits or less, because
  4, 3, 2, 1, 0 is 5 digits
  */
  decimalValue = 
  (tenThousandsDigit * pow(baseNum, TEN_K_DIGIT_2_DEC_EXPONENT)) +
  (thousandsDigit * pow(baseNum, THOUSAND_DIGIT_2_DEC_EXPONENT)) + 
  (hundredsDigit * pow(baseNum, HUNDREDS_DIGIT_2_DEC_EXPONENT)) +
  (tensDigit * pow(baseNum, TENS_DIGIT_2_DEC_EXPONENT)) + 
  (onesDigit * pow(baseNum, ONES_DIGIT_2_DEC_EXPONENT));

  // return the decimal value
  return decimalValue;
}

// get value of ones digit in integer x
short getOnesDig(const long intNum)
{
  return intNum % ONE_DIGIT_MOD;
}

// get value of tens digit in integer x
short getTensDig(const long intNum)
{
  return (intNum % TWO_DIGIT_MOD) / TWO_DIGIT_DIVIDENT;
}

// get value of hundreds digit in integer x
short getHundredsDig(const long intNum)
{
  return (intNum / THREE_DIGIT_DIVIDENT) % THREE_DIGIT_MOD;
}

// get value of thousands digit in integer x
short getThousandsDig(const long intNum)
{
  return (intNum % FOUR_DIGIT_MOD) / FOUR_DIGIT_DIVIDENT;
}

// get value of thousands digit in integer x
short getTenThousandsDig(const long intNum)
{
  return intNum / FIVE_DIGIT_DIVIDENT;
}

// generate random number greater than or equal to 0 and less than a max number
short randomNumber(const short maxNum)
{
  /* 
  Return a random number less than the base number. 
  Modulate by 10 to get range of 0 - 10, subtract to leave only zero remaining
  Add the max number to make that the new range, then subtract 1 to ensure 
  random number is at least 1 less than base
  */ 
  return rand() % maxNum; 
}
