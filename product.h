/***************************************************************
 * File: product.h
 * Author: Leonardo Santos
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>

using namespace std;

class Product
{
   private:
      string name;
      string description;
      float basePrice;
      float weight;
      float salesTax;
      float shipRate;
      float totalPrice;

      void getSalesTax();
      void getShippingCost();
      void getTotalPrice();
   
   public:
      void prompt();
      void displayAdProfile();
      void displayInventoryLine();
      void displayReceipt();  
};

#endif
