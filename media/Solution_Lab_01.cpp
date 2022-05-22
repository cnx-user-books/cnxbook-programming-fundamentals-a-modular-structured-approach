//******************************************************
// Filename: Solution_Lab_01.cpp
// Purpose:  Average the weight of three people
// Author:   Ken Busbee; © 2008 Kenneth Leroy Busbee
// Date:     Dec 24, 2008
//******************************************************
// Solution source code files are provided by the 
// instructor to each individual student as needed.
// Students are not to share these files with any other
// student, even those taking the course.
// Not now, not later, not ever.  Don't share them.
//******************************************************

// Headers and Other Technical Items

#include <iostream>  
using namespace std;

// Function Prototypes

void pause(void);

// Variables

int     weight1;
int     weight2;
int     weight3;
double  answer;

//******************************************************
// main
//******************************************************

int main(void)
  {
  // Input	

  cout << "\nEnter the weight of the first person --->: ";
  cin >> weight1;

  cout << "\nEnter the weight of the second person -->: ";
  cin >> weight2;

  cout << "\nEnter the weight of the third person --->: ";
  cin >> weight3;

  // Process

  answer = (weight1 + weight2 + weight3) / 3.0;

  // Output

  cout << "\nThe average of their weights is -------->: ";
  cout << answer;

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
