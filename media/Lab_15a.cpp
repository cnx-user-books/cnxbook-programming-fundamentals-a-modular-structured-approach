//******************************************************
// Filename:    Lab_15a.cpp
// Purpose:     While loop as a Conting Loop
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Mar 20, 2009
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

int  counter;

//******************************************************
// main
//******************************************************

int main(void)
  {
  counter = 0;
  while(counter < 5)
    {
    cout << "\nI like computers! - counter value is: " << counter;
    counter++;
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
