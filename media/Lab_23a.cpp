//******************************************************
// Filename:    Lab_23a.cpp
// Purpose:     Bank Deposit Change Calculation
// Comments:    To be modified using Conditional Conpilation 
//              for test data
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Apr 17, 2009
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

int     pennies;
int     nickels;
int     dimes;
int     quarters;
double  total_pennies;
double  total_nickels;
double  total_dimes;
double  total_quarters;
double  total_value;

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input 

  cout << "\nEnter the number of pennies you have ---->: ";
  cin >> pennies;
  cout << "\nEnter the number of nickels you have ---->: ";
  cin >> nickels;
  cout << "\nEnter the number of dimes you have ------>: ";
  cin >> dimes;
  cout << "\nEnter the number of quarters you have --->: ";
  cin >> quarters;

  // Process

  total_pennies = pennies * .01;
  total_nickels = nickels * .05;
  total_dimes = dimes * .10;
  total_quarters = quarters * .25;
  total_value = total_pennies + total_nickels + total_dimes + total_quarters;
  
  // Output
  
  cout << "\n"; 
  cout << "\nThe total value of your coins is -------->: ";
  cout << total_value;

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
