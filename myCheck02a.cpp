/***********************************************************************
* Program:
*    Checkpoint 02a, Checkpoint 02a       (e.g. Checkpoint 01a, review)  
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

//structure for student
struct Student
{
   //gather all information for each student
   string firstName;
   string lastName;
   int id;   
};

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Student tempStudent;
   
   //Ask for the first name
   cout << "Please enter your first name: ";
   cin >> tempStudent.firstName;

   //Ask for the last name
   cout << "Please enter your last name: ";
   cin >> tempStudent.lastName;

   //Ask for the id
   cout << "Please enter your id number: ";
   cin >> tempStudent.id;
   cout << endl;
   
   //display the information provided
   cout << "Your information:\n" 
        << tempStudent.id << " - " << tempStudent.firstName << " " 
        << tempStudent.lastName << endl;

   return 0;
}
