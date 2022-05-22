//******************************************************
// Filename:    Demo_Nested_For_Loops.cpp
// Purpose:     Nested Control Structures - for loops
//              12 by 12 Multiplication Table
// Comments:    Includes a user defined delay function
//              to allow students to see it process
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Mar 18, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
#include<iomanip>               // needed for the setw
#include<ctime>                 // needed for delay function
using namespace std;

// Function Prototypes

void pause(void);
void delay(int tenths_second);

// Constants

#define DELAY_IN_TENTHS 5       // change the value as needed

// Variables

int  across;
int  down;

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "Multiplication Table\n\n";

  // The top line 

  cout << "      ";
  delay(DELAY_IN_TENTHS);                    // call delay
  for(across=1; across<13; across++)
    {
    cout << setw(4) << across << " |";
    delay(DELAY_IN_TENTHS);                  // call delay
    }
  cout << endl;

  // The second line of dashes

  cout << "      ";
  delay(DELAY_IN_TENTHS);                    // call delay
  for(across=1; across<13; across++)
    {
    cout << "------";
    delay(DELAY_IN_TENTHS);                  // call delay
    }
  cout << endl;

  //  The next 12 rows - Note: nested for loops

  for(down=1; down<13; down++)
    {
    cout << setw(4) << down << " !";         // The row label
    delay(DELAY_IN_TENTHS);                  // call delay
    for(across=1; across<13; across++)       // The row contents 
      {
      cout << setw(4) << down*across << " |";
      delay(DELAY_IN_TENTHS);                // call delay    
      }
    cout << endl;
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
// delay
//******************************************************

void delay(int tenths_second)
  {
  clock_t mark_the_time = clock(); // long int, 1000's of seconds
  
  while(clock() < (mark_the_time + (tenths_second * 100)));
  
  return;
  }

//******************************************************
// End of Program
//******************************************************
