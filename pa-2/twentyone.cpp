/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA 2
*****************************************************************************/
/* Ryan Ton
rton@usc.edu
*/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these 
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/*
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  /******** You complete ****************/
 
  for (int i=0; i<=51; i++) // initiate deck of cards as integer values
  {
    cards[i] = i;
  }
  for (int i=51; i>0; i--) // uses a secondary array and temp variable to shuffle cards based on a random integer between 0-51
  {
    int j = rand()%(i+1);
    int temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
  }
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id)
{
  /******** You complete ****************/

 if (id >= 0 && id<=8)
 {
   cout << id+2 << "-H";
 }
 if (id >= 13 && id <= 21)
 {
   cout << id-11 << "-S";
 }
 if (id>= 26 && id <= 34)
 {
   cout << id-24 << "-D";
 }
 if (id >=39 && id<=47)
 {
   cout << id-37 << "-C";
 }
 if (id%13 == 9)
 {
   cout << "J-";
   if (id == 9)
   {
     cout << "H";
   }
   if (id == 22)
   {
     cout << "S";
   }
   if (id == 35)
   {
     cout << "D";
   }
   if (id==48)
   {
     cout << "C";
   }
 }
 if (id %13==10)
 {
   cout << "Q-";
   if (id == 10)
   {
     cout << "H";
   }
   if (id == 23)
   {
     cout << "S";
   }
   if (id == 36)
   {
     cout << "D";
   }
   if (id== 49)
   {
     cout << "C";
   } 
 }
 if (id%13 == 11)
 {
   cout << "K-";
   if (id == 11)
   {
     cout << "H";
   }
   if (id == 24)
   {
     cout << "S";
   }
   if (id == 37)
   {
     cout << "D";
   }
   if (id==50)
   {
     cout << "C";
   }
 }
 if (id % 13 == 12)
 {
   cout << "A-";
   if (id == 12)
   {
     cout << "H";
   }
   if (id == 25)
   {
     cout << "S";
   }
   if (id == 38)
   {
     cout << "D";
   }
   if (id==51)
   {
     cout << "C";
   }
 }
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
  /******** You complete ****************/
  for (int i=0; i<=8; i++) //If numeric card
  {
    if (id%13 == i)
    {
      return id%13 + 2;
    }
  }
  if (id%13 == 9 ||id%13 == 10 || id%13 == 11) // If face
  {
    return 10;
  }
  if (id%13 == 12) // If ace
  {
    return 11;
  }
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  /******** You complete ****************/
  for (int i=0; i<numCards; i++)
  {
    printCard(hand[i]);
    cout << " ";
  }
  cout << endl;
}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
  /******** You complete ****************/
  int sum = 0, acecount = 0;
  for (int i=0; i<numCards; i++)
  {
    int val = cardValue(hand[i]);
    if (val == 11)
    {
      acecount++;
    }
    sum += val;
  }

  while(acecount > 0)
  {
    if (sum > 21)
    {
      sum -= 10;
      acecount--;
    }
    else
    {
      break;
    }
  }
  return sum;
}

/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/

    while (1) // use this to loop game until quit
    {
      shuffle(cards);
      
      for (int i=0; i<9; i++) // initiates player and dealer hands to 0
      {
        dhand[i]=0;
        phand[i]=0;
      }
      phand[0]=cards[0];
      phand[1]=cards[2];
      dhand[0]=cards[1];
      dhand[1]=cards[3];

      char userinput;
      int cardcount = 4;
			int pcardcount = 2;
			int dcardcount = 2;
      int psum = getBestScore(phand, pcardcount); // current sum based on adding first 2 cards
      int dsum = getBestScore(dhand, dcardcount);

      cout << "Dealer: ? ";
      printCard(dhand[1]);
      cout << endl;
      cout << "Player: "; 
      printCard(phand[0]);
      cout << " ";
      printCard(phand[1]);
      cout << endl;

      if (psum == 21) // check 4: if player hits 21 automatically
      {
        while (dsum < 17) // still draws for dealer until standing at 17
        {
          dhand[dcardcount]=cards[cardcount]; 
          cardcount++;
          dcardcount++;
          dsum = getBestScore(dhand, dcardcount);
        }
        cout << "Dealer: ";
        printHand(dhand, dcardcount);
      }
      else
      {
        cout << "Type 'h' to hit and 's' to stay:" << endl;
        cin >> userinput;
        while (userinput == 'h') 
        {
          phand[pcardcount]=cards[cardcount];
          cardcount++;
          pcardcount++;
          cout << "Player: ";
          printHand(phand, pcardcount);
          psum = getBestScore(phand, pcardcount);
          
          if (psum>21) // check 1: automatic bust
          {
            break;
          }
          else if (psum >= 21) // check 6, 10
          {
            while (dsum < 17) // will stand at 17
            {
              dhand[dcardcount]=cards[cardcount];
              cardcount++;
              dcardcount++;
              dsum = getBestScore(dhand, dcardcount);
            } 
            cout << "Dealer: "; 
            printHand(dhand, dcardcount); 
            break;
          }
          else if (psum < 21) // gives player option to continue playing
          {
            cout << "Type 'h' to hit and 's' to stay:" << endl;
            cin >> userinput;
            if (userinput == 's')
            {
              break;
            }
            else if (userinput == 'h')
            {
              continue;
            }
          }
        }
        if (userinput == 's') // if player opts to stand
        {
          while (dsum < 17) // must stand at 17
          {
            dhand[dcardcount]=cards[cardcount]; 
            cardcount++;
            dcardcount++;
            dsum = getBestScore(dhand, dcardcount);
          } 
          cout << "Dealer: ";
          printHand(dhand, dcardcount);
        }
      }
      if (psum>dsum && psum>21) // player busts
      {
        cout << "Player busts" << endl;
        cout << "Lose " << psum << " " << dsum << endl;
      }
      if (psum>dsum && psum<=21) // player wins by numbers, under or equal to 21
      {
        cout << "Win " << psum << " " << dsum << endl;
      }
      if (psum==dsum)
      {
        cout << "Tie " << psum << " " << dsum << endl;
      }
      if (dsum>psum && dsum<=21) // dealer wins by numbers, under or equal to 21 
      {
        cout << "Lose " << psum << " " << dsum << endl;
      }
      if (dsum>psum && dsum>21) // dealer busts
      {
        cout << "Dealer busts" << endl;
        cout << "Win " << psum << " " << dsum << endl;
      }
      char replay;
      cout << endl << "Play again? [y/n]" << endl;
      cin >> replay;
      if (replay == 'y')
      {
        continue;
      }
      if (replay == 'n')
      {
        break;
      }
    }
  return 0;
}