/* Author: YOUR NAME HERE
 * Program: color_conv
 * Description: Converts RGB -> CMYK color representation
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   cout << "Enter 3 integers (red, green, and blue), in that order:" << endl;
   // Enter your code here
   double red, green, blue, white, cyan, magenta, yellow, black, max1, max2;
   cin >> red >> green >> blue;

   max1 = max(red/255, green/255);
   max2 = max (max1, blue/255);
   white = max2;
   //cout << max1 << " " << max2 << " " << white;

   cyan = (white-red/255)/white;
   magenta = (white-green/255)/white;
   yellow = (white-blue/255)/white;
   black = 1-white;

   cout << "cyan: " << cyan << endl;
   cout << "magenta: " << magenta << endl;
   cout << "yellow: " << yellow << endl;
   cout << "black: " << black << endl;
   
   return 0;
}