/***************************************************************
 * File: rational.h
 * Author: Leonardo Santos
 * Purpose: Contains the definition of the Rational class
 ***************************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
   private:
      float top;
      float bottom;

   public:
      void prompt();
      void display();
      void displayDecimal();  
      void multiplyBy(); 
};
#endif
