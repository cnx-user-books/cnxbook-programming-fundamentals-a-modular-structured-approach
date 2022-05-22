//******************************************************
// Filename:    Demo_String_Class.cpp
// Purpose:     Demonstrate string data type
// Covers:      assignment
//              relational operators (equality shown)
//              concatenation or append (the + operator)
//              class member function named: length
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Mar 19, 2009
// Updated:     Apr 17, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>   
#include <string>         // Needed for the string items
using namespace std;

// Function Prototypes

void pause(void);

// Variables

string  professor_last_name   = "Busbee";
string  professor_first_name  = "Kenneth";
string  professor_middle_name = "Leroy";
string  professor_full_name;
string  user_last_name;

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "Enter your last name -->: ";
  cin >> user_last_name;

  if (professor_last_name == user_last_name)
    {
    cout << "\nYou must be an 'A' student.\n";
    }
  else
    {
    cout << "\nOur last names are not the same.\n";
    }

  professor_full_name = professor_first_name + " " + professor_middle_name + " " + professor_last_name;

  cout << "\nThe professor's full name is: --->: " << professor_full_name;

  cout << "\n\nsizeof operator does not work correctly: ----> " << sizeof professor_last_name;
  cout << "\n\nThe class member function of length works: --> " << professor_last_name.length();
  
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
