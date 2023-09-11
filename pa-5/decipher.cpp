/* Ryan Ton
rton@usc.edu

This program is using the prior designed BigInt library 
to decipher secret input files provided to us.

*/

#include "bigint.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout<<"\033[1;41m----Missing an argument----\033[0m"<<endl;
	  cout << "Usage: ./decipher <file>"<<endl;
	  cout << "Examples:" << endl;
	  cout << "\t./decipher secret/message1.txt \033[1;90m//to decipher message 1\033[0m" << endl;
	  cout << "\t./decipher secret/message2.txt \033[1;90m//to decipher message 2\033[0m"<<endl;
		return -1;
	}

	/************* You complete *************/
	try
	{
		ifstream infile;
		infile.open(argv[1]);
		if (infile.fail())
		{
			cout << "Error opening file." << endl;
		}

		int base;
		string d, n, secret_code;
		BigInt unscrambled;
		infile >> base >> d >> n;
		BigInt D(d, base); // cast string to big int
		BigInt N(n, base);

		while (infile >> secret_code)
		{
			BigInt scrambled(secret_code, base);
			unscrambled = modPow(scrambled, D, N);
			cout << (char)unscrambled.to_int();
		}
		cout << endl;
	}
  catch (const exception &excep)
	{
		cout << excep.what() << endl;
		return -1;
	}
	return 0;
}
