//******************************************************
// Filename:    Demo_Factorial.cpp
// Purpose:     Demonstrate Recursive and Iterative Solutions
//              for Factorial
// Comments:    Using 8! - eight factorial
// Author:      Ken Busbee; © 2009 Kenneth Leroy Busbee
// Date:        Mar 22, 2009
// Licensed by: Kenneth Leroy Busbee under a 
//              Creative Commons Attribution License (CC-BY 3.0)
//              http://creativecommons.org/licenses/by/3.0/
//******************************************************

// Headers and Other Technical Items

#include <iostream>
using namespace std;

// Function Prototypes

void pause(void);
int  factorial(int num);

// Variables

int  input = 8;
int  answer;
int  x;

//******************************************************
// main
//******************************************************

int main(void)
  {
  cout << "Recursion vs Iteration";
  cout << "\n\nFor 8! - eight factorial.\n\n\n";

  // The recursive process
  cout << "8! by Recursion is: " << factorial(input);

  // The iterative process
  for(answer = 1, x = 1; x <= input; x++)
    {
    answer = answer * x;
    }
  cout << "\n\n8! by Iteration is: " << answer;

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
// factorial
//******************************************************

int factorial(int num)
  {
  if(num == 1)
    {
    return 1;
    }
  else
    {
    return (num * factorial(num - 1));
    }
  }

//******************************************************
// End of Program
//******************************************************
