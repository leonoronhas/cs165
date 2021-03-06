// File: customer.cpp

#include <iostream>
#include <string>
#include "customer.h"
//#include "address.h" 

using namespace std;

/*****************************************************
 * Method bodies for customer class
 **************************************************/

//Constructors
Customer :: Customer()
{
   name = "unspecified";
}

Customer :: Customer(string name, Address address)
{
   setName(name);
   setAddress(address);   
}

//Setters
void Customer :: setName(string name)
{
   this->name = name;   
}

void Customer :: setAddress(Address address)
{
   this->address = address;   
}

//Display
void Customer :: display() const
{
   cout << getName() << endl;
   address.display(); 
}





