/***********************************************************************
* Program:
*    Date Methods         
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    This date.cpp file will contain all method bodies for the class
*    date.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
************************************************************************/
#include <iostream>
#include "date.h"
using namespace std;

void Date::set()
{
   cout << "Month: ";
   cin >> month;
   
   cout << "Day: ";
   cin >> day;
   
   cout << "Year: ";
   cin >> year;
      
}

void Date::displayAmerican()
{
   cout << month << "/" << day << "/" << year << endl;   
}

void Date::displayEuropean()
{
   cout << day << "/" << month << "/" << year << endl;   
}

void Date::displayISO()
{
   cout << year << "-" << month << "-" << day << endl;   
}






