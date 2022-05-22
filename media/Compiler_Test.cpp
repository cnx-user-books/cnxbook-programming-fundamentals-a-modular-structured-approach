//******************************************************
// Filename:    Compiler_Test.cpp
// Purpose:     Average the ages of two people
// Comment:     Main idea is to be able to 
//              debug and run a program on your compiler.
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Jan 5, 2009
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

int     age1;
int     age2;
double  answer;

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input	
  cout << "\nEnter the age of the first person --->: ";
  cin >> age1;
  cout << "\nEnter the age of the second person -->: ";
  cin >> age2;

  // Process
  answer = (age1 + age2) / 2.0;

  // Output
  cout << "\nThe average of their ages is -------->: ";
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
