/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

// For this assignment, for simplicity, you may put all of your classes
// in this file.

// TODO: Define your Book class here
class Book
{
   private:

   protected:
      
      string title;
      string author;
      int publicationYear;

   public:
      
      Book(){
      
         title = "";           //no value yet
         author = "";          //no value yet
         publicationYear = 0;  //no value yet 
      }
      
      //Method to prompt the user for the book info
      void promptBookInfo() {
         
         //prompt for the title and store it in title
         cout << "Title: ";
         getline(cin, title);   

         //prompt for the author and store it in author
         cout << "Author: ";
         getline(cin, author);

         //prompt for the public. year and store it in public. year.
         cout << "Publication Year: ";
         cin >> publicationYear;
      
         cin.ignore(256, '\n'); //dont forget to clear cin.
      }
      
      //Method to display the book info. 
      void displayBookInfo() const{
         
         cout << title << " " << "(" << publicationYear << ")" 
              << " by " << author << endl;
      }
};

// TODO: Define your TextBook class here
class TextBook : public Book
{
   private:

      Book book;
      string subject;

   public:

      TextBook() : Book(){
         
         subject = "";   
      }

      //Method that prompt for the subject of the book
      void promptSubject(){
         
         //call promptBookInfo from the book class
         book.promptBookInfo();

         //prompt for the subject
         cout << "Subject: ";
         getline(cin, subject);
      }
      
      //Method to diplay the subject
      void displaySubject() const{
         
         book.displayBookInfo();
         cout << "Subject: " << subject << endl;
      }
   
};

// TODO: Add your PictureBook class here
class PictureBook : public Book
{
   private:

      Book book;      
      string illustrator;

   public:
      
      PictureBook() : Book(){
         
         illustrator = "";
      }

      //Method to prompt for the illustrator
      void promptIllustrator(){
         
         //Call the book method here
         book.promptBookInfo();
            
         cout << "Illustrator: ";
         getline(cin, illustrator);
      }

      //Method to display the illustrator
      void displayIllustrator() const{
         
         book.displayBookInfo();
         cout << "Illustrated by " << illustrator << endl;   
      }

   
};


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare a Book object here and call its methods
   Book book;
   
   book.promptBookInfo();
   cout << endl;
   book.displayBookInfo();
   cout << endl;
   
   // Declare a TextBook object here and call its methods
   TextBook textBook;
   
   textBook.promptSubject();
   cout << endl;
   textBook.displaySubject();
   cout << endl;

   // Declare a PictureBook object here and call its methods
   PictureBook picBook;

   picBook.promptIllustrator();
   cout << endl;
   picBook.displayIllustrator();

   return 0;
}


