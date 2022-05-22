//******************************************************
// Filename:    Demo_Multidimension_Arrays.cpp
// Purpose:     Demonstrate a Two Dimension Array
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Apr 16, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;

// Function Prototypes

void pause(void);

// Variables

char puzzle[4] [18] =
  {
    {' ','W','H','E','E','L',' ','O','F',' ','F','O','R','T','U','N','E',' '},
    {' ',' ',' ',' ','M','U','Z','Z','L','E',' ','B','O','X',' ',' ',' ',' '},
    {'T','E','A','C','H','I','N','G',' ','A','B','O','U','T',' ','T','W','O'},
    {' ','D','I','M','E','N','S','I','O','N',' ','A','R','R','A','Y','S',' '}
  };

int row;
int col;

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "Output of Data\n\n";
  for(row = 0; row < 4; row++)
    {
    for(col = 0; col < 18; col++)
      {
      cout << puzzle[row][col];
      }
    cout << endl;
    }
  cout << "\nPuzzle outputed sucessfully.";
  pause();

  puzzle[1][4] = 'P';
  cout << "Output of Data\n\n";
  for(row = 0; row < 4; row++)
    {
    for(col = 0; col < 18; col++)
      {
      cout << puzzle[row][col];
      }
    cout << endl;
    }
  cout << "\nPuzzle outputed sucessfully.";
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
