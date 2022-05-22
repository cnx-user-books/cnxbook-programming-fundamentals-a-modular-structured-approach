//******************************************************
// Filename:    Monitor_Verify_Header.cpp
// Purpose:     To verify that the header file is working
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Jan 7, 2009; Modified: Mar 17, 2010
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>      // Keep the using namespace std;
using namespace std;     // immediately after the #include <iostream>
#include "C:\\Dev-Cpp\\user_library\\udst_monitor.h"

// Variables

int  age;

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "\nEnter your age --->: ";
  cin >> age;
  pause_m();
  clear_m();
  cout << "\nEnter your age --->: ";
  cin >> age;
  delay_m(25);
  
  return 0;
  }

//******************************************************
// End of Program
//******************************************************
