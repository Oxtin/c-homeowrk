//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018--
//  FILENAME     : HW05AB07611042.CPP
//  DESCRIPTION  : Caesar shift
//================================================================
#include <iostream>
using namespace std;

char answer1;
char answer2;

int main()
{
	char decode[27] = "UVWXYZABCDEFGHIJKLMNOPQRST"; // when k = -6, the alphabet order. 
	char s[36] = "O RUBK IUSVAZKX VXUMXGSSOTM YU SAIN"; // encoded sentence.
	for (int i = 0; i < 35; i++)
	{	if (s[i] == ' ') // when encounter space just fill in space.
			s[i] = ' ';
		else
			s[i] = decode[s[i] - 65]; // the ascii of the character -65 is the alphabet order in k = -6.
	}
	for (int i = 0; i < 35; i++) // print the result
		cout << s[i];
	cout << endl;
	answer1 = s[0];
	answer2 = s[34];
	return 0;
}
