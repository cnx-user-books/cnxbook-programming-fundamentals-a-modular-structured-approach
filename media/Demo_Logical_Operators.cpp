//******************************************************
// Filename:    Demo_Logical_Operators.cpp
// Purpose:     Demonstrate the three logical operators
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Mar 3, 2009
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

  cout << "\nLogical and, where  7 < 15 && 8 > 3  is: " << (x < 15 && y > 3) << "   which is true";
  cout << "\nLogical and, where  7 > 15 && 8 > 3  is: " << (x > 15 && y > 3) << "   which is false";
  cout << "\nLogical and, where  7 < 15 && 8 < 3  is: " << (x < 15 && y < 3) << "   which is false";
  cout << "\nLogical and, where  7 > 15 && 8 < 3  is: " << (x > 15 && y < 3) << "   which is false";
  cout << "\n";
  cout << "\nLogical or,  where  7 < 8 || 3 == 4  is: " << (x < y || 3 == 4) << "   which is true";     
  cout << "\nLogical or,  where  7 > 8 || 3 == 3  is: " << (x > y || 3 == 3) << "   which is true";     
  cout << "\nLogical or,  where  7 < 8 || 3 == 3  is: " << (x < y || 3 == 3) << "   which is true";     
  cout << "\nLogical or,  where  7 > 8 || 3 == 4  is: " << (x > y || 3 == 4) << "   which is false";     
  cout << "\n";
  cout << "\nLogical not, where  ! (7 <= 8)       is: " << !(x <= y) << "   which is false";
  cout << "\nLogical not, where  ! (7 >= 8)       is: " << !(x >= y) << "   which is true";

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
