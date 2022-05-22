//******************************************************
// Filename:    Demo_Arithmetic_Assignment.cpp
// Purpose:     Demonstrate assignment and arithmetic assignment
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

int x = 9;  // Normally this would violate the identifier
            // rule which indicates to make an identifier 
            // name meaningful.  Our identifier name of
            // x is acceptable for two reasons.
            //   1. x represents any integer value
            //   2. x is commonly used in this way by
            //      mathematicians.   

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input - None

  // Process - Done in conjunction with the output

  // Output - The results are prediced in the wording - last item is 2 

  cout << "\nassignment,      where x is 9  but x = 12 means x now is: " << (x = 12);
  cout << "\n";
  cout << "\nplus assign,     where x is 12 but x += 9 means x now is: " << (x += 9);
  cout << "\nminus assign,    where x is 21 but x -= 6 means x now is: " << (x -= 6);
  cout << "\nmultiply assign, where x is 15 but x *= 3 means x now is: " << (x *= 3);
  cout << "\ndivide assign,   where x is 45 but x /= 7 means x now is: " << (x /= 7);
  cout << "\nmodulus assign,  where x is 6  but x %= 4 means x now is: " << (x %= 4 );

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
