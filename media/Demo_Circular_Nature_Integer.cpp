//******************************************************
// Filename:    Demo_Circular_Nature_Integer.cpp
// Purpose:     Demonstrate the Circular Nature of  
//              Integer and Character Data Types
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Mar 19, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
#include<ctime>                 // needed for delay function
using namespace std;

// Function Prototypes

void pause(void);
void delay(int tenths_second);

// Constants

#define DELAY_IN_TENTHS 1

// Variables

int           four_byte_integer;
short int     two_byte_integer;
unsigned char one_byte_character;  //Domain is: 0 to 255
int           x;

//******************************************************
// main
//******************************************************

int main(void)
  {
  four_byte_integer = 2147483647;
  cout << "\nThe largest four byte integer value is: ----> " << four_byte_integer;
  cout << "\n";
  four_byte_integer++;
  cout << "\nAfter incrementing it becomes: -------------> " << four_byte_integer;
  pause();

  two_byte_integer = 32767;
  cout << "\nThe largest two byte integer value is: -----> " << two_byte_integer;
  cout << "\n";
  two_byte_integer++;
  cout << "\nAfter incrementing it becomes: -------------> " << two_byte_integer;
  pause();

  one_byte_character = (char)255;
  cout << "\nThe largest one byte character value is: ---> " << (int)one_byte_character;
  cout << "\n";
  one_byte_character++;
  cout << "\nAfter incrementing it becomes: -------------> " << (int)one_byte_character;
  pause();

  one_byte_character = (char)0;
  cout << "\nThe smallest one byte character value is: --> " << (int)one_byte_character;
  cout << "\n";
  one_byte_character--;
  cout << "\nAfter decrementing it becomes: -------------> " << (int)one_byte_character;
  pause();

  cout << "\nThe two byte integer running circular like a clock.";
  cout << "\nAdding 12,345 with each movement.";
  cout << "\n";
  for(two_byte_integer = 0, x = 0; x < 10; two_byte_integer += 12345, x++)
    {
    cout << "\nTwo byte integer value: ----> " << two_byte_integer;
    }
  pause();

  cout << "\nThe two byte integer running circular like a clock.";
  cout << "\nSubtracting 12,345 with each movement.";
  cout << "\nThus, running back wards or counter clock wise.";
  cout << "\n";
  for(two_byte_integer = 0, x = 0; x < 10; two_byte_integer -= 12345, x++)
    {
    cout << "\nTwo byte integer value: ----> " << two_byte_integer;
    }
  pause();

  cout << "\nThe one byte character running circular like a clock.";
  cout << "\nCircles around twice plus a little in about one minute.";
  pause();
  for(one_byte_character = (char)0, x = 0; x < 600; one_byte_character++, x++)
    {
    cout << "\nOne byte character value: ----> " << (int)one_byte_character;
    delay(DELAY_IN_TENTHS);                // call delay    
    }
  pause();

  cout << "\nThe two byte integer running circular like a clock.";
  cout << "\nDecrementing with each movement.";
  cout << "\nThus, running back wards or counter clock wise.";
  cout << "\nBecause, the programmer meant to increment.";
  cout << "\nIt stops once the value decrements to positive 32767.";
  pause();
  for(two_byte_integer = 0; two_byte_integer < 10; two_byte_integer--)
    {
    cout << "\nTwo byte integer value: ----> " << two_byte_integer;
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
