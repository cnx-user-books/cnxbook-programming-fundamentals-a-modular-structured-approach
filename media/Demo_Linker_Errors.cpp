//******************************************************
// Filename:    Demo_Linker_Errors.cpp
// Purpose:     Improve your ability to use the IDE
// Purpose:     Demonstrate linker errors
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
// stop again you have introduced the error into the 
// program.  Download the original source code and try
// again.
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
  
  answer = radius * radius * PI;
  
  // Output 
  
  cout << "\n\nThe area of a circle with a 6 inch diameter is: ";
  cout << answer;
  
  pause();

  return 0;
  }

//******************************************************
// pause
//******************************************************

/*  1. This starts a comment area and in effect is as if
the pause function has not been defined.  The prototype
and call are present but the linker software can not find 
the function definintion.  Eliminate these five lines and
the line below with the asterisk and slash

void pause(void)
  {
  cout << "\n\n";
  system("PAUSE");
  cout << "\n\n";
  return;
  }

*/ 

//******************************************************
// End of Program
//******************************************************
