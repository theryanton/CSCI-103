#include <iostream>
using namespace std;

int roll();
void printHistogram(int counts[]);

int roll()
{
  return rand() % 6 + 1;
}

void printHistogram(int counts[])
{
  for (int i=0; i<21; i++)
  {
    cout << i + 4 << ":";
    for (int j=0; j<counts[i]; j++)
    {
      cout << "X";
    }
    cout << "\n";
  }
}

int main() {
  srand (time(0));

  int counts[21];

  //initialize the elements of the array to 0
  for(int i=0; i<21; i++) {
    counts[i] = 0;
  }

  int dice, input;
  cin >> input;
  
  for (int i=0; i<input; i++)
  {
    dice = 0;
    for (int j=0; j<4; j++)
    {
      dice += roll();
    }
    counts[dice-4]+=1;
  }
  printHistogram(counts);
}