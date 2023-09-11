/********************************************************
 * Description:
 *  Displays a 64-bit integer (long long) with
 *   commas for thousands, millions, billions, etc.
 *
 * ** ABSOLUTELY NO ARRAYS, NO `string`, NO `vector` **
 *  usage is allowed.
 *
 * Instead, you may only declare:
 *
 *    bool,
 *    int, or
 *    int64_t (long long)
 *
 *  The only library function allowed is pow(base, exp)
 *    defined in the <cmath> library.
 *
 ********************************************************/
// Ryan Ton
// rton@usc.edu

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  long long n;
  //cout << "Enter an integer:" << endl;
  /*====================*/
  /* Start of your code */
    cin >> n;
    int input = n;
    int count;

    if (n==0) // if 0
    {
      cout << "0";
    }

    if (n<0) // swaps negative sign
    {
      cout << "-";
      n *= -1;
    }

    while (input!=0) // iterates to count digits in input
    {
      input/=10;
      count++;
    }
    
    int tempcount = count;
    long long divisor;
    int offset = count %3; // count of digits modulus 3
    int index = 1;

    while (tempcount != 0)
    {
      divisor = pow(10,tempcount-1);
      cout << n/divisor;
      n %= divisor;
      if (index % 3 == offset) // if index which increments = amount of digits modulus 3, comma is placed
      {
        cout << ",";
      }
      tempcount--;
      index++;
    }
  

  /* End of your code */
  /*==================*/
  
  return 0;
}
