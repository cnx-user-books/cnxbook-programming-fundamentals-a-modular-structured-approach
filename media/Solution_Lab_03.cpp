//******************************************************
// Filename: Solution_Lab_03.cpp
// Purpose:  Paint Your House Calculations
// Author:   Ken Busbee; © 2008 Kenneth Leroy Busbee
// Date:     Dec 24, 2008
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

void pause(void);

// Variables

double  length;
double  width;
double  height;
double  price_gal_paint;
int     coverage_gal_paint;
double  total_area;
int     total_gal_paint;
double  total_cost;

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input - Test Data = 100, 40, 10, 28.49, 250
  //       - Alternate Test Data = 20, 30, 10, 12.34, 350

  cout << "\nEnter the length of the house in feet --->: ";
  cin >> length;
  cout << "\nEnter the width of the house in feet ---->: ";
  cin >> width;
  cout << "\nEnter the height of the house in feet --->: ";
  cin >> height;
  cout << "\nEnter the price of a gallon of paint ---->: ";
  cin >> price_gal_paint;
  cout << "\nEnter the coverage of a gallon of paint ->: ";
  cin >> coverage_gal_paint;

  // Process

  total_area = (length * height * 2) + (width * height * 2);
  total_gal_paint = total_area / coverage_gal_paint + 0.9999;
  total_cost = total_gal_paint * price_gal_paint;

  // Output - Predicted Results From Test Data = 12, 341.88
  //          Alternate Test DAta Results = 3, 37.02

  cout << "\n";
  cout << "\nThe total gallons of paint needed is ---->: ";
  cout << total_gal_paint;
  cout << "\nThe total cost is ----------------------->: ";
  cout << total_cost;

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
