//******************************************************
// Filename:    Demo_Parallel_Speed.cpp
// Purpose:     Demonstration that simulates parallel processing
// Title:       Parallel Speed Demonstration Program
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Mar 13, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;

// Function Prototypes

void display_factorial(int qty_to_display, int delay_in_thousands_second);
// max qty to display about 160 -- use delay to approximate processors

// Function Prototypes for Monitor Functions

void clear_m(void);
void delay_m(int tenths_second);
void pause_m(void);

// Variables - none

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "Parallel Speed Demonstration Program\n\n";
  cout << "Author: Ken Busbee; Copyright 2009 Kenneth Leroy Busbee\n";
  cout << "Licensed by: Kenneth Leroy Busbee under a\n";
  cout << "Creative Commons Attribution License (CC-BY 3.0)";
  pause_m();
  clear_m();
  display_factorial(60, 1000);  // 60 with 1 processor
  pause_m();
  clear_m();
  display_factorial(60, 100);   // 60 with 10 processors
  pause_m();
  clear_m();
  display_factorial(60, 10);    // 60 with 100 processors
  pause_m();

  return 0;
  }

//******************************************************
// display factorial
//******************************************************

void display_factorial(int qty_to_display, int delay_in_thousands_second)
  {
  long double factN = 1;
  cout << "For demonstration purposes let's assume that it takes";
  cout << "\n1 processor 1 second to calculate each factorial number;";
  cout << "\nthus 1 factorial or 1! takes one second, 2! takes two seconds, etc.";
  cout << "\n\nGiven you have " << 1000 / delay_in_thousands_second << " processor(s), ";
  cout << "it takes about " << qty_to_display * delay_in_thousands_second / 1000.0 << " seconds";
  cout << "\nto calculate " << qty_to_display << "! that is " << qty_to_display << " factorial.";
  pause_m();
  for (int i = 1; i < qty_to_display; i++)
    {
    factN *= i;
    delay_m(delay_in_thousands_second);
    cout << factN << "  ";
    }

  return;
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

void delay_m(int thousands_second)
  {
  clock_t mark_the_time = clock(); // long int, 1000's of seconds
  
  while(clock() < (mark_the_time + thousands_second));
  
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
