//******************************************************
// Filename:    Demo_Parameter_Passing.cpp
// Purpose:     Demonstrate Passing by Reference
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Apr 15, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;

// Function Prototypes

void pass_by_reference(int &thing1, char &thing2, double &thing3);
void pause(void);

// Variables

int     age   = 26;
char    grade = 'B';
double  money = 2.34;

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "\nThe integer age ------->: " << age;
  cout << "\nThe character grade --->: " << grade;
  cout << "\nThe double money ------>: " << money;
  
  pass_by_reference(age, grade, money);

  cout << "\nThe integer age ------->: " << age;
  cout << "\nThe character grade --->: " << grade;
  cout << "\nThe double money ------>: " << money;

  pause();
  return 0;
  }

//******************************************************
// pass_by_reference
//******************************************************

void pass_by_reference(int &thing1, char &thing2, double &thing3)
  {
  cout << "\n\n**** The function starts. ****\n";
  cout << "\nEnter the new age ----->: ";
  cin >> thing1;
  cout << "\nEnter the new grade --->: ";
  cin >> thing2;
  cout << "\nEnter the new money --->: ";
  cin >> thing3;
  cout << "\n**** The function ends. ****\n";
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
