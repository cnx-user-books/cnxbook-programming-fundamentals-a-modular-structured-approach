//******************************************************
// Filename:    Lab_12a.cpp
// Purpose:     Case Control Structure using nested if then else
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Mar 7, 2009 - Revised: Mar 13, 2010
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

int  miles;

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "\nEnter in whole miles the distance to grandma's house -->: ";
  cin >> miles;
  cout << "\n";

  if(miles == 110)
    {
    cout << "\nYou can drive 55 mph and be there in 2 hours.";
    }
  else
    {
    if(miles == 20)
      {
      cout << "\nYou are about 30 minutes to grandma's house.";
      }
    else
      {
      if(miles == 700)
        {
        cout << "\nIt takes a day to get to grandma's house.";
        }
      else
        {
        cout << "\nYou did not enter 110, 20 or 700.  Too Bad!";
        }
      }
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
