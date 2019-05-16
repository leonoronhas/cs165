/***********************************************************************
* Program:
*    CheckPoint 03b, Syntax  
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int prompt() throw (string)
{
   int number = -1;
 //  bool done = false;
  
   do   
   {   
      cout << "Enter a number: ";
      cin >> number;
      
      if (cin.fail())
      {   
         cin.clear();
         cin.ignore(256, '\n');
         cout << "Invalid input." << endl;
      } 
   }
   while(!number);
   
   return number;
}

int main()
{
   int number = 0;
   try
   {
      number = prompt();
      cout << "The number is " << number << "." << endl;   
   }
   catch (string errorMessage)
   {
      cout << "Error: " << errorMessage << endl;   
   }
   
   return 0;
}
