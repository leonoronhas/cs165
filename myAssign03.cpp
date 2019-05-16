/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics with corrupted files   
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    This program will scan through a log to identify users who 
*    accessed files in a window of time.
*
*    Estimated:  3.0 hrs   
*    Actual:     9.0 hrs
*      Please describe briefly what was the most difficult part.
*      The most difficult part was getting all the structs to work
*      together with the functions.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
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
}

/**********************************************************************
 * This function will prompt the user for the time stamp.
 ***********************************************************************/
void timePrompt(UserInfo &time)
{
   cout << endl;
   cout << "Enter the start time: ";
   cin >> time.startTime;
   cout << "Enter the end time: ";
   cin >> time.endTime;
}

/**********************************************************************
 * This function will read the file line by line.
 ***********************************************************************/
void parseLine(string line, AccessRecord record[500], int i)
{
   stringstream buffer(line);

   try
   {
      
      buffer >> record[i].fileName;
      buffer >> record[i].username;
      buffer >> record[i].timeStamp;
 
      if (buffer.fail() || record[i].timeStamp < 1000000000 
                        || record[i].timeStamp > 10000000000)
         throw string(line);   
   }
   catch (string line)
   {
      cout << "Error parsing line: " << line << endl;   
   }
}

/**********************************************************************
 * This function will display the lines set by the start and end time.
 ***********************************************************************/
void displayLines(string line, AccessRecord record[500], int i, 
                  UserInfo &info)
{
   stringstream buffer(line);
        
   buffer >> record[i].fileName;
   buffer >> record[i].username;
   buffer >> record[i].timeStamp;
   
   if (i == 0)
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
   }
      
   if (record[i].timeStamp >= info.startTime 
      && record[i].timeStamp <= info.endTime)
   {
      cout << setw(15) << record[i].timeStamp 
           << setw(20) << record[i].fileName 
           << setw(20) << record[i].username << endl;
   }
     
} 

/**********************************************************************
 * This function will parse the file and read it accordingly.
 ***********************************************************************/
void getResults(UserInfo &info, AccessRecord record[500])
{
   ifstream fin(info.read);
   string line;

   if (fin.fail())
   {
      cout << "Unable to open file: " << info.read << endl;
      return;   
   }
   
   int i = 0;
   while (getline(fin, line))
   {
      displayLines(line, record, i, info);
      i++;
   }
  
   //close the file
   fin.close();
}

/**********************************************************************
 * This function will parse the file and read it accordingly.
 ***********************************************************************/
void parseFile(UserInfo &info, AccessRecord record[500])
{
   ifstream fin(info.read);
   string line;

   if (fin.fail())
   {
      cout << "Unable to open file: " << info.read << endl;
      return;   
   }
   
   int i = 0;
   while (getline(fin, line))
   {
      parseLine(line, record, i);
      i++;
   }
  
   //close the file
   fin.close();
}

/**********************************************************************
 * Main will be the driver function.
 ***********************************************************************/
int main()
{
   AccessRecord record[500];
   UserInfo user;

   getFileName(user);
   parseFile(user, record);
   timePrompt(user);
   getResults(user, record);
   cout << "End of records" << endl;

   return 0;
}










