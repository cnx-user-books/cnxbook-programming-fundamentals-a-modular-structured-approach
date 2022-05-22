//******************************************************
// Filename:    Demo_Linear_to_Parallel.cpp
// Purpose:     Demonstration that converts a linear problem to a parallel solution
// Title:       Linear to Parallel Calculator
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

void clear_m(void);
void pause_m(void);

// Variables 

char  do_it_again;
int   in_years;         // max 67
int   in_days;          // max 364 
int   in_hours;         // max 23
int   in_minutes;       // max 59
int   qty_processors;   // max 1,000,000
int   total_seconds;
int   seconds_for_task;
int   new_years;
int   new_days;
int   new_hours;
int   new_minutes;
int   new_seconds;
int   interium_calc;

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "Linear to Parallel Calculator\n\n";
  cout << "Author: Ken Busbee; Copyright 2009 Kenneth Leroy Busbee\n";
  cout << "Licensed by: Kenneth Leroy Busbee under a\n";
  cout << "Creative Commons Attribution License (CC-BY 3.0)";
  pause_m();
  do
    {
    clear_m();
    cout << "Linear to Parallel Calculator";
    cout << "\n\nHow long will it take one person to do a task?";
    cout << "\nYou will be prompted for yesrs, days, hours and minutes.";
    cout << "\n\nTask years (max 67) -----> ";
    cin >> in_years;
    cout << "\nTask days (max 364) -----> ";
    cin >> in_days;
    cout << "\nTask hours (max 23) -----> ";
    cin >> in_hours;
    cout << "\nTask minutes (max 59) ---> ";
    cin >> in_minutes;
    cout << "\nHow many people will work as a group (max 10000000) -> ";
    cin >> qty_processors;
      
    total_seconds = in_years * 31557600 + in_days * 86400 + in_hours * 3600 + in_minutes * 60;
    seconds_for_task = total_seconds / qty_processors;
    new_years = seconds_for_task / 31557600;
    new_days = (seconds_for_task - new_years * 31557600) / 82800;
    interium_calc = (seconds_for_task - new_years * 31557600) % 82800;
    new_hours = interium_calc / 3600;
    interium_calc = interium_calc % 3600;
    new_minutes = interium_calc / 60;
    new_seconds = interium_calc % 60;
    
    cout << "\n\nThe task will take a total of " << total_seconds << " seconds.";
    cout << "\nBut, with " << qty_processors << " people working as a group, it will";
    cout << "\ntake " << seconds_for_task << " seconds for the group to complete the task, or";
    cout << "\n";
    cout << "\n  Years: " << new_years;
    cout << "\n   Days: " << new_days;
    cout << "\n  Hours: " << new_hours;
    cout << "\nMinutes: " << new_minutes;
    cout << "\nSeconds: " << new_seconds;
  
    cout << "\n\nDo you want to do another calculation Y or y for Yes ---> ";
    cin >> do_it_again;
    }
  while(do_it_again == 'Y' || do_it_again == 'y');

  return 0;
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
