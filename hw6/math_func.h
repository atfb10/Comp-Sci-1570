// Programmer: ADAM FORESTIER	   Date: 10/11/2018
// File: math_func.h			   Section: E
// Purpose: This file contains the program's 
//          global constants and function prototypes

#ifndef MATH_FUNCT_H
#define MATH_FUNCT_H
using namespace std;

// global constant declarations
const short MIN_INT = 0;
const long MAX_INT = 99999;
const short MIN_BASE = 2;
const short MAX_BASE = 9;
const short MAX_DIGITS = 5;
const short CONVERT_TO_BASE = 10;
const short ENTER_INT = 1;
const short ENTER_BASE_NUM = 2;
const short VERIFY_BASE_NUM = 3;
const short ASSIGN_BASE_NUM = 4;
const short RANDOM_DIGITS_IN_BASE = 5;
const short CONVERT_TO_DEC = 6;
const short EXIT = 7;
const short FIRST_MENU_OPTION = 1;
const short LAST_MENU_OPTION = 7;
const short SEED_INSTRUCTION = 7;

// Consts for creating new random int x of base n
const short TENS_DIGIT_MULT = 10;
const short HUND_DIGIT_MULT = 100;
const short THOUS_DIGIT_MULT = 1000;
const short TEN_K_DIGIT_MULT = 10000;

/*
Consts for dividing and modulating digit values
Five is for the left most digit and decreases from left to right;
meaning ONE_DIGIT const is right most digit
*/
const short FIVE_DIGIT_DIVIDENT = 10000;
const short FOUR_DIGIT_MOD = 10000;
const short FOUR_DIGIT_DIVIDENT = 1000;
const short THREE_DIGIT_MOD = 10;
const short THREE_DIGIT_DIVIDENT = 100;
const short TWO_DIGIT_MOD = 100;
const short TWO_DIGIT_DIVIDENT = 10;
const short ONE_DIGIT_MOD = 10;

// These consts are used for converting number of base n to base 10
const short TEN_K_DIGIT_2_DEC_EXPONENT = 4;
const short THOUSAND_DIGIT_2_DEC_EXPONENT = 3;
const short HUNDREDS_DIGIT_2_DEC_EXPONENT = 2;
const short TENS_DIGIT_2_DEC_EXPONENT = 1;
const short ONES_DIGIT_2_DEC_EXPONENT = 0;

/*
Description: The function getInt() gets integer input from user between
the values 0 and 99999.
Pre-Condition: None.
Post-Condition: Integer value between 0 and 99999 returned.
*/
long getInt();

/*
Description: The function getBase() gets integer input from user between
the values 2 and 9.
Pre-Condition: None.
Post-Condition: Integer value between 2 and 9 returned.
*/
short getBase();

/*
Description: The function isBase() sees if intNum is a base of baseNum
and returns the boolean result of that analysis.
Pre-Condition: Parameter intNum must be between 0 and 99999 and 
paramater baseNum must be between 2 and 9
Post-Condition: Boolean result of whether or not intNum is base of 
baseNum is returned.
*/
bool isBase(const long intNum, const short baseNum);

/*
Description: The function validBase() checks if parameter intNum is a valid
number for base number parameter baseNum. If not, the value of base number
is incremented to be one larger than greatest digit value in parameter intNum
and value is passed to variable passed to parameter intNum.
Pre-Condition:Parameter intNum must be between 0 and 99999 and 
paramater baseNum must be between 2 and 9
Post-Condition: Integer value one greater than largest digit in 
argument intNum is passed by reference to baseNum variable
*/
void validBase(const long intNum, short & baseNum);

/*
Description: The function validInt() checks if parameter intNum is a valid 
number for base number parameter baseNum. If not it generates a new number 
that is a base number of the parameter baseNum.
Pre-Condition: Parameter intNum must be between 0 and 99999 and 
paramater baseNum must be between 2 and 9
Post-Condition: Pseudo-randomly generated integer that is a valid number for 
baseNum is passed by reference to intNum's variable.
*/
void validInt(long & intNum, const short baseNum);

/*
Description: The function decVal() returns the decimal value of 
parameter intNum with base number of parameter baseNum.
Pre-Condition: Parameter intNum must be between 0 and 99999 and 
paramater baseNum must be between 2 and 9. Parameter intNum must be
a valid base number of parameter baseNum
Post-Condition: Decimal value of parameter intNum with base number of 
parameter baseNum is returned
*/
long decVal(const long intNum, const short baseNum);

/*
Description: Returns result of 1's digit from parameter intNum.
Pre-Condition: None.
Post-Condition: Result of 1's digit is returned.
*/
short getOnesDig(const long intNum);

/*
Description: Returns result of 10's digit from parameter intNum.
Pre-Condition: None.
Post-Condition: Result of 10's digit is returned.
*/
short getTensDig(const long intNum);

/*
Description: Returns result of 100's digit from parameter intNum.
Pre-Condition: None.
Post-Condition: Result of 100's digit is returned.
*/
short getHundredsDig(const long intNum);

/*
Description: Returns result of 1000's digit from parameter intNum.
Pre-Condition: None.
Post-Condition: Result of 1000's digit is returned.
*/
short getThousandsDig(const long intNum);

/*
Description: Returns result of 10000's digit from parameter intNum.
Pre-Condition: None.
Post-Condition: Result of 10000's digit is returned.
*/
short getTenThousandsDig(const long intNum);

/*
Description: The function randomNumber() generates a pseudo-number whose base
is that of parameter maxNum
Pre-Condition: The parameter must be between 2 and 9.
Post-Condition: The pseudo-random number generated is returned.
*/
short randomNumber(const short maxNum);

// necessary end statement for header files
#endif
