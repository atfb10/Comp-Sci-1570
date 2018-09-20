#include <iostream>
using namespace std;

int main()
{
  const char REPEAT_PROGRAM = 'y';
  const char EXIT = 'n';
  const short AVG_DIVISOR = 3;

  char repeat;
  short firstInput;
  short secondInput;
  short thirdInput;
  short avg;
  short min;
  short max;

  cout << "Welcome to the math 101 program!" << endl;

  do
  {
    cout << "Please enter a whole number: ";
    cin >> firstInput;
    cout << "Please enter a second whole number: ";
    cin >> secondInput;
    cout << "Please enter a final whole number: ";
    cin >> thirdInput;

    if(firstInput < secondInput && firstInput < thirdInput)
      min = firstInput;
    else if(secondInput < firstInput && firstInput < thirdInput)
      min = secondInput;
    else if(thirdInput < firstInput && thirdInput < secondInput)
      min = thirdInput;
    else 
      cout << "Two or more minimum values." << endl;

    if(firstInput > secondInput && firstInput > thirdInput)
      max = firstInput;
    else if(secondInput > firstInput && secondInput > thirdInput)
      max = secondInput;
    else if(thirdInput > firstInput && secondInput > thirdInput)
      max = thirdInput;
    else
      cout << "Two or more maximum values." << endl;

    avg = firstInput + secondInput + thirdInput / static_cast<float>(AVG_DIVISOR);

    cout << "Minimum value = " << min << endl;
    cout << "Maximum value = " << max << endl;
    cout << "Average value = " << avg << endl;

    cout << "Would you like to run this program again? (y/n) ";
    cin >> repeat;
  } while(repeat = REPEAT_PROGRAM);

  cout << "Thank you for using the math 101 program!" << endl;

  return 0;
}