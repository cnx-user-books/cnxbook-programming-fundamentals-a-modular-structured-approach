//******************************************************
// Filename:    Monitor_Testing_Shell.cpp
// Purpose:     To create and test some Specific Task functions
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Jan 7, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************
// Comments: These functions will be placed into a user
// header file so that they may be referenced by any
// program that the user creates.
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;
#include <ctime>

// Function Prototypes

void clear_m(void);
void delay_m(int tenths_second);
void pause_m(void);

// Variables

int  age;

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "\nEnter your age --->: ";
  cin >> age;
  pause_m();
  clear_m();
  cout << "\nEnter your age --->: ";
  cin >> age;
  delay_m(25);
  
  return 0;
  }

//******************************************************
// clear_m
//******************************************************

void clear_m(void)
  {
  system("CLS");
  return;
  }

//******************************************************
// delay_m
//******************************************************

void delay_m(int tenths_second)
  {
  clock_t mark_the_time = clock(); // long int, 1000's of seconds
  
  while(clock() < (mark_the_time + (tenths_second * 100)));
  
  return;
  }

//******************************************************
// pause_m
//******************************************************

void pause_m(void)
  {
  cout << "\n\n";
  system("PAUSE");
  cout << "\n\n";
  return;
  }

//******************************************************
// End of Program
//******************************************************
