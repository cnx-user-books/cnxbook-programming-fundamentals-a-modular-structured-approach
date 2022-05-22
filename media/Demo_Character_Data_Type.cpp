//******************************************************
// Filename:    Demo_Character_Data_Type.cpp
// Purpose:     To demonstrate character data type
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Jan 2, 2009
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

char  letter = 'A';

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "\nWhen you display the letter variable you get ------------------------>: ";
  cout << letter;
  cout << "\n\n";
  cout << "\nWhen you cast the letter variable into an integer you get ----------->: ";
  cout << (int)letter;
  cout << "\n\n";
  cout << "\nWhen you display the letter variable plus 3 you get ----------------->: ";
  cout << letter + 3;
  cout << "\n\n";
  cout << "\nWhen you cast the letter variable plus 3 into a character you get --->: ";
  cout << (char)(letter + 3);
  cout << "\n\n";
  pause();

  cout << "\nYou try it. Enter a letter (a to w) --->: ";
  cin >> letter;
    
  cout << "\n\nWhen you display the letter variable you get ------------------------>: ";
  cout << letter;
  cout << "\n\n";
  cout << "\nWhen you cast the letter variable into an integer you get ----------->: ";
  cout << (int)letter;
  cout << "\n\n";
  cout << "\nWhen you display the letter variable plus 3 you get ----------------->: ";
  cout << letter + 3;
  cout << "\n\n";
  cout << "\nWhen you cast the letter variable plus 3 into a character you get --->: ";
  cout << (char)(letter + 3);
  cout << "\n\n";
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
