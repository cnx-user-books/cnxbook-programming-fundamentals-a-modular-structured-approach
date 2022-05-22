//******************************************************
// Filename:    Demo_Versatile_Array_Function.cpp
// Purpose:     Show how typedef can be used to make 
//              array functions usable for different data types
// Author:      Ken Busbee; © 2009-2010 Kenneth Leroy Busbee
// Date:        Apr 6, 2009, Revised: Jan 13, 2010
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************
// You are to run this program twice.
// 1st time with the Demo_Farm_Acres_Input.txt file.
// THEN CHANGE TO THREE SPOTS AS IDENTIFIED BY CAPITAL LETTERS BELOW
// 2nd time with the Demo_Deposit_Checks_Input.txt file.
//******************************************************

// Headers and Other Technical Items

#include <iostream>
#include <fstream>         // For file I/O 
#include <iomanip>         // For setw()
using namespace std;

// Typedefs - data type alias

typedef char filespec[];    // For documentation - do not change  
typedef int  array_type[];  // CHANGE FROM INT TO DOUBLE
typedef int  values_type;   // CHANGE FROM INT TO DOUBLE

// Function Prototypes

int          count_file_values(filespec input_filename);
void         load_array_from_file(filespec input_filename, array_type things, int array_size);
void         display_array(array_type things, int array_size);
values_type  sum_array(array_type things, int array_size);
values_type  average_array(array_type things, int array_size);
int          search_array(array_type things, int array_size, values_type target);
values_type  max_array(array_type things, int array_size);
values_type  min_array(array_type things, int array_size);
void         bubble_sort_array(array_type things, int array_size);
void         pause(void);

// Variables

// Place the Demo_Farm_Acres_Input.txt file in a folder on your
// drive.  We suggest that you create a folder named: 
// Data_Files on the root level of your C: (hard disk) drive
// or flash drive as appropriate. 

                           // File Specifications for the input file
                           // A file specificatoin includes a 
                           // drive, path, filename and file extention 
char     data_filename[]  = "C:\\Data_Files\\Demo_Farm_Acres_Input.txt";
                           // CHANGE THE FILENAME FOR THE SECOND FILE  

// Also place your Demo_Deposit_Checks_Input.txt file in your data files folder.

//******************************************************
// main
//******************************************************

int main(void)
  {
  int record_count = count_file_values(data_filename);
  values_type file_data[record_count];
  load_array_from_file(data_filename, file_data, record_count);
  cout << "The file data is: \n";
  display_array(file_data, record_count);
  cout << "\n\nThe total of the values in the file is: " << sum_array(file_data, record_count);
  cout << "\n\nThe average of the values in the file is: " << average_array(file_data, record_count);
  pause();

  cout << "The file data is: \n";
  display_array(file_data, record_count);
  values_type desired_value;
  cout << "\n\nWhat value to you want to search for? ";
  cin >> desired_value;
  int search_response = search_array(file_data, record_count, desired_value);
  if (search_response > -1)
    {
    cout << "\n\nMember " << search_response + 1 << " has datum of interest.";
    }
  else
    {
    cout << "\n\nNo matching file datum was found";
    }
  cout << "\n\nThe largest file datum is " << max_array(file_data, record_count) << " file_data.";
  cout << "\n\nThe smallest datum is " << min_array(file_data, record_count) << " file_data.";
  pause();

  cout << "The file data is: \n";
  display_array(file_data, record_count);
  bubble_sort_array(file_data, record_count);
  cout << "\n\nThe sorted file data is: \n";
  display_array(file_data, record_count);
  pause();

  return 0;
  }

//******************************************************
// count_file_values
//******************************************************

int count_file_values(filespec input_filename)
  {
  fstream      inData;           // device token for the input stream
  values_type  next_value;
  int          number_of_values = 0;
  
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

void load_array_from_file(filespec input_filename, array_type things, int array_size)
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

void display_array(array_type things, int array_size)
  {

  cout << "\n********************************";
  for (int i = 0; i < array_size; i++)
    {
    cout << "\nOffset: " << setw(2) << i;
    cout << " Memeber: " << setw(2) << i+1;
    cout << " value is: " << things[i];
    }
  cout << "\n********************************";

  return;
  }

//******************************************************
// sum_array
//******************************************************

values_type sum_array(array_type things, int array_size)
  {
  values_type  total = 0;         // Accumulator

  for (int i = 0; i < array_size; i++)
    {
    total += things[i];
    }
  return total;
  }

//******************************************************
// average_array
//******************************************************

values_type average_array(array_type things, int array_size)
  {
  values_type  total = 0;         // Accumulator

  for (int i = 0; i < array_size; i++)
    {
    total += things[i];
    }
  return total / array_size;
  }

//******************************************************
// search_array
//******************************************************
// the target is the value you are searching for
// if found the return value is the index (offset) for the member
// if not found the return value is -1
//******************************************************

int search_array(array_type things, int array_size, values_type target)
  {
  for (int i = 0; i < array_size; i++)
    {
    if (target == things[i])
      {
      return i;            // target found
      }
    }
  return -1;               // search failed to find the target
  }

//******************************************************
// max_array
//******************************************************

values_type max_array(array_type things, int array_size)
  {
  values_type  max = things[0];   // Pick the first element as the largest value

  for (int i = 1; i < array_size; i++)
    {
    if (max < things[i])
      {
      max = things[i];    // Replace max with a larger value
      }
    }
  return max;
  }

//******************************************************
// min_array
//******************************************************

values_type min_array(array_type things, int array_size)
  {
  values_type  min = things[0];  // Pick the first element as the smallest value

  for (int i = 1; i < array_size; i++)
    {
    if (min > things[i])
      {
      min = things[i];   // Replace min with a smaller value
      }
    }
  return min;
  }

//******************************************************
// bubble_sort_array
//******************************************************

void bubble_sort_array(array_type things, int array_size)
  {
  bool moresortneeded;   // Flag to determine if sorting is completed
  values_type  temp;             // Used for swaping array members

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
