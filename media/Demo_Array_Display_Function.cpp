//******************************************************
// Filename:    Demo_Array_Display_Function.cpp
// Purpose:     Demonstrate using a function for displaying 
//              the members of an array
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Apr 6, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
#include <iomanip>         // For setw()
using namespace std;

// Function Prototypes

void display_array(int things[], int array_size);
void pause(void);

// Variables

int  ages[]            = {49,48,26,19,16};
int  ages_member_count = sizeof ages / sizeof ages[0];

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "\nThe array using a simple for loop.\n";
  cout << "\n************************************";
  for(int x = 0; x < ages_member_count; x++)
    {
    cout << "\nOffset: " << setw(2) << x;
    cout << " Memeber: " << setw(2) << x+1;
    cout << " value is: " << setw(3) << ages[x];
    }
  cout << "\n************************************";

  cout << "\n\nThe array calling the function.\n";
  display_array(ages, ages_member_count);
  
  pause();
  return 0;
  }

//******************************************************
// display_array
//******************************************************

void display_array(int things[], int array_size)
  {

  cout << "\n************************************";
  for (int i = 0; i < array_size; i++)
    {
    cout << "\nOffset: " << setw(2) << i;
    cout << " Memeber: " << setw(2) << i+1;
    cout << " value is: " << setw(3) << things[i];
    }
  cout << "\n************************************";

  return;
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
