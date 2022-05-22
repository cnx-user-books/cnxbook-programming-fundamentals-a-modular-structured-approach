//***************************************************************
// Filename:    ps8.cpp
// Purpose:     Demonstration of Super Micro Computer 
//              Multiple Machines Parallel Code 
// Comment:     Bubble Up Sort with Array Indexing
//              Using nested for loops (wall moving method)
// Author:      Ken Busbee - May 25, 2006
//              © 2006 Kenneth Leroy Busbee
// Licensed by: Kenneth Leroy Busbee under a Creative Commons Attribution License (CC-BY 2.0)
//              http://creativecommons.org/licenses/by/2.0/
//***************************************************************

#include<iostream>
using namespace std;
#include <mpi.h>

#define ELEMENTS 150000
#define SUBSIZE 15000
#define SEED 4567
#define SERVER_NODE 0
#define TAG 2

//***************************************************************
// main
//***************************************************************

int main(int argc, char ** argv) 
  {
  int  nums[ELEMENTS];
  int  pres[ELEMENTS];
  long index1;

  long index01 = SUBSIZE * 0;
  long index02 = SUBSIZE * 1;
  long index03 = SUBSIZE * 2;
  long index04 = SUBSIZE * 3;
  long index05 = SUBSIZE * 4;
  long index06 = SUBSIZE * 5;
  long index07 = SUBSIZE * 6;
  long index08 = SUBSIZE * 7;
  long index09 = SUBSIZE * 8;
  long index10 = SUBSIZE * 9;
  
  int  count;
  int  group;

  long current;
  long walker;
  long last = ELEMENTS-1;
  int  temp;

  int my_rank;
  int world_size;
  int source;
  MPI_Status status;

  //*************************************************************
  // Common Code
  //*************************************************************

  MPI_Init(&argc, &argv); /* note that argc and argv are passed by address */

  MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
  MPI_Comm_size(MPI_COMM_WORLD,&world_size);

  // Propagate the array 
  srand(SEED);
  for(index1 = 0; index1 < ELEMENTS; index1++)
    {
    nums[index1] = rand () % 30000 + 1; // Values from 1 to 30,000
    }
  cout << endl;
  // End of propogating the array
    
  //*************************************************************
  // Server Node Code
  //*************************************************************

  if ( my_rank == SERVER_NODE)
    {
    // Display the first 20 elements of the array before it's sorted
    for(index1 = 0; index1 < 20; index1++)
      {
      cout << nums[index1] << endl;
      }
    cout << endl;
    // End of displaying the array
    
    for (source = 1; source < world_size; source++)
      {
      MPI_Recv(&pres[SUBSIZE * (source -1)],SUBSIZE,MPI_INT,source,TAG,MPI_COMM_WORLD, &status);
      }

    // Display the first 20 elements of the array before merged
    for(index1 = 0; index1 < 20; index1++)
      {
      cout << pres[index1] << endl;
      }
    cout << endl;
    // End of displaying the array

    //****************************************************
    // Merge Logic Starts Here
    for(index1 = 0; index1 < ELEMENTS; index1++)
      {
      temp =  30001;
      if((index01 < SUBSIZE) && (pres[index01] < temp))
	{
	temp = pres[index01];
	group = 1;
	}
      if((index02 < SUBSIZE *2) && (pres[index02] < temp))
	{
	temp = pres[index02];
	group = 2;
	}
      if((index03 < SUBSIZE *3) && (pres[index03] < temp))
	{
	temp = pres[index03];
	group = 3;
	}
      if((index04 < SUBSIZE *4) && (pres[index04] < temp))
	{
	temp = pres[index04];
	group = 4;
	}
      if((index05 < SUBSIZE *5) && (pres[index05] < temp))
	{
	temp = pres[index05];
	group = 5;
	}
      if((index06 < SUBSIZE *6) && (pres[index06] < temp))
	{
	temp = pres[index06];
	group = 6;
	}
      if((index07 < SUBSIZE *7) && (pres[index07] < temp))
	{
	temp = pres[index07];
	group = 7;
	}
      if((index08 < SUBSIZE *8) && (pres[index08] < temp))
	{
	temp = pres[index08];
	group = 8;
	}
      if((index09 < SUBSIZE *9) && (pres[index09] < temp))
	{
	temp = pres[index09];
	group = 9;
	}
      if((index10 < SUBSIZE *10) && (pres[index10] < temp))
	{
	temp = pres[index10];
	group = 10;
	}
      nums[index1] = temp;
      if(group == 1)
	index01++;
      if(group == 2)
	index02++;
      if(group == 3)
	index03++;
      if(group == 4)
	index04++;
      if(group == 5)
	index05++;
      if(group == 6)
	index06++;
      if(group == 7)
	index07++;
      if(group == 8)
	index08++;
      if(group == 9)
	index09++;
      if(group == 10)
        index10++;
      }
    // Merge Logic Ends Here
    //****************************************************

    // Display the first 20 elements of the after before it's sorted
    for(index1 = 0; index1 < 20; index1++)
      {
      cout << nums[index1] << endl;
      }
    cout << endl;
    // End of displaying the array
    }
    
  //*************************************************************
  // Client Node Code
  //*************************************************************

  if (my_rank != SERVER_NODE)
    {
    last = SUBSIZE * my_rank -1; 
    for(current = SUBSIZE * (my_rank -1); current < last; current++)      // Outter loop
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
    MPI_Send(&nums[SUBSIZE * (my_rank -1)], SUBSIZE,MPI_INT,SERVER_NODE,TAG,MPI_COMM_WORLD);
    }
  //*************************************************************
  // Common Code
  //*************************************************************

  MPI_Finalize();
  return 0;
  }

//***************************************************************
// End of Program
//***************************************************************
