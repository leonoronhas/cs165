/***********************************************************************
* Program:
*    CheckPoint 04a, Classes  
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    No summary required for checkpoints.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
class Book
{
private:
   string title;
   string author;

public:
   void prompt();
   void display();
   
};

void Book::prompt()   //the :: means calling the method(function)
{
   cout << "Title: ";
   getline(cin, title);
   cout << "Author: ";
   getline(cin, author);   
}

void Book::display() //the :: means calling the method(function)
{
   cout << "\"" << title << "\"" << " by " << author << endl;    
}


int main()
{
   Book book;
   book.prompt();
   book.display();

   return 0;
}
