//******************************************************
// Filename: Solution_Lab_01_with_Program_Control.cpp
// Purpose:  Example of Modularization for Program Control
// Author:   Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:     Jan 2, 2009
// Comment:  Modified from Lab 01 assignment
// See Also: Solution_Lab_01_Hierarchy_Chart.jpg
//******************************************************
// Solution source code files are provided by the 
// instructor to each individual student as needed.
// Students are not to share these files with any other
// student, even those taking the course.
// Not now, not later, not ever.  Don't share them.
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

int     weight1;
int     weight2;
int     weight3;
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
  cout << "\nEnter the weight of the first person --->: ";
  cin >> weight1;
  cout << "\nEnter the weight of the second person -->: ";
  cin >> weight2;
  cout << "\nEnter the weight of the third person --->: ";
  cin >> weight3;
  return;
  }

//******************************************************
// process data
//******************************************************

void process_data(void)
  {
  answer = (weight1 + weight2 + weight3) / 3.0;
  return;
  }

//******************************************************
// show results
//******************************************************

void show_results(void)
  {
  cout << "\nThe average of their weights is -------->: ";
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
