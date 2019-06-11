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

   Money()
   {
      dollars = 0;
      cents = 0;   
   }

   void prompt();
   void display() const;
   int getDollars() const { return dollars;};
   int getCents() const { return cents; };
   void setDollars(int dollars) { this->dollars = abs(dollars); }; //this-> sets the first var to be the member var.
   void setCents(int cents) { this->cents = abs(cents); };
};

#endif
