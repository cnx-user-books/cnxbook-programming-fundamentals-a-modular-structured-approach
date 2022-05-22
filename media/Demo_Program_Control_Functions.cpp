//******************************************************
// Filename:    Demo_Program_Control_Functions.cpp
// Purpose:     Example of Modularization for Program Control
// Comment:     Modified from the Compiler_Test program
// See Also:    Demo_Program_Control_Functions_Hierarchy_Chart.jpg
// See Also:    Demo_Program_Control_Functions_Pseudocode.txt
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Jan 6, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;

// Function Prototypes

void get_data(void);
void process_data(void);
void show_results(void);
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
  get_data();
  process_data();
  show_results();

  return 0;
  }

//******************************************************
// get data
//******************************************************

void get_data(void)
  {
  cout << "\nEnter the age of the first person --->: ";
  cin >> age1;
  cout << "\nEnter the age of the second person -->: ";
  cin >> age2;
  return;
  }

//******************************************************
// process data
//******************************************************

void process_data(void)
  {
  answer = (age1 + age2) / 2.0;
  return;
  }

//******************************************************
// show results
//******************************************************

void show_results(void)
  {
  cout << "\nThe average of their ages is -------->: ";
  cout << answer;
  pause();
  return;
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
