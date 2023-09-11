/* Ryan Ton
 rton@usc.edu
 Given a lower and an upper bound, using the prior hailstone code, we expand it and use a counter to count the length of each inputs, initializing new variables to also keep track of the shortest and longest length
 */

#include <iostream>
using namespace std;

int main()
{
  int lower, upper, x, max=0, min=500000;
  cout << "Enter the range that you want to search: ";
  cin >> lower >> upper;
  int minNum, maxNum;
  
  if (lower>upper)
  {
    cout << "Invalid range";
  }
  else
  {
    for (int i = lower; i<=upper; i++)
    {
      int count=0;
      x = i;
      while(x != 1){
        if (x %2 ==0)
        {
          x = x/2;
          count++;
        }
        else
        {
          x= x * 3+1;
          count++;
        }
      }
      if (count>max)
      {
        max=count;
        maxNum = i;
      }
      if (min>count)
      {
        min =count;
        minNum = i;
      }
    }
  }
  cout << "Minimum length: " << min << "\nAchieved by: " << minNum << "\n";
  cout << "Maximum length: " << max << "\nAchieved by: " << maxNum << "\n";
  return 0;
}