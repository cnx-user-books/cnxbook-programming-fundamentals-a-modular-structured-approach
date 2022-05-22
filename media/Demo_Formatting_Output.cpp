//******************************************************
// Filename:    Demo_Formatting_Output.cpp
// Purpose:     Demonstrate formatting concepts
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Mar 18, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
#include <iomanip>               // needed for the setw
using namespace std;

// Function Prototypes

void pause(void);

// Variables

int     counter;
double  x;

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "Bad Wrapping with No Vertical Spacing\n\n";
  for(counter = 0; counter < 5; counter++)
    {
    cout << "This is a rambling sentence long enough to cause wrapping.";
    }
  pause();

  cout << "\n\nGood Vertical Spacing with no Wrapping\n\n";
  for(counter = 0; counter < 5; counter++)
    {
    cout << "\nThis is a rambling sentence long enough to cause wrapping.";
    }
  pause();

  cout << "\n\nNice Formatting of Floating-point Values\n\n";
  for(counter = 0, x = 23.456; counter < 5; counter++, x *= 3.345)
    {
    cout << setw(8) << x << endl;
    }
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
