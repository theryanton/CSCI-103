#include <vector>
#include <iostream>
#include "bigint.h"


BigInt::BigInt(string s)
{
  for (int i=s.size()-1; i>=0; i--)
  {
    int strtodigit = (int)(s[i]-48);
    v.push_back(strtodigit);
  }
}

string BigInt::to_string()
{
  string s = "";
  for (int i=(int)v.size()-1; i>=0; i--)
  {
    char digittostr = (char)(v[i] +48);
    s += digittostr;
  }
  return s;
}

void BigInt::add(BigInt b)
{
  // while(v.size() > b.v.size()){
  //   b.v.push_back(0);
  // }
  // while(v.size() < b.v.size()){
  //   v.push_back(0);
  // }

  if (v.size() > b.v.size())
  {
    while (v.size() != b.v.size())
    {
        b.v.push_back(0);
    }
  }
  else if (v.size() < b.v.size())
  {
    while (v.size() != b.v.size())
    {
        v.push_back(0);
    }
  }
  int carryover = 0;
  for (unsigned int i=0; i<v.size(); i++)
  {
    int sum = v[i]+b.v[i]+carryover;
    //  v[i] = sum % 10;
    //  carryover = sum / 10;
    if(sum > 9)
    {
      v[i] = sum-10;
      carryover = 1;
    }
    else 
    {
      v[i] = sum;
      carryover =0;
    }
  }
  if (carryover > 0)
  {
    v.push_back(carryover);
  }
}