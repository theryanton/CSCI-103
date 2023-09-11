/********************************************************
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  Failure to follow this direction will lead
 *   to a score of 0 on this part of the assignment.
 ********************************************************/

#include <iostream>
using namespace std;

int main()
{
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3
  unsigned int n1 = 0, n2 = 0, n3 = 0;
  int a1 = 0, a2 = 0, a3 = 0;

  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0;

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  /*====================*/
  /* Start of your code */
  /* Ryan Ton
  rton@usc.edu

  Code takes an input of a range of integers and enters a do while loop, iterating from 1 to the input and finding all its divisors. If sum of divisors is greater than input, count of abundant numbers is updated and is sorted via temporary variables
  */
  
  int input;

  do // enters while loop while input is not 0
  {
    cin >> input; // takes range of inputs
    int factors, tempsum =0;
    for (factors = 1; factors<input; factors++) // iterates up to (before) input, because even though input is a factor of itself, that would result in tempsum always being greater than input
    {
      if (input%factors ==0)
      {
        tempsum+=factors;
      }
    }
    if (tempsum > input)
    {
      num_abundant++;
      if (tempsum>a1) // swaps for max abundant number
      {
        a3=a2;
        a2=a1;
        a1 = tempsum;
        n3=n2;
        n2 = n1;
        n1 = input;
      }
      else if (tempsum>a2) // swaps for second most abundant number
      {
        a3=a2;
        a2=tempsum;
        n3=n2;
        n2 = input;

      }
      else if (tempsum>a3) // swaps for third most abundant number
      {
        a3 = tempsum;
        n3 = input;
      }
    }
  } 
  while (input !=0);
  /* End of your code */
  /*==================*/
  
  
  cout << "Abundant number count: " << num_abundant << endl;
  cout << "Top 3 most abundant numbers: " << endl;
  cout << n1 << " : " << a1 << endl;
  cout << n2 << " : " << a2 << endl;
  cout << n3 << " : " << a3 << endl;


  return 0;

}
