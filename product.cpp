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

//The prompt method will receive the input from the user and 
//save the information on the product class
void Product::prompt()
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
void Product::getSalesTax()
{
   salesTax = basePrice * 0.06;
   
}

//This method will get the shipping costs based on the weight. A
//flat rate of $2.00 if the item is less than 5lbs, and 
//$2.00 + $0.10 per pound over 5lbs.
void Product::getShippingCost()
{
   if (weight < 5)
      shipRate = 2;   
   else
      shipRate = 2 + ((weight - 5) * 0.10); 
}

//This method will get the total price after shipping costs
//and sales tax.
void Product::getTotalPrice()
{
  getSalesTax();
  getShippingCost();

  totalPrice = basePrice + salesTax + shipRate;
  
}

//This method will dipslay the Advertising Profile
void Product::displayAdProfile()
{
   cout << name << " - " << "$" << basePrice << endl << "(" << description 
        << ")" << endl;  
}

//This method will display the Inventory Line Item
void Product::displayInventoryLine()
{
   cout << "$" << basePrice << " - " << name << " - " 
        << weight << " lbs" << endl;   
}

void Product::displayReceipt()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   getSalesTax();
   getShippingCost();
   getTotalPrice();

   cout << name << endl;
   cout << setw(2) << "  Price:" << setw(10) << "$" 
        << setw(8) << basePrice << endl;
   cout << setw(2) << "  Sales tax:" << setw(6) << "$" 
        << setw(8) << salesTax << endl;
   cout << setw(2) << "  Shipping cost:" << setw(2) << "$"
        << setw(8) << shipRate << endl;
   cout << setw(2) << "  Total:" << setw(10) << "$" 
        << setw(8) << totalPrice << endl;   
}































