/***************************************************************
 * File: rational.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Rational class.
 ***************************************************************/

#include "rational.h"
#include <iostream>

using namespace std;

void Rational::prompt()
{
   cout << "Top: ";
   cin >> top;

   cout << "Bottom: ";
   cin >> bottom;

}

void Rational::display()
{
   if (top > bottom)
   {
      cout << (int)top / (int)bottom << " " 
           << (int)top -((int)top/(int)bottom)*bottom 
           << "/" << bottom << endl;   
   }
   cout << top << "/" << bottom << endl;   
}

void Rational::displayDecimal()
{
  cout.setf(ios::fixed);
  cout.precision(2);

  cout << top / bottom << endl;   
}

void Rational::multiplyBy()
{
   cout << "Another top number: ";
   int anotherTop = 0;;
   cin << anotherTop;

   cout << "Another bottom number: ";
   int anotherBottom = 0;
   cin >> anotherBottom;

   top *= anotherTop;
   bottom *= anotherBottom;

}
