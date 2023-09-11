#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  int x, hundreds, tens, ones;
  cout << "Enter an integer between 0 and 999:" << endl;
  cin >> x;
  
  ones = x%10;
  tens = (x/10)%10;
  hundreds = (x/100)%10;
   
  cout << "1's digit is " << ones << endl;
  cout << "10's digit is " << tens << endl;
  cout << "100's digit is " << hundreds;

}