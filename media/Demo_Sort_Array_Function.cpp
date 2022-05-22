//******************************************************
// Filename:    Demo_Sort_Array_Function.cpp
// Purpose:     Sort an array using a function
// Comment:     Bubble Sorting an Array  (Sorts while it needs more sorting)
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Apr 6, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
#include <fstream>         // For file I/O 
#include <iomanip>         // For setw()
using namespace std;

// Function Prototypes

int  count_file_values(char input_filename[]);
void load_array_from_file(char input_filename[], int things[], int array_size);
void display_array(int things[], int array_size);
void bubble_sort_array(int things[], int array_size);
void pause(void);

// Variables

// Place the Demo_Farm_Acres_Input.txt file in a folder on your
// drive.  We suggest that you create a folder named: 
// Data_Files on the root level of your C: (hard disk) drive
// or flash drive as appropriate. 

                           // File Specifications for the input file
                           // A file specificatoin includes a 
                           // drive, path, filename and file extention 
char     data_filename[]  = "C:\\Data_Files\\Demo_Farm_Acres_Input.txt";

//******************************************************
// main
//******************************************************

int main(void)
  {
  int record_count = count_file_values(data_filename);
  int acres[record_count];
  load_array_from_file(data_filename, acres, record_count);
  cout << "The individual farm acerages are: \n";
  display_array(acres, record_count);
  bubble_sort_array(acres, record_count);
  cout << "\n\nThe sorted farm acerages are: \n";
  display_array(acres, record_count);
  pause();

  return 0;
  }

//******************************************************
// count_file_values
//******************************************************

int count_file_values(char input_filename[])
  {
  fstream  inData;           // device token for the input stream
  double   next_value;
  int      number_of_values = 0;
  
  inData.open(input_filename, ios::in);        //Open input file
  if (!inData)
    {
    cout << "\n\nError opening input data file: " << input_filename << "\n\n";
    pause();
    exit(EXIT_FAILURE);
    }
  // Get data values and count them

  while (inData >> next_value)
    {
    number_of_values++;
    }

  // Close the files
  inData.close();                              //Close input file

  return number_of_values;
  }

//******************************************************
// load_array_from_file
//******************************************************

void load_array_from_file(char input_filename[], int things[], int array_size)
  {
  fstream  inData;           // device token for the input stream

  inData.open(input_filename, ios::in);        //Open input file
  if (!inData)
    {
    cout << "\n\nError opening input data file: " << input_filename << "\n\n";
    pause();
    exit(EXIT_FAILURE);
    }
  else
    {
    for (int i = 0; i < array_size; i++)   // Load the array
      {
      inData >> things[i];
      }
    inData.close();
    }
  return;
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
// bubble_sort_array
//******************************************************

void bubble_sort_array(int things[], int array_size)
  {
  bool moresortneeded;   // Flag to determine if sorting is completed
  int  temp;             // Used for swaping array members

  do
    {
    moresortneeded = false;
    for(int i = 0; i < array_size - 1; i++)
      {
      if(things[i] > things[i+1])
        {
        temp = things[i];
        things[i] = things[i+1];
        things[i+1] = temp;
        moresortneeded = true;
        }
      }
    }
  while(moresortneeded);

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
