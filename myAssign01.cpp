/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy  
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    This program will receive a single DNA marker that will allow a 
*    user to search for relatives based on his or her DNA marker and 
*    display the percentage number that indicates their similarities.
*    I will use several functions to help me remember how to use them
*    in the future.
*
*    Estimated:  3.0 hrs   
*    Actual:     5.0 hrs
*      Please describe briefly what was the most difficult part.
*      Putting everything together and making comparisons with the DNA
*      markers.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * This function will prompt the user to enter his or her single DNA 
 * marker.
 ***********************************************************************/
void getSingleDna(char dna[])
{
   cout << "Enter your DNA sequence: ";
   cin >> dna;
}

/**********************************************************************
 * This function will prompt the user for the number of relatives. We
 * assume the amount is less than fifty.
 ***********************************************************************/
void numbRelatives(int &relatives)
{
   cout << "Enter the number of potential relatives: ";
   cin >> relatives;
   cout << endl; //new line after set of questions
}

/**********************************************************************
 * This function will prompt the user for the names of all his or her
 * relatives.
 ***********************************************************************/
void relativeNames(char names[][10], int numbMembers)
{
   for (int i = 0; i < numbMembers; i++)
   {
      cout << "Please enter the name of relative #" << i + 1 << ": ";
      cin >> names[i];
   }
}

/**********************************************************************
 * This function will ask the user to enter the DNA marker for each 
 * relative.
 ***********************************************************************/
void getDnaRelatives(char names[][10], int numbRelatives, 
                     char relativeDna[][10])
{
   for (int i = 0; i < numbRelatives; i++)
   {
      cin.ignore();
      cout << "Please enter the DNA sequence for " << names[i] << ": ";
      cin >> relativeDna[i];
   }
}

/**********************************************************************
 * This function will calculate the match between the first DNA and the
 * relative DNAs..
 ***********************************************************************/
void calcMatch(char names[][10], char dna[], 
               char dnaRelatives[][10], 
               int numberOfRelatives)
{
   int count = 0;
   
   for (int i = 0; i < numberOfRelatives; i++)
   {
      count = 0;

      //compare the dna
      for (int j = 0; j < 10; j++)
      {
         if (dna[j] == dnaRelatives[i][j])
         {
            count++;
         }   
      }
      cout << "Percent match for " << names[i] << ": " << count * 10 
           << "%" << endl; 
   }
}

/**********************************************************************
 * Main will call the functions and have them do the work.
 ***********************************************************************/
int main()
{
   int relatives = 0;
   char dna[256];
   
   //get the DNA will be use for comparison
   getSingleDna(dna);
   
   //get the number of relatives
   numbRelatives(relatives);
   
   //will get the names of relatives according to the number of relatives
   char names[relatives][10];
   relativeNames(names, relatives);
   
   cout << endl; //line between set of questions
   
   //will get the dna for all relatives
   char dnaRelatives[relatives][10];
   getDnaRelatives(names, relatives, dnaRelatives);
   
   cout << endl; //line between set of questions

   //calculate the amount of DNA that matches the first DNA.
   calcMatch(names, dna, dnaRelatives, relatives);
   
   return 0;
}






