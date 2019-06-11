/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;

int main()
{
   //Create a date object
   Date date;   
   // set its values
   date.set();
   // call each display function
   date.displayAmerican();
   date.displayEuropean();
   date.displayISO();

   return 0;
}
