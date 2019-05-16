/***********************************************************************
* Program:
*    Checkpoint 01a, Checkpoint 01a, review    
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{  
   string name;
   int age;
   
   cout << "Hello CS 165 World!" << endl;
   cout << "Please enter your first name: ";
   getline(cin, name);
   cout << "Please enter your age: ";
   cin >> age; 
   
   cout << endl << "Hello " << name << ", " << "you are " << age << " years old.\n";


   return 0;
}
