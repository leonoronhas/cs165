/***********************************************************************
* Program:
*    CheckPoint 01b, CheckPoint 01b, review
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    This program will ask the user for a list size then save all his or
*    her entries and display all the numbers the user entered that are
*    divisible by 3. The program will use different functions for all
*    calculations required..
*
*    Estimated:  1.0 hrs   
*    Actual:     1.30 hrs
*      Please describe briefly what was the most difficult part.
*      Trying to remember how to use arrays again.
************************************************************************/

#include <iostream>
using namespace std;

int getSize();
void getList(int list[], int size);
void displayMultiples(int list[], int size);

/**********************************************************************
 * Main will call the functions.
 ***********************************************************************/
int main()
{
   int size = getSize();
   int list[size];
   getList(list, size);
   displayMultiples(list, size);

   return 0;
}

/**********************************************************************
 * getList is going to receive the size of the list from main and ask
 * the user for the index number equivalent to the list size and return
 * the amounts..
 ***********************************************************************/
void getList(int list[], int size)
{
   //prompt the user until the list is completed
   for (int i = 0; i < size; i++)
   {
      cout << "Enter number for index " << i << ": ";
      cin >> list[i];  
   }
}

/**********************************************************************
 * getSize will prompt the user for the size of the list and return
 * the list size to the caller.
 ***********************************************************************/
int getSize()
{
   int list = 0;
   cout << "Enter the size of the list: ";
   cin >> list;   

   return list;
}

/**********************************************************************
 * displayMultiples function will receive the array and its size, will 
 * then show all numbers in the array that are divisible by 3..
 ***********************************************************************/
void displayMultiples(int list[], int size)
{
   cout << endl << "The following are divisible by 3:\n";
   
   //runt the loop to find the numbers divisible by 3
   for (int i = 0; i < size; i++)
   {
      if (list[i] % 3 == 0)
         cout << list[i] << endl;  //print a new line after each number 
   }
}
