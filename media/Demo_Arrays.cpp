//******************************************************
// Filename:    Demo_Arrays.cpp
// Purpose:     Demonstrate Single Dimension Arrays
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Apr 4, 2009
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

int   ages[5]  = {49,48,26,19,16};
char  grades[] = {'A','F','C','B','W','A'};

int   x;          // Used as a flag to control for loops

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "\nThe original ages:" << endl;
  for(x = 0; x < 5; x++)
    {
    cout << ages[x] << endl;
    }

  cout << "\n\nThe third person had a birthdate, what is their new age ->: ";
  cin >> ages[2];

  cout << "\n\nThe revised ages:" << endl;
  for(x = 0; x < 5; x++)
    {
    cout << ages[x] << endl;
    }

  pause();

  cout << "\n\nThe grades for 6 students:" << endl;
  for(x = 0; x < sizeof grades / sizeof grades[0]; x++)
    {
    cout << grades[x] << endl;
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
