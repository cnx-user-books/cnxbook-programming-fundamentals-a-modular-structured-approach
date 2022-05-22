//******************************************************
// Filename:    Demo_File_IO.cpp
// Purpose:     File I/O - text file
// Comments:    The input file contains several integer and
//              floating-point values.  This program will 
//              open the input file, read the values and 
//              total them.  When it runs out of input data,
//              the program will write the total to the 
//              output file.
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Apr 6, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
#include <fstream>         // For file I/O 
using namespace std;

// Function Prototypes

void pause(void);

// Variables

double   next_number;
double   total = 0;        // Initialize to zero

fstream  inData;           // device token for the input stream
fstream  outData;          // device token for the output stream

// Place the Demo_File_IO_Input.txt file in a folder on your
// drive.  We suggest that you create a folder named: 
// Data_Files on the root level of your C: (hard disk) drive
// or flash drive as appropriate. 
// The output file will also be stored at this location.

                           // File Specifications for the 
                           // input file and the output file
                           // A file specificatoin includes a 
                           // drive, path, filename and file extention 
char     input_filename[]  = "C:\\Data_Files\\Demo_File_IO_Input.txt";
char     output_filename[] = "C:\\Data_Files\\Demo_File_IO_Output.txt";

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Open the files
  
  inData.open(input_filename, ios::in);        //Open input file
  if (!inData)
    {
    cout << "\n\nError opening input data file: " << input_filename << "\n\n";
    pause();
    exit(EXIT_FAILURE);
    }
  outData.open(output_filename, ios::out);     //Open output file
  if (!outData)
    {
    cout << "\n\nError opening output data file: " << output_filename << "\n\n";
    pause();
    exit(EXIT_FAILURE);
    }

  // Get data values and total them

  while (inData >> next_number)
    {
    total += next_number;
    }

  // Send the total to the output file

  outData << "Total is: " << total << endl;
  
  // Close the files
  inData.close();                              //Close input file
  outData.close();                             //Close output file

  // Message to the User
  cout << "\n\nThe program worked correctly.";
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
