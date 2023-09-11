/* Author: YOUR NAME HERE
 * Program: compute_sin
 * Description: Reads a number x from input, an angle in radians. 
 *    Computes an approximation to sin(x) using an 4th-order Taylor series.
 */
#include <iostream>
#include <cmath>

using namespace std;

int fact(int); // declares a function the skeleton defines for you.

int main(int argc, char *argv[])
{
   // Declare any variables you need here
   double userinput, sum;

   // Prompt the user
   cout << "Enter x in radians:  ";

   // get input
   cin >> userinput;

   // Do some operations
   /*for (i=1; i<userinput; i+=2)
   {
      value = pow(-1, i-1) * (pow(userinput, i) / fact(i));
      sum += value;
   }*/

   sum = userinput - (pow(userinput, 3)/fact(3)) + (pow(userinput, 5)/fact(5)) - (pow(userinput, 7)/fact(7));
   
   // Print the result to the user
   cout << sum;
   
   // You're done
   return 0;
   
}

// here's the actual definition of fact, declared earlier.
int fact(int n)
{
   int result = 1;
   for (int i = 1; i <= n; i++) {
      result = result * i;
   }
   return result;
}

