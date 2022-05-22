//******************************************************
// Filename:    udst_monitor.h
// Purpose:     Header File for several Specific Task functions
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Jan 7, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

#include <ctime>

//******************************************************
// clear_m
//******************************************************

void clear_m(void)
  {
  system("CLS");
  return;
  }

//******************************************************
// delay_m
//******************************************************

void delay_m(int tenths_second)
  {
  clock_t mark_the_time = clock(); // long int, 1000's of seconds
  
  while(clock() < (mark_the_time + (tenths_second * 100)));
  
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
// End of File
//******************************************************
