/* Ryan Ton
rton@usc.edu

This program is a BigInt library designed to:
1.) support arbitrary precision signed arithmetic
2.) support operator overloads for C++ math and comparison
3.) support any base within 2 and 36

*/

#include "bigint.h"
#include <iostream>
#include <string>
#include <climits>
#include <cmath>
using namespace std;

//******************************************************************
//START OF THE CONSTRUCTORS SECTION
//******************************************************************

/*
// Create a default BigInt with base 10.
// This function is complete. You do not have to add anything.
*/
BigInt::BigInt(){
  base = 10;
  isPositive = true;
}

/*
// Create a BigInt with a specified base.
// This function is complete. You do not have to add anything.
*/
BigInt::BigInt(int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    base = setbase;
    isPositive = true;
}

/*
// Destructure. You do not have to add anything.
// This function is complete
*/
BigInt::~BigInt(){}

/*
//  Create a BigInt from string.
//  Don't forget to set the base accordingly
//  The input string will contain
//      - numbers (0-9) and/or 
//      - uppercase letters (A-Z) [A=10, B=11, ... , Z=35]
//  The input string may contain
//      - a negative sign ('-') to signify that the number is negative.
//  Note: char '0' = int 48 (see ASCII table)
//  Note: char 'A' = int 65
*/
BigInt::BigInt(const string &s, int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    /************* You complete *************/
  base = setbase;
  int index = 0;
  if (s[0] == '-')
  {
    isPositive = false;
    index = 1;
  }
  else
  {
    isPositive = true;
  }
  for (int i=s.size()-1; i>=index; i--)
  {
    if (s[i] >= '0' && s[i] <= '9')
    {
      vec.push_back((int)(s[i]-48));
    }
    else if (s[i] >= 'A' && s[i] <= 'Z')
    {
      vec.push_back((int)(s[i]-55));
    }
  }
}


/*
//  Create a BigInt from int (base 10).
//  - Convert the int (base 10) input into a specified base (setbase).
//  - Don't forget to set the base accordingly
//  For example:
//     BigInt k(6,2) <- int 6 base 10 to BigInt base 2
//          - Result:  BigInt k with value 110 (base 2)
//     BigInt k(154,16) <- 154 base 10 to BigInt base 16
//          - Result: BigInt k with value 9A (base 16)
*/
BigInt::BigInt(int input,int setbase){
    if(setbase < 2 || setbase > 36){
        throw InvalidBaseException();
    }
    /************* You complete *************/
  base = setbase;
  if (input < 0)
  {
    isPositive = false;
    input *= -1;
  }
  else if (input > 0)
  {
    isPositive = true;
  }
  else
  {
    vec.push_back(input);
  }
  while (input != 0)
  {
    vec.push_back(input % base);
    input /= setbase;
  }
}

/*
//  Create a BigInt from another BigInt.
//  This is a copy constructor.
//  Simply call the assignment operator (=) below.
// (You can also think of this function as the same as the assignment operator (=))
// (but without a return statement because you are overriding the current object)
*/
BigInt::BigInt(const BigInt &b){

    /************* You complete *************/

  *this = b;

}

/*
//  Assignment operator. (i.e., BigInt a = b;)
//  OVERRIDING a's data with BigInt b's data
//       - vec
//       - isPositive
//       - base
*/
BigInt & BigInt::operator = (const BigInt &b){

    /************* You complete *************/

    vec = b.vec;
    isPositive = b.isPositive;
    base = b.base;
    return *this; 
}


//******************************************************************
//END OF THE CONSTRUCTORS SECTION
//******************************************************************

//******************************************************************
//START OF THE DISPLAYS SECTION
//******************************************************************

/*
// Convert to string and return the string
// Display it in its corresponding base
//  Note: char '0' = int 48 (see the ASCII table)
//  Note: char 'A' = int 65
*/
string BigInt::to_string(){

    /************* You complete *************/
  
  if (!vec.size())
  {
    return "0";
  }
  string converted = "";
  if (!isPositive)
  {
    converted += "-";
  }
  for (int i=vec.size()-1; i>=0; i--)
  {
    if (vec[i] >= 0 && vec[i] <= 9)
    {
      converted += (char)(vec[i]+48);
    }
    else
    {
      converted += (char)(vec[i]+55);
    }
  }
  return converted;

}

/*
//  Convert BigInt to integer base 10 and return that int
//    If BigInt >= INT_MAX, return INT_MAX.
//    If BigInt =< INT_MIN, return INT_MIN.
//  Note: 1. INT_MAX and INT_MIN are already defined for you
//           in the 'climits' library.
//        2. INT_MAX = 2147483647, INT_MIN = -2147483648
//           therefore, INT_MIN does not equal to (-INT_MAX)
*/
int BigInt::to_int() const{

    /************* You complete *************/
  long long converted = 0;
  for (int i=0; i<(int)vec.size(); i++)
  {
    converted += (vec[i] * pow(base, i));
  }
  if (!isPositive)
  {
    converted *= -1;
  }

  if (converted <= (long long)INT_MIN)
  {
    if (isPositive)
    {
      return INT_MAX;
    }
    return INT_MIN;
  }
  if (converted >= (long long)INT_MAX)
  {
    if (!isPositive)
    {
      return INT_MIN;
    }
    return INT_MAX;
  }
  return converted;
}

//******************************************************************
//END OF THE DISPLAYS SECTION
//******************************************************************

//******************************************************************
//START OF THE EQUALITY CHECK OPERATORS SECTION
//******************************************************************

/*
//  Compare a and b.
//     If a = b, return 0.
//     If a < b, return -1.
//     If a > b, return 1.
//  See the HINT below
*/
int BigInt::compare(const BigInt &b) const{
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/

    //HINT:
    //1. do NOT call the to_int() or to_string() function
    //2. do NOT convert bigInt to other datatypes first (e.g., long long, int)
    
    //First let's compare the signs
    //    - if the signs aren't the same,
    //              how do you know which one is larger?

    //If they have the same sign, let's compare their vec sizes 
    //    - what if both are positive, but a's vec is larger (a or b is larger?)
    //    - other cases?
    
    //If they have the same vec size, let's compare their digits one by one
    // Starting from the most-significant digits. --> in what vector position?
    // Remember that the BigInt vectors are in reverse order!
    //    - what if both are positive, but the digit of a is greater than that of b (a or b is larger?)
    //    - other cases?
    
    //If ALL digits are the same, then they MUST be equal!!

    if (isPositive != b.isPositive)
    {
      if (isPositive)
      {
        return 1;
      }
      else
      {
        return -1;
      }
    }
    else if (isPositive == true && b.isPositive == true)
    {
      if (vec.size() > b.vec.size())
      {
        return 1;
      }
      else if (vec.size() < b.vec.size())
      {
        return -1;
      }
      else
      {
        for (int i = vec.size()-1; i>=0; i--)
        {
          if (vec[i] > b.vec[i])
          {
            return 1;
          }
          else if (vec[i] < b.vec[i])
          {
            return -1;
          }
        }
      }
    }
    else if (isPositive == false && b.isPositive == false)
    {
      if (vec.size() > b.vec.size())
      {
        return -1;
      }
      else if (vec.size() < b.vec.size())
      {
        return 1;
      }
      else
      {
        for (int i = vec.size()-1; i>=0; i--)
        {
          if (vec[i] > b.vec[i])
          {
            return -1;
          }
          else if (vec[i] < b.vec[i])
          {
            return 1;
          }
        }
      }
    }
    return 0;
}


//Call the compare function above to check if a == b
bool operator == (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/

  if (a.compare(b) == 0)
  {
    return true;
  }
  return false;
}

//Call the compare function above to check if a != b
bool operator != (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/

  if (a.compare(b) == 0)
  {
    return false;
  }
  
  return true;
}

//Call the compare function above to check if a <= b
bool operator <= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/

  if (a.compare(b) < 1)
  {
    return true;
  }
  return false;
}

//Call the compare function above to check if a >= b
bool operator >= (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/

  if (a.compare(b) > -1)
  {
    return true;
  }
  return false;
}

//Call the compare function above to check if a > b
bool operator > (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/

  if (a.compare(b) == 1)
  {
    return true;
  }
  return false;
}

//Call the compare function above to check if a < b
bool operator < (const BigInt &a, const BigInt &b){
  
    /************* You complete *************/

  if (a.compare(b) == -1)
  {
    return true;
  }
  return false;
}

//******************************************************************
//END OF THE EQUALITY CHECK OPERATORS SECTION
//******************************************************************

//******************************************************************
//START OF THE ARITHMETIC OPERATORS SECTION
//******************************************************************

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call += operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator + (const  BigInt &a, const BigInt & b){

  /************* You complete *************/
  
  BigInt temp = a;
  temp += b;
  return temp;
}

/*
//==================
// MEMBER function
//==================
//  Addition assignment operator.
//    i.e., a += b
*/
const BigInt & BigInt::operator += (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
  while (vec.size() < b.vec.size())
  {
    vec.push_back(0); // adding 2 numbers that dont have the same amount of indexes
  }
  if (b.to_int() == 0) // adding 0, return original value
  {
    return *this;
  }
  if (isPositive == b.isPositive) // same sign
  {
    int carry = 0, sum = 0; // sum used to add all values together
    for (unsigned int i=0; i<vec.size(); i++)
    {
      if (i>b.vec.size()-1) // no more things to add in b
      {
        sum = vec[i] + carry;
      }
      else // if there are still values within the b vector to be added
      {
        sum = vec[i] + b.vec[i] + carry;
      }
      if (sum >= base) // greater than base (10), then carry over
      {
        vec[i] = sum%base;
        carry = sum/base;
      }
      else
      {
        vec[i] = sum;
        carry = 0;
      }
    }
    if (carry > 0)
    {
      vec.push_back(1);
    }
  }
  else if (isPositive != b.isPositive)
  {
    if (isPositive) // if a is positive while b is negative
    {
      BigInt temp = b; // can't change b
      temp.isPositive = true;
      *this -= temp;
    }
    else 
    {
      BigInt temp = b;
      temp.isPositive = false;
      *this -= temp;
    }
  }

  return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call -= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator - (const  BigInt &a, const BigInt & b){

  /************* You complete *************/
  
  BigInt temp = a;
  temp -= b;
  return temp;

}


/*
//==================
// MEMBER function
//==================
//  Subtraction assignment operator.
//    i.e., a -= b
//  Note: Think of base cases (e.g., subtract by itself)
*/
const BigInt & BigInt::operator -= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/
  int diff = 0, carry = 0;

  while (vec.size() < b.vec.size()) // number they're subtracting from has less indexes
  {
    vec.push_back(0);
  }

  if (isPositive == b.isPositive)
  {
    if ((isPositive && compare(b) == 1) || (!isPositive && compare(b) == -1)) // same signs and a is greater than b
    {
      for (unsigned int i=0; i<vec.size(); i++)
      {
        if (i>b.vec.size()-1)
        {
          diff = vec[i] - carry;
        }
        else
        {
          diff = vec[i] - b.vec[i] - carry;
        }
        carry = 0;
        if (diff<0)
        {
          carry = 1;
          diff += base;
        }
        vec[i] = diff;
      }
    }
    else
    {
      BigInt temp = b;
      for (unsigned int i=0; i<vec.size(); i++)
      {
        if (i>vec.size()-1)
        {
          diff = temp.vec[i] - carry;
        }
        else
        {
          diff = temp.vec[i] - vec[i] - carry;
        }
        carry = 0;
        if (diff<0)
        {
          carry = 1;
          diff += base;
        }
        temp.vec[i] = diff;
      }
      *this = temp;
      isPositive = !isPositive;
    }
    while (vec[vec.size()-1] == 0 && vec.size() > 1)
    {
      vec.pop_back();
    } 
  }
  else if (isPositive != b.isPositive)
  {
    if (isPositive)
    {
      BigInt temp = b;
      temp.isPositive = true;
      *this += temp;
    }
    else
    {
      BigInt temp = b;
      temp.isPositive = false;
      *this += temp;
    }
  }

  if (to_int() == 0) // has to be at bottom?
  {
    isPositive = true;
  } 
  
  return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call *= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator * (const  BigInt &a, const BigInt & b){

    /************* You complete *************/

    BigInt temp = a;
    temp *= b;

  return temp;
}



/*
//==================
// MEMBER function
//==================
//  Multiplication assignment operator.
//    i.e., a *= b
//  Implement Long Multiplication
//  Note: What are the base cases?? (e.g., multiply by 0)
*/
const BigInt & BigInt::operator *= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    /************* You complete *************/

    if (to_int() == 0) // multiply by 0
    {
      return *this;
    }
    else if (b.to_int() == 0)
    {
      *this = b;
      return *this;
    }

    bool productsign;
    if (isPositive != b.isPositive)
    {
      productsign = false;
    }
    else
    {
      productsign = true;
    }

    if (to_int() == 1)
    {
      vec = b.vec;
      isPositive = productsign;
      return *this;
    }
    else if (b.to_int() == 1)
    {
      isPositive = productsign;
      return *this;
    }
    
    BigInt tempsum(0, base);
    int carry = 0, product = 0;
    for (unsigned int i=0; i<b.vec.size(); i++)
    {
      string buffer(i, '0');
      BigInt temp(buffer, base);
      for (unsigned int j=0; j<vec.size(); j++)
      {
        product = carry + (b.vec[i] * vec[j]);
        carry = product / base;
        temp.vec.push_back(product % base);
      }
      if (carry != 0)
      {
        temp.vec.push_back(carry);
      }
      tempsum += temp;
      carry = 0;
    }
    *this = tempsum;
    isPositive = productsign;
    return *this;
    
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call /= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator / (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
  
    BigInt temp = a;
    temp /= b;
    return temp;
}


/*
//==================
// MEMBER function
//==================
//  Division assignment operator.
//    - Call 'divisionMain' to get the quotient;
*/
const BigInt & BigInt::operator /= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();
    }
    /************* You complete *************/

    BigInt quotient(base);
    BigInt remainder(base);
    divisionMain(b, quotient, remainder);
    *this = quotient;
  
    return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call %= operator on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt operator % (const  BigInt &a, const BigInt & b){

    /************* You complete *************/
  
    BigInt temp = a;
    temp %= b;
    
    return temp;
}


/*
//==================
// MEMBER function
//==================
//  Modulus assignment operator.
//    - Call 'divisionMain' to get the remainder;
//    - Note: remainder takes the sign of the dividend.
*/
const BigInt & BigInt::operator %= (const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(b.vec.size() == 1 && b.vec[0] == 0){
        throw DivByZeroException();//divide by zero.
    }
    /************* You complete *************/

    BigInt quotient(base);
    BigInt remainder(base);
    divisionMain(b, quotient, remainder);
    *this = remainder; 
  
    return *this;
}

/*
//  Main function for the Division (/=) and Modulus (%=) operators.
//     - Compute (q)uotient and (r)emainder
//     - Implement Long Division
//  Note: 1. This should behave like integer division
//        2. What are the base cases?? (e.g., div by itself)
*/
void BigInt::divisionMain(const BigInt &b, BigInt &quotient, BigInt &remainder){

    /************* You complete *************/

    bool quotientsign; // bool determines final sign
    if (isPositive != b.isPositive)
    {
      quotientsign = false;
    }
    else
    {
      quotientsign = true;
    }

    bool asign = isPositive; // copying a sign
    isPositive = true;
  
    BigInt zero(0, base);
    BigInt one(1, base);
    BigInt negone(-1, base);

    if (b.vec.size() == 1 && b.vec[0] == 1)
    {
      quotient = *this;
      quotient.isPositive = quotientsign;
      remainder = zero;
      return;
    }

    BigInt copyb(b); // we copy b as we are discouraged to change b itself
    copyb.isPositive = true;

    if (*this == copyb)
    {
      quotient = one;
      quotient.isPositive = quotientsign;
      remainder = zero;
      return;
    }

    if (*this < copyb)
    {
      quotient = zero;
      remainder = *this;
      remainder.isPositive = asign;
      return;
    }

    if(*this == zero)
    {
      quotient = zero;
      remainder = zero;
      remainder.isPositive = asign;
      return;
    }

    int index = vec.size() -1;
    BigInt curr (vec[index], base);
    while (curr<copyb)
    {
      index--;
      curr.vec.insert(curr.vec.begin(), vec[index]);
    }
    while (index >=0)
    {
      int counter = 0;
      while (curr >= copyb)
      {
        curr = curr - copyb;
        counter++;
      }
      quotient.vec.insert(quotient.vec.begin(), counter);
      if (curr.vec.size() ==1 && curr.vec[0] ==0)
      {
        curr.vec.pop_back();
      }
      if (index -1 >=0)
      {
        curr.vec.insert(curr.vec.begin(), vec[index-1]);
      }
      index--;
    }
    if (curr.vec.empty())
    {
      remainder.vec.push_back(0);
      remainder.isPositive = true;
    }
    else
    {
      remainder = curr;
      remainder.isPositive = asign;
    }
    quotient.isPositive = quotientsign;
}



/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call the 'exponentiation' function on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt pow(const  BigInt &a, const BigInt & b){

    /************* You complete *************/
    BigInt temp = a;
    temp.exponentiation(b);
    return temp;
}

/*
//==================
// MEMBER function
//==================
//  Exponentiation assignment function.
//     - i.e., a.exponentiation(b);
// Note: 1. implement Exponentiation by Squaring (see the writeup)
//       2. b should be treated as BigInt, not int or other data type.
*/
const BigInt & BigInt::exponentiation(const BigInt &b){
    if(base != b.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/
    BigInt result(1,base);
    BigInt exponent = b;

    BigInt zero(0, base);
    BigInt one(1, base);
    BigInt two(2, base);
  
    while (exponent > zero)
    {
      if (exponent%two == zero) // continue multiplying by itself 
      {
        *this *= *this;
        exponent/=two;
      }
      else // to power of 1 is itself
      {
        exponent-=one;
        result *= *this;
      }
    }
    *this = result;
    return *this;
}

/*
//======================
// NON-MEMBER function
//======================
// 1. Create a copy of a
// 2. Call the 'modulusExp' function on the copy and b
// 3. Return the copy
// Note: Should take you exactly 3 lines of code
*/
BigInt modPow(const BigInt &a, const BigInt &b, const BigInt &m){

    /************* You complete *************/
    BigInt temp = a;
    temp.modulusExp(b, m);
    return temp;
}


/*
//==================
// MEMBER function
//==================
//  Modulus Exponentiation assignment function.
//     - i.e., a.modulusExp(b)
// Note: 1. implement Modulus Exponentiation (see the writeup)
//       2. b should be treated as BigInt, not int or other data type.
// Hint: same implementation as exponentiation, but take modulus 
//          after every call to the *= operator.
*/
const BigInt & BigInt::modulusExp(const BigInt &b, const BigInt &m){
    if(base != b.base || base != m.base){
        throw DiffBaseException();
    }
    if(!b.isPositive){
        throw ExpByNegativeException();
    }
    /************* You complete *************/

    BigInt result (1, base);
    if (b.vec[0] == 0 && b.vec.size() ==1)
    {
      result = *this % b;
    }
    else if (b.vec[0] == 1 && b.vec.size() ==1)
    {
      result = *this % b;
    }
    else
    {
      BigInt exponent = b;

      BigInt zero (0, base);
      BigInt one (1, base);
      BigInt two (2, base);
    
      while (exponent > zero)
      {
        if (exponent % two == zero)
        {
          *this *= *this;
          *this %= m;
          exponent /= two;
        }
        else
        {
          exponent -= one;
          result *= *this;
          result %= m;
        }
      }
    }
    *this = result;
    return *this;
}

//******************************************************************
//END OF THE ARITHMETIC OPERATORS SECTION
//******************************************************************

//******************************************************************
//START OF SANITY CHECK FUNCTIONS
//YOU CAN USE THEM, BUT DO NOT CHANGE ANYTHING
//THESE FUNCTIONS ARE COMPLETE.
//******************************************************************
void BigInt::printVecItems(){
  cout<<"[";
  for(size_t i = 0;i<vec.size();i++){
    cout<<vec[i];
    if(i < vec.size()-1){
      cout<<",";
    }
  }
  cout<<"]"<<endl;
}

bool BigInt::getSign(){
	return isPositive;
}

int BigInt::getBase(){
	return base;
}
//******************************************************************
//END OF SANITY CHECKS SECTION
//******************************************************************