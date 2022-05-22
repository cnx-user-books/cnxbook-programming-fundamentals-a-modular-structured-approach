//******************************************************
// Filename:    Lab_08_Testing_Shell.cpp
// Purpose:     To create and test some Specific Task functions
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Jan 2, 2009
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
#include "C:\\Dev-Cpp\\user_library\\udst_monitor.h"

// Function Prototypes

double area_square(double side);
double area_rectangle(double side1, double side2);
double area_circle(double radius);
double area_trapezoid(double base, double top, double height);

// Variables

double  square_room_size;
double  driveway_length;
double  driveway_width;
double  swimming_pool_diameter;
double  trap_bottom;
double  trap_top;
double  trap_height;

//******************************************************
// main
//******************************************************

int main(void)
  {
  // *************************** square
  // Input Test Data - 4.5
  cout << "\nWhat is the length of one of the walls in your square bedroom? -->: ";
  cin >> square_room_size;
  // Output Test Results - 20.25
  cout << "\nYour room is " << area_square(square_room_size) << " square whatevers.\n";
  pause_m();
  clear_m();
  
  // *************************** rectangle
  // Input Test Data - 4.5
  cout << "\nWhat is the length of your driveway? -->: ";
  cin >> driveway_length;
  // Input Test Data - 6.6
  cout << "\nWhat is the width of your driveway? --->: ";
  cin >> driveway_width;
  // Output Test Results - 29.7

  cout << "\nYour driveway is " << area_rectangle(driveway_length, driveway_width) << " square whatevers.\n";
  pause_m();
  clear_m();
  
  // *************************** circle
  // Input Test Data - 13.8
  cout << "\nWhat is the diameter of your circular swimming_pool? -->: ";
  cin >> swimming_pool_diameter;
  // Output Test Results - 149.571
  cout << "\nYour pool is " << area_circle(swimming_pool_diameter / 2) << " square whatevers.\n";
  pause_m();
  clear_m();
  
  // *************************** trapezoid
  // Input Test Data - 12.7
  cout << "\nWhat is the length of the bottom side of your trapezoid? -->: ";
  cin >> trap_bottom;
  // Input Test Data - 9.3
  cout << "\nWhat is the length of the top side of your trapezoid? ----->: ";
  cin >> trap_top;
  // Input Test Data - 4.2
  cout << "\nHow tall is your trapezoid? ------------------------------->: ";
  cin >> trap_height;
  // Output Test Results - 46.2
  cout << "\nYour trapezoid is " << area_trapezoid(trap_bottom, trap_top, trap_height) << " square whatevers.\n";
  pause_m();
  clear_m();
  
  return 0;
  }

//******************************************************
// area_square
//******************************************************

double area_square(double side)
  {
  return side * side;
  }

//******************************************************
// area_rectangle
//******************************************************

double area_rectangle(double side1, double side2)
  {
  return side1 * side2;
  }

//******************************************************
// area_circle
//******************************************************

double area_circle(double radius)
  {
  return 3.14159265 * radius * radius;
  }

//******************************************************
// area_trapezoid
//******************************************************

double area_trapezoid(double base, double top, double height)
  {
  return (base + top) / 2 * height;
  }

//******************************************************
// End of Program
//******************************************************
