/***************************************************************
 * File: product.cpp
 * Author: Leonardo Santos
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/**************************************************************
 * Methods for the Product class
 *************************************************************/

//Constructors
Product :: Product()
{
   name = "none";
   description = "";
   basePrice = 0;
   weight = 0;   
}

Product :: Product(const string name,
                   const string description,
                   float basePrice,
                   float weight)
{
   this->name = name;
   this->description = description;
   this->basePrice =  basePrice;
   this->weight = weight;
}


//The prompt method will receive the input from the user and 
//save the information on the product class
void Product :: prompt()
{
   cout << "Enter name: ";
   getline(cin, name);
   cout << "Enter description: ";
   getline(cin, description);
   cout << "Enter weight: ";
   cin >> weight;

   do
   {   
      cout << "Enter price: ";
      cin >> basePrice;

      if (cin.fail())
      {
         cin.clear(); //clear first
         cin.ignore(256, '\n');
         basePrice = -1; //setting to -1 because it cannot be less than 0   
      }
   }
   while (basePrice < 0);  
}

//This method will get the sales tax (6%) and add the amount
//to the base price.
float Product :: getSalesTax() const
{
   return basePrice * 0.06;
   
}

//This method will get the shipping costs based on the weight. A
//flat rate of $2.00 if the item is less than 5lbs, and 
//$2.00 + $0.10 per pound over 5lbs.
float Product :: getShippingCost() const
{
   if (weight < 5)
      return 2.00;   
   else
      return 2.00 + ((weight - 5) * 0.10); 
}

//This method will get the total price after shipping costs
//and sales tax.
float Product :: getTotalPrice() const
{
  return getBasePrice() + getSalesTax() + getShippingCost(); 
}

//This method will dipslay the Advertising Profile
void Product :: displayAdvertising() const
{ 
   cout.setf(ios::fixed);
   cout.precision(2);
   cout << name << " - " << "$" << basePrice << endl << "(" << description 
        << ")" << endl;  
}

//This method will display the Inventory Line Item
void Product::displayInventory() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "$" << setprecision(2) << getBasePrice() << " - " << getName() << " - " 
        << setprecision(1) << getWeight() << " lbs" << endl;   
}

void Product::displayReceipt() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << name << endl;
   cout << setw(2) << "  Price:" << setw(10) << "$" 
        << setw(8) << getBasePrice() << endl;
   cout << setw(2) << "  Sales tax:" << setw(6) << "$" 
        << setw(8) << getSalesTax() << endl;
   cout << setw(2) << "  Shipping cost:" << setw(2) << "$"
        << setw(8) << getShippingCost() << endl;
   cout << setw(2) << "  Total:" << setw(10) << "$" 
        << setw(8) << getTotalPrice() << endl;   
}

//Setters
void Product :: setName(const string name)
{
   this->name = name;
}

void Product :: setDescription(const string description)
{
   this->description = description;
}

void Product :: setBasePrice(float basePrice)
{
   this->basePrice = basePrice;
}

void Product :: setWeight(float weight)
{
   this->weight = weight;
}





























