//******************************************************
// Filename:    Demo_Integer_Division_and_Modulus.cpp
// Purpose:     Demonstration integer division and modulus
// Author:      Ken Busbee; © 2008 Kenneth Leroy Busbee
// Date:        Dec 31, 2008
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 2.0)
//              http://creativecommons.org/licenses/by/2.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;

// Function Prototypes

void pause(void);

// Variables

int   silver_dollars = 50;
int   friends;

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input - Test Data = 3

  cout << "\nEnter the number of friends (between 4 and 9) you have -->: ";
  cin >> friends;

  // Process - NOTE: The processing is being done in conjunction 
  //           with the output.                                                              *

  // Output - From Test Data = 16 remainder 2
  
  cout << "\n\nI will give you " << silver_dollars << " silver dollars to divide";
  cout << " between your " << friends << " friends.";
  cout << "\nEach friend will get " << silver_dollars / friends << " silver dollars.";
  cout << "  You will keep " << silver_dollars % friends << " silver dollars.";

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
