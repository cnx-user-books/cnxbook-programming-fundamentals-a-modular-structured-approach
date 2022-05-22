//******************************************************
// Filename:    Demo_Compiler_Conversion_Errors.cpp
// Purpose:     Improve your ability to use the IDE
// Purpose:     Demonstrate compiler conversion errors
//              when converting source code to object code
// Author:      Ken Busbee; © 2008 Kenneth Leroy Busbee
// Date:        Dec 31, 2008
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 2.0)
//              http://creativecommons.org/licenses/by/2.0/
//******************************************************
// Directions:  You try compiling and running the program.
// The compiler will stop where it finds the 1st error.
// Read the feed back towards the bottom area of the IDE
// window.  The error message might not always lead to a 
// clear understanding of the problem.
// Look to the comments numbered 1. It will tell you what
// the problem is and how to fix it.  Once fixed, try
// compiling and running the program again.  If it should
// stop again resolve the problem by doing the same steps.
// Do this as many times as needed to resolve all errors.
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;

#define PI 3.1415

// Function Prototypes

//void pause(void);     // 3. Function prototype missing
                        // Remove the // at the beginning of line

// Variables

int    radius = 3       // 1. missing a semi-colon - add one
double answer;

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input - none
  
  // Process 
  
  answer = radias * radius * PI;    // 2. Mispelled identifier
                                    // name. Fix the spelling.
  
  // Output 
  
  cout << "\n\nThe area of a circle with a 6 inch diameter is: ";
  cout << answer;
  
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
