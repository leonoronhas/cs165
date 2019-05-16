#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

//function to roll 5 dives
void doRoll(int dice[])
{
   for(int i = 0; i < 5; ++i)
   {
      dice[i] = (rand() % 6) + 1;
   }
   
}

bool isYahtzee(int dice[])
{
   for(int i = 1; i < 5; i++)
   {
      if (dice[0] != dice[i])
         return false;
   }
   return true;
}

void display(int rolls, int count)
{
   cout << "Number of rolls = " << rolls << endl;
   count << "Number of average = " << rolls / count << endl;:wq
}

int main()
{
   srand(time(0));

   int dice[5];
   int count = 0;
   doRoll(dice);
   

   for (int i =0; i < 999; i++)
   {
      do
      {
         count++;
         doRoll(dice);   
      }
      while (!isYahtzee(dice));
   }
   display(count, 1000);

   return 0;   
}
