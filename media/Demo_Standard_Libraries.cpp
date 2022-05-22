//******************************************************
// Filename:    Demo_Standard_Libraries.cpp
// Purpose:     Demonstrate various standard functions
//              and features from the Standard Library
// Comment:     Note the need for some additional include files
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Jan 7, 2009; Modified: Mar 20, 2010
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>  
using namespace std;
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cstring>

// Function Prototypes

void pause(void);

// Variables

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Output
  cout << "\nThe absolute value of -24 is: ------->: " << abs(-24);
  cout << "\nThe length of my name: Busbee is: --->: " << strlen("Busbee");
  cout << "\nThe square root of 25.4 is: --------->: " << sqrt(25.4);
  cout << "\nThe square of 5.2 is: --------------->: " << exp(5.2);
  cout << "\n";
  cout << "\n==== Output with I/O Manipulators ====" << endl;
  cout << "\nThe absolute value of -24 is: ------->: " << setw(7) << abs(-24);
  cout << "\nThe length of my name: Busbee is: --->: " << setw(7) << strlen("Busbee");
  cout << fixed << setprecision(2);
  cout << "\nThe square root of 25.4 is: --------->: " << setw(10) << sqrt(25.4);
  cout << "\n";
  
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
