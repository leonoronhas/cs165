#include <iostream>
#include <string>

using namespace std;

struct Scripture
{
   string book;
   int chapter;
   int verse;
};

struct Insight
{
   Scripture scripture[3];
   string message[];   
};

void promptInsight(Scripture &scripture, Insight message[])
{
   for (int i = 0; i < 3; i++)
   {
      cout << "Enter insight for " << scripture[i].book << " " 
           << scripture[i].chapter << ":" << scripture[i].verse 
           << ": ";
      cin >> message[i].message;
   }
}
void promptScripture(Insight &scripture)
{
  for (int i = 0; i < 3; i++)
  {
     cout << "Please enter book: ";
     cin >> scripture.scripture[i].book;
     cout << "Please enter chapter: ";
     cin >> scripture.scripture[i].chapter;
     cout << "Please enter verse: ";
     cin >> scripture.scripture[i].verse;
  }    
}

void displayScripture(Scripture scripture[])
{
   for (int i = 0; i < 3; i++)
   {
      cout << scripture[i].book << " " << scripture[i].chapter << ":" 
           << scripture[i].verse << endl;
   }  
}

int main()
{
   Insight scripture;

   promptScripture(scripture);
 //  promptInsight(scripture, message);
 //  displayInsight(scripture, message);
 //  displayScripture(scripture);
   
   return 0;   
}
