// Ryan Ton
// rton@usc.edu
// Code uses a while loop to count the amount of steps it takes to hit 1, using if statements to divide by 2 if even and multiply by 3 and add 1 if odd

#include <iostream>
using namespace std;

int main()
{
  int p, q=0;
  cout << "Enter a number: ";
  cin >> p;
  while (p !=1)
  {
    if (p%2 ==0)
    {
      q++;
      p =p/2;
      cout << p;
    }
    else
    {
      q++;
      p=p * 3+1;
      cout << p;
    }
  }
  cout << "\nLength: " << q;
  return 0;
}