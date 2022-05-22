//******************************************************
// Filename:    Demo_Logic_Errors.cpp
// Purpose:     Improve your ability to use the IDE
// Purpose:     Demonstrate logic errors
// Author:      Ken Busbee; © 2008 Kenneth Leroy Busbee
// Date:        Dec 31, 2008
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 2.0)
//              http://creativecommons.org/licenses/by/2.0/
//******************************************************
// Directions:  You try compiling and running the program.
// Read the directions within the program when it runs.
// Look to the comments numbered 1. It will tell you what
// the problem is and how to fix it.  Onced fixed, try
// compiling and running the program again.
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;

#define PI 3.1415

// Function Prototypes

void pause(void);

// Variables

int    radius = 3;
double answer;

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input - none
  
  // Process 
  
  answer = radius * 2 * PI;    // 1. The formula should be
                               // PI r squared  NOT
                               // PI 2r
                               // Replace the 2 with radius

  // Output 
  
  cout << "\n\nThe area of a circle with a 6 inch diameter is: ";
  cout << answer;
  cout << "\n\nWell it compiles and links but the answer is wrong!";
  cout << "\nRemember your test data - 3 radius is 28.2735 area.";
  cout << "\nHit the enter key, review the source code and fix ";
  cout << "the problem.";
  
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
