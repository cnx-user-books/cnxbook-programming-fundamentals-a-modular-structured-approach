//******************************************************
// Filename:    Demo_Data_Type_Conversions.cpp
// Purpose:     Demonstrate demotion with trunction
// Author:      Ken Busbee; © 2008 Kenneth Leroy Busbee
// Date:        Dec 31, 2008
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

int     coverage_gal_paint = 250;
double  total_area = 2800;
int     total_gal_paint;

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input - Provided in the variables (inititalized)
  
  // Process - Note: Processing done as an expression
  //                 in conjunction with the output.
  //                 No demotion nor truncation.

  // Output - Predicted Results From Test Data = 11.2

  cout << "\n";
  cout << "\nThe total gallons of paint needed is ---->: ";
  cout << total_area / coverage_gal_paint;

  pause();
  
  //*************************************************
  // Process - Note: Processing done as an expression
  //                 in conjunction with the output.
  //                 Explicit type conversion.
  
  // Output - Predicted Results From Test Data = 11

  cout << "\n";
  cout << "\nThe total gallons of paint needed is ---->: ";
  cout << (int)(total_area / coverage_gal_paint);

  pause();

  //*************************************************
  // Process - Note: Demotion and Truncation as the value
  //                 of the expression is assigned to the 
  //                 variable.  Implicit type conversion.
  
  total_gal_paint = total_area / coverage_gal_paint;

  // Output - Predicted Results From Test Data = 11

  cout << "\n";
  cout << "\nThe total gallons of paint needed is ---->: ";
  cout << total_gal_paint;

  pause();

  //*************************************************
  // Process - Note: Demotion and Truncation as the value
  //                 of the expression is assigned to the 
  //                 variable, however we added 0.9999 to
  //                 be able to round up to the next full
  //                 gallon of paint.     
  
  total_gal_paint = total_area / coverage_gal_paint + 0.9999;

  // Output - Predicted Results From Test Data = 12

  cout << "\n";
  cout << "\nThe total gallons of paint needed is ---->: ";
  cout << total_gal_paint;

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
