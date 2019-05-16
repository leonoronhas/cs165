/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Comeau, CS165
* Author:
*    Leonardo Santos
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

// TODO: Define your Complex struct here
struct Complex
{
   double c1;
   double c2;  
};

// TODO: Add your prompt function here
void prompt(Complex &number)
{
   cout << "Real: ";
   cin >> number.c1;

   cout << "Imaginary: ";
   cin >> number.c2;
   
}

// TODO: Add your display function here
void display(Complex &number)
{
   cout << number.c1 << " + " << number.c2 << "i";   
}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex & x, const Complex & y)
{
   // TODO: Fill in the body of the add function
   Complex sum;

   sum.c1 = x.c1 + y.c1;
   sum.c2 = x.c2 + y.c2;

   return sum;
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
   Complex real;
   Complex imag;

   // Call your prompt function twice to fill in c1, and c2 
   prompt(real);
   prompt(imag);

   // Declare another Complex for the sum
   Complex sum;

   // Call the addComplex function, putting the result in sum;
   sum = addComplex(real, imag);
   
   cout << "\nThe sum is: ";
   display(sum);
   cout << endl;
 
   return 0;
}


