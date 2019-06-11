// File: order.h

#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "customer.h"


// Order class
class Order
{
   private:
      Product product;
      int quantity;
      Customer customer;
   
   public:   
      //Constructors
      Order();
      Order(Product product, int quantity, Customer customer);

      //Getters
      Product getProduct() const { return product; }
      int getQuantity() const { return quantity; }
      Customer getCustomer() const { return customer; }
      string getShippingZip() const { return customer.getAddress().getZip(); }
      float getTotalPrice() const;

      //Setters
      void setProduct(Product product);
      void setQuantity(int quantity);
      void setCustomer(Customer customer);
      
      //Display
      void displayShippingLabel() const; 
      void displayInformation() const;     
};


#endif
