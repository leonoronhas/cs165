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
      
   public:
      //Constructors
      Product();
      Product(const string name,
              const string description,
              float basePrice,
              float weight);

      //Getters
      string getName() const { return name; }
      string getDescription() const { return description; }
      float getBasePrice() const { return basePrice; }
      float getWeight() const { return weight; }

      //Setters
      void prompt();
      void setName(const string name);
      void setDescription(const string description);
      void setBasePrice(float basePrice);
      void setWeight(float weight);

      //Display
      void displayAdvertising() const;
      void displayInventory() const;
      void displayReceipt() const;
      
      //Shipping and Sales cost
      float getSalesTax() const;
      float getShippingCost() const;
      float getTotalPrice() const;
  
};

#endif
