/***********************************************************************
* Program:
*    Date header  
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    This will be the header of the program, here I will declare my
*    date class.
*
*    Estimated:  1.0 hrs   
*    Actual:     1.0 hrs
************************************************************************/

//#ifndef DATE_H
//#define DATE_H

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

//#endif
