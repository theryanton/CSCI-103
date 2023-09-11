#include "bigint.h"
#include <iostream>
using namespace std;

int main() {
  BigInt b("123");
  cout << b.v[0] << endl;
  return 0;
}