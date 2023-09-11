#include <iostream>
using namespace std;

int main();
void prime (int &x);

int main()
{
  int userinput;
  cout << "Enter a positive integer:\n";
  cin >> userinput;
  while (1)
  {
    prime(userinput);
    return 0;
  }
}

void prime (int &x)
{
  int temp, count2, count3;
  if (x < 2)
  {
    cout << "Please try a different integer.\n";
    return;
  }
  else
  {
    temp = x;
    int flag1 = 0;
    while (temp%3==0)
    {
      count3++;
      flag1++;
      temp = temp/3;
      if (flag1 > 50)
      {
        break;
      }
    }
    int flag2 = 0;
    while (temp%2==0)
    {
      count2++;
      flag2++;
      temp = temp/2;
      if (flag2>50)
      {
        break;
      }
    }
    if (temp==1)
    {
      cout << "Yes\n";
      cout << "Twos=" << count2 << " Threes=" << count3 << "\n";
    }
    else
    {
      cout << "No\n";
    }
  }
  return;
}