// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "address.h"

//Customer class
class Customer
{
   private:
      string name;
      Address address;

   public:
      //Constructors
      Customer();
      Customer(const string name, Address address);
      
      //Getters
      string getName() const { return this->name; }
      Address getAddress() const { return this->address; }
      
      //Setters
      void setName(const string name);
      void setAddress(Address address);
      
      //Display
      void display() const;
         
};

#endif
