//******************************************************
// Filename:    Lab_07_Testing_Shell.cpp
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

double inch_to_cm(double inches);
double feet_to_meters(double feet);
double miles_to_kilometers(double miles);

// Variables

double  hot_dog;
double  driveway_depth;
double  distance_to_work;

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input Test Data - 4.5, 36.75, 7.3            
  
  cout << "\nIn inches, how long is a hot dog? ----->: ";
  cin >> hot_dog;
  cout << "\nIn feet, how long is your driveway? --->: ";
  cin >> driveway_depth;
  cout << "\nIn miles, how far is it to work? --_--->: ";
  cin >> distance_to_work;
  cout << "\n\n";
  
  // Output Test Results - 11.43, 11.2088, 11.753
  
  cout << "\nA hot dog is " << inch_to_cm(hot_dog) << " centimeters long.\n";
  cout << "\nYour driveway is " << feet_to_meters(driveway_depth) << " meters long.\n";
  cout << "\nYour commute is " << miles_to_kilometers(distance_to_work) << " kilometers.\n";

  pause_m();
  
  return 0;
  }

//******************************************************
// inch_to_cm
//******************************************************

double inch_to_cm(double inches)
  {
  return 2.54 * inches;
  }

//******************************************************
// feet_to_meters
//******************************************************

double feet_to_meters(double feet)
  {
  return 0.305 * feet;
  }

//******************************************************
// miles_to_kilometers
//******************************************************

double miles_to_kilometers(double miles)

  {
  return 1.61 * miles;
  }

//******************************************************
// End of Program
//******************************************************
