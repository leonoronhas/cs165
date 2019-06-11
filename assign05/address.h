// File: address.h

#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Class: Address
class Address
{
   private:
      string street;
      string city;
      string state;
      string zip;
   
   public:
      //Constructors
      Address();
      Address(const string street,
              const string city,
              const string state,
              const string zip);
            
      //Getters
      string getStreet() const { return street; }
      string getCity() const { return city; }   
      string getState() const { return state; }   
      string getZip() const { return zip; } 
      
      //Setters
      void setStreet(const string street);
      void setCity(const string city);
      void setState(const string state);
      void setZip(const string zip);
      
      //Display
      void display() const;        
};


#endif
