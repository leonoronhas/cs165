// File: address.cpp
#include <iostream>
#include <string>
#include "address.h"
#include "customer.h"

using namespace std;

/***********************************************
 * Methods for the address class
 * ********************************************/

//Constructors
Address :: Address()
{
   street = "unknown";
   city = "";
   state = "";
   zip = "00000";
}

Address :: Address(const string street,
                   const string city,
                   const string state,
                   const string zip)
{
   this->street = street;
   this->city = city;
   this->state = state;
   this->zip = zip;
}

//Setters
void Address :: setStreet(const string street)
{
   this->street = street;   
}

void Address :: setCity(const string city)
{
   this->city = city;   
}
void Address :: setState(const string state)
{
   this->state = state;   
}
void Address :: setZip(const string zip)
{
   this->zip = zip;   
}

void Address :: display() const
{
   cout << getStreet() << endl;
   cout << getCity() << ", " << getState() << " " << getZip() << endl; 
}
