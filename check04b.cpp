/***********************************************************************
* Program:
*    CheckPoint 04b   
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    This will be the driver program.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
************************************************************************/

#include <iostream>
#include "date.h"
using namespace std;

int main()
{
   //declare the date object
   Date date;

   //get the date from the user
   date.set();

   //call the methods
   date.displayAmerican();
   date.displayEuropean();
   date.displayISO();

   return 0;
}
