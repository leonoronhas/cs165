/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H
#include <iostream>
#include <cstdlib>
using namespace std;

class Money
{
private:
   int dollars;
   int cents;

public:

   Money ()
   {
      dollars = 0;
      cents = 0;   
   }
   
   Money (int dollars)
   {
      this->dollars = abs(dollars);   
   }

   Money (int dollars, int cents)
   {
      this->dollars = abs(dollars);
      this->cents = abs(cents);   
   }
   
   void prompt();
   void display() const;
   int getDollars() const { return dollars;}
   int getCents() const { return cents; }
};

#endif
