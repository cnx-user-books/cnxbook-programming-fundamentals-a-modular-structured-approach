//******************************************************
// Filename:    Lab_17a.cpp
// Purpose:     Conditional Operator Conversions with If Then Else
// Author:      Ken Busbee; © 2009-2010 Kenneth Leroy Busbee
// Date:        Mar 20, 2009, Revised: Jan 13, 2010
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;

// Function Prototypes

void pause(void);

// Variables

int     qty_my_toys = 4;
int     qty_user_toys;

double  body_temp = 98.6;
double  your_temp;

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Item 1 -  if then else to be converted to conditional
  cout << "You are a kid and love your toys.";
  cout << "\nHow many toys do you have? ---->: ";
  cin >> qty_user_toys;
  if (qty_user_toys > qty_my_toys)
    {
    cout << "\nYou have more toys than me.";
    }
  else
    {
    cout << "\nI have at least as many toys as you.";
    }
  pause();

  // Item 2 - conditional to be converted to if then else
  cout << "\nYou are ill and you take your body temperature.";
  cout << "\nWhat is your temperature? ------------------->: ";
  cin >> your_temp;
  your_temp == body_temp ? cout << "\nYou are normal." : cout << "\nYou are sick.";
  pause();
  
  return 0;
  }

//******************************************************
// pause
//******************************************************

void pause(void)
  {
  cout << "\n\n";
  system("PAUSE");
  cout << "\n\n";
  return;
  }

//******************************************************
// End of Program
//******************************************************
