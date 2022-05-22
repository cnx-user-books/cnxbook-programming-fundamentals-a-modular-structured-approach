//******************************************************
// Filename:    Demo_Pre_Processor_Compiler_Errors.cpp
// Purpose:     Improve your ability to use the IDE
// Purpose:     Demonstrate pre-processor compiler errors
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

#include <ioxstream>     // 1. Missing or mispelled include
                         // Fix the spelling to: iostream
using namespace std;

#define PI 3.1415

// Function Prototypes

void pause(void);

// Variables - none

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input - none
  
  // Process - none
  
  // Output 
  
  cout << "\n\nThe area of a circle with a 6 inch diameter is: ";
  cout << 3 * 3 * PIE;   // 2. Wrong PIE not spelled correctly
                         // Change it to PI so the #define can
                         // complete it's pre-processor task.

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
