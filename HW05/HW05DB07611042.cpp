//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-11-21
//  FILENAME     : HW05DB07611042.CPP
//  DESCRIPTION  : Caesar Shift but not knowing k
//================================================================
#include <iostream>
#include <iomanip>
using namespace std;

int answer1;
char answer2;
char answer3;

int main()
{
	char code[38] = "GWC IZM ZMITTG I PIZL EWZSQVO ABCLMVB"; // encoded sentence
	for (int i = 1; i < 26; i++) // run 25 times to find all the possibility
	{
		for (int j = 0; j < 37; j++)
		{
			if (code[j] == ' ') // if encounter space, just remain the space
				code[j] = ' ';
			else
			{
				if (int(code[j] - 1) >= 65 && int(code[j] - 1) < 90) // if the alphabet is between 'B' to 'Z', then -1 to get the previous alphabet
					code[j] = code[j] - 1;
				else // if the alphabet is 'A', then the previous one is 'Z'
					code[j] = 'Z';
			}
		}
		cout << "Move " << setw(2) << i << "  " << code << endl;
	}
	// Because of the result, we can find 'Move 8' is a valid setence.
	answer1 = 8;
	answer2 = 'Y';
	answer3 = 'T'; 
	return 0;
}
