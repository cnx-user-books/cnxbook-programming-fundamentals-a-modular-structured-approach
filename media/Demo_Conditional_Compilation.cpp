//******************************************************
// Filename:    Demo_Conditional_Compilation.cpp
// Purpose:     Demonstrate condidtional compilation using test 
//              data imbeded into a program that does 
//              calculations for painting a house
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Apr 17, 2009; Revised: May 6, 2009; 
//              Updated: May 11, 2010
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;

// Function Prototypes

void pause(void);

//  Conditional Compilation Items

#define DEBUG 1                 // 1 for true  (i.e. DEBUG on)
                                // 0 for false (i.e. DEBUG off)
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
  // Input
  
  #if DEBUG 
    cout << "\n***** DEBUG Code ** Enter a length of 100";
  #endif
  cout << "\nEnter the length of the house in feet --->: ";
  cin >> length;
  
  #if DEBUG 
    cout << "\n***** DEBUG Code ** Enter a width of 40";
  #endif
  cout << "\nEnter the width of the house in feet ---->: ";
  cin >> width;
  
  #if DEBUG 
    cout << "\n***** DEBUG Code ** Enter a height of 10";
  #endif
  cout << "\nEnter the height of the house in feet --->: ";
  cin >> height;
  
  #if DEBUG 
    cout << "\n***** DEBUG Code ** Enter a price of 28.49";
  #endif
  cout << "\nEnter the price of a gallon of paint ---->: ";
  cin >> price_gal_paint;
  
  #if DEBUG 
    cout << "\n***** DEBUG Code ** Enter a coverage of 250";
  #endif
  cout << "\nEnter the coverage of a gallon of paint ->: ";
  cin >> coverage_gal_paint;

  // Process

  total_area = (length * height * 2) + (width * height * 2);
  #if DEBUG 
    cout << "\n***** DEBUG Code ** The total area should be: 2800 and it is: " << total_area;
    pause();
  #endif
  
  total_gal_paint = total_area / coverage_gal_paint + 0.9999;
  #if DEBUG 
    cout << "\n***** DEBUG Code ** The total gallons of paint should be: 12 and it is: " << total_gal_paint;
    pause();
  #endif
  
  total_cost = total_gal_paint * price_gal_paint;
  #if DEBUG 
    cout << "\n***** DEBUG Code ** The total cost should be: 341.88 and it is: " << total_cost;
    pause();
  #endif

  // Output

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
