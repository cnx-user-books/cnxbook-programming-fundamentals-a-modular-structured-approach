//******************************************************
// Filename:    Demo_Relational_Operators.cpp
// Purpose:     Demonstrate the six relational operators
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Jan 24, 2009
// Licensed by: Kenneth Leroy Busbee under a Creative Commons Attribution License (CC-BY 2.0)
//              http://creativecommons.org/licenses/by/2.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;

// Function Prototypes

void pause(void);

// Variables

int x = 7;  // Normally this would violate the identifier
int y = 8;  // rule which indicates to make an identifier 
            // name meaningful.  Our identifier names of
            // x and y are acceptable for two reasons.
            //   1. x and y represents any integer value
            //   2. x and y is commonly used in this way
            //      by mathematicians.   

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input - None

  // Process - Done in conjunction with the output

  // Output - The results are prediced in the wording 

  cout << "\nless than,                where  7 < 8     is: " << (x < y) << "   which is true";
  cout << "\ngreater than,             where  7 > 8     is: " << (x > y) << "   which is false";     
  cout << "\nless than or equal to,    where  7 <= 8    is: " << (x <= y) << "   which is true";
  cout << "\ngreater than or equal to, where  7 >= 8    is: " << (x >= y) << "   which is false";
  cout << "\nequality,                 where  7 == 8    is: " << (x == y) << "   which is false";
  cout << "\ninequality,               where  7 != 8    is: " << (x != y) << "   which is true";

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
