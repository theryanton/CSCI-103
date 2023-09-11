// game.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter

  for (int i=0; i<strlen(targetWord); i++)
  {
    word[i] = '*';
  }
  word[strlen(targetWord)] = '\0'; // set last char in a string to null to avoid garbage data

  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed

  cout << "Current word: " << word << endl;
  cout << "10 remain...Enter a letter to guess:" << endl;

  while (numTurns>0 && wordGuessed == false)
  {
    cin >> guess;
    int found = processGuess(word, targetWord, guess);
    if (found == 0) // if user inputted letter is wrong
    {
      numTurns--;
      if (numTurns == 0) // if no more tries left
      {
        break;
      }
      else // if user still has remaining turns
      {
        cout << "Current word: " << word << endl;
        cout << numTurns << " remain...Enter a letter to guess:" << endl;
        continue;
      }
    }
    else // if user inputted letter is correct
    {
      for (int i=0; i<strlen(targetWord); i++)
      {
        if (targetWord[i] == guess)
        {
          word[i] = guess; // change asterisk to user's correct guessed letter
        }
      }
      if (strcmp(targetWord, word) != 0) // if entire word isn't guessed yet
      {
        cout << "Current word: " << word << endl;
        cout << numTurns << " remain...Enter a letter to guess:" << endl;
        continue;
      }
      else // user guessed whole word
      {
        wordGuessed = true;
      }
    }
  }

  // Print out end of game status
  if (wordGuessed == true)
  {
    cout << "The word was: " << targetWord << ". You win!" << endl;
  }
  else 
  {
    cout << "Too many turns...You lose!" << endl;
  }
  
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  int count;
  for (int i=0; i<strlen(targetWord); i++)
  {
    count = 0;
    if (targetWord[i] == guess)
    {
      count++;
      return count;
    }
  }
  return 0;
}