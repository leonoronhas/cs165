/**********************************************************************
 * File: ta03.cpp
 * Author: Br. Burton
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

/***********************************************************************
 * Struct: Scripture
 * Description: Holds the reference to a scripture (book, chapter, verse
 ***********************************************************************/
struct Scripture
{
   string book;
   int chapter;
   int verse;
};

/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/
void display(const Scripture &scripture)
{
   cout << scripture.book << " ";
   cout << scripture.chapter << ":";
   cout << scripture.verse;
}

void getFileName()
{
   string filename;
   cout << "Enter filename: ";
   cin >> filename;
}

void readFile(string filename, int lines)
{
   string scripture;

   //open the file
   ifstream fin(filename);

   if (fin.fail())
      cout << "Cannot read file. " << filename << endl;
   
   //read the file
   int count = 0;
   while (!fin.eof())
   {
      getline(fin, scriptures);
      count++;
      lines = count;   
   }
   
   //close the file
   fin.close();
}
/***********************************************************************
 * Function: main
 * Description: The driver for the program.
 ***********************************************************************/
int main()
{
   Scripture scripture;

   int lines;
   string filename;
   
   filename = getFilename();
   readFile (filename, lines);
   display (scripture)

   return 0;
}
