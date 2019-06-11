/********************************************************************
 * File: date.h
 * Purpose: Holds the definition of the Date class.
 ********************************************************************/

#ifndef DATE_H
#define DATE_H

class Date
{
   private:
      int month;
      int day;
      int year;
      
   public:
      void set();
      void displayAmerican();
      void displayEuropean();
      void displayISO();   
};



#endif
