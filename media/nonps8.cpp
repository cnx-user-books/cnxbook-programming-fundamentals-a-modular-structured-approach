//***************************************************************
// Filename:    nonps8.cpp
// Purpose:     Demonstration of Super Micro Computer 
//              Single Machine Non-Parallel Code 
// Comment:     Bubble Up Sort with Array Indexing
//              Using nested for loops (wall moving method)
// Author:      Ken Busbee - May 25, 2006
//              © 2006 Kenneth Leroy Busbee
// Licensed by: Kenneth Leroy Busbee under a Creative Commons Attribution License (CC-BY 2.0)
//              http://creativecommons.org/licenses/by/2.0/
//***************************************************************

#include<iostream>
using namespace std;

#define ELEMENTS 150000
#define SEED 4567

//***************************************************************
// main
//***************************************************************

int main(void)
  {
  int  nums[ELEMENTS];
  long index1;

  int  seed;

  long current;
  long walker;
  long last = ELEMENTS-1;
  int  temp;

  // Propagate the array 
  srand(SEED);
  for(index1 = 0; index1 < ELEMENTS; index1++)
    {
    nums[index1] = rand () % 30000 + 1; // Values from 1 to 30,000
    }
  cout << endl;
  // End of propogating the array
    
  // Display the first 20 elements of the array before it's sorted
  for(index1 = 0; index1 < 20; index1++)
    {
    cout << nums[index1] << endl;
    }
  cout << endl;
  // End of displaying the array
    
  for(current = 0; current < last; current++)      // Outter loop
    {
    for(walker = last; walker > current; walker--) // Inner loop
      {
      if(nums[walker] < nums[walker-1])
        {
        temp = nums[walker];
        nums[walker] = nums[walker-1];
        nums[walker-1] = temp;
        }
      }
    }

  // Display the first 20 elements of the after before it's sorted
  for(index1 = 0; index1 < 20; index1++)
    {
    cout << nums[index1] << endl;
    }
  cout << endl;
  // End of displaying the array
    
  return 0;
  }

//***************************************************************
// End of Program
//***************************************************************
