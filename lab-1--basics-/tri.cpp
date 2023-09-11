#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  double i, columns,rows, userinput, tangent, flag=0;
  cout << "Enter a value for theta between 15 and 75:\n";
  cin >> userinput;

  for(rows=0;rows<31;rows++)
  {
    /*if (rows <=20 && rows >=10)
    {
      for (i=0; i<20; i++)
      {
        cout << "*";
      }
    }
    else
    {*/
    tangent = floor(rows*(tan(userinput * (M_PI / 180))));
    if (tangent >=20 && tangent <=30)
    {
      for (i=20; i>0; i--)
      {
        cout<< "*";
      }
      cout<<endl;
      tangent++;
    }
    else
    {
	    for(columns=(tangent+1);columns>0;columns--)
      {
        cout << "*";
      }
      tangent++;
	  cout<<endl;
    }
  }	
}

  /*
  for(rows=0;rows<31;rows++)
  {
	  for(columns=1;columns<rows;columns++)
	    cout<<"*";
	cout<<endl;
  }	
}
*/