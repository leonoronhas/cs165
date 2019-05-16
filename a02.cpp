/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics     
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    This program will scan through a log to identify users who 
*    accessed files in a window of time.
*
*    Estimated:  3.0 hrs   
*    Actual:     5.0 hrs
*      Please describe briefly what was the most difficult part.
*      The most difficult part was getting all the structs to work
*      together with the functions.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Struct that contains the basic info required.
struct AccessRecord
{
   char username[256];
   char fileName[256];
   long int timeStamp;   
};

//Struct that contains the info the user in question.
struct UserInfo
{
   long int startTime;
   long int endTime;
   char read[256];
   int fileLength;
   int results[500];
   int numbResults;   
};

/**********************************************************************
 * This function will get the file name from the user.
 ***********************************************************************/
void getFileName(UserInfo &file)
{
   cout << "Enter the access record file: ";
   cin >> file.read;
   cout << endl;
}

/**********************************************************************
 * This function will prompt the user for the time stamp.
 ***********************************************************************/
void timePrompt(UserInfo &time)
{
   cout << "Enter the start time: ";
   cin >> time.startTime;
   cout << "Enter the end time: ";
   cin >> time.endTime;
}

/**********************************************************************
 * This function will read the file 
 ***********************************************************************/
void readFile(UserInfo &file, AccessRecord record[500])
{
   ifstream fin(file.read);
   if (fin.fail())
   {
      cout << "Unable to open file " << file.read << endl;
      return;
   }

   //read the data
   int i = 0;
   while (!fin.eof())
   {   
      fin >> record[i].username;
      fin >> record[i].fileName;
      fin >> record[i].timeStamp;
      file.fileLength = i;
      i++;
   }
   
   //close the file
   fin.close();

   return;
}

/**********************************************************************
 * This function will search for the files that were accessed by the
 * start and end time stamp.
 ***********************************************************************/
void searchFile(UserInfo &file, AccessRecord record[500])
{
   int j = 0;
   for (int i = 0; i < file.fileLength; i++)
   {
      if (record[i].timeStamp >= file.startTime && 
          record[i].timeStamp <= file.endTime)
      {
         file.results[j] = i;
         j++;   
      }   
   }
   file.numbResults = j;
}

/**********************************************************************
 * This function will display the information from the file.
 ***********************************************************************/
void display(AccessRecord record[500], UserInfo &info)
{
   cout << endl;
   cout << "The following records match your criteria:\n";
   cout << endl;
   cout << setw(15) << "Timestamp"
        << setw(20) << "File"
        << setw(21) << "User\n";
        
   cout << "--------------- "
        << "------------------- "
        << "-------------------\n";
   
   for (int i = 0; i < info.numbResults; i++)
   {   
      int j = info.results[i];
      cout << setw(15) << record[j].timeStamp 
           << setw(20) << record[j].username 
           << setw(20) << record[j].fileName << endl;
   }
   cout << "End of records" << endl;
}

/**********************************************************************
 * Main will be the driver function.
 ***********************************************************************/
int main()
{
   AccessRecord record[500];
   UserInfo user;

   getFileName(user);
   timePrompt(user);
   readFile(user, record);
   searchFile(user, record);
   display(record, user);
   
   return 0;
}











