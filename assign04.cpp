/***************************************************************
 * File: assign04.cpp
 * Author: Leonardo Santos
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "product.h"

int main()
{
   // Declare your Product object here
   Product item;

   // Call your prompt function here
   item.prompt();

   cout << endl;
   cout << "Choose from the following options:\n";
   cout << "1 - Advertising profile\n";
   cout << "2 - Inventory line item\n";
   cout << "3 - Receipt\n";
   cout << endl;
   cout << "Enter the option that you would like displayed: ";

   int choice;
   cin >> choice;

   cout << endl;

   if (choice == 1)
   {
      // Call your display advertising profile function here
      item.displayAdProfile();
   }
   else if (choice == 2)
   {
      // Call your display inventory line item function here
      item.displayInventoryLine();
   }
   else
   {
      // Call your display receipt function here
      item.displayReceipt();  
   }

   return 0;
}
