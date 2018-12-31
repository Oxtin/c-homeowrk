//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-12-12
//  FILENAME     : HW06CB07611042.CPP
//  DESCRIPTION  : Pangram Checker
//================================================================
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int answer1, answer2;

bool PangramCheck(string s)
{
	int Len = s.length(); // The length of the string
	int Char[26] = {0}; // create a array to record if the character has appeared
	for(int i = 0; i < Len; i++)
	{
		if (s[i] == 'a' || s[i] == 'A') // record the corresponding number of the characters
			Char[0]++;
		else if (s[i] == 'b' || s[i] == 'B')
			Char[1]++;
		else if (s[i] == 'c' || s[i] == 'C')
			Char[2]++;
		else if (s[i] == 'd' || s[i] == 'D')
			Char[3]++;
		else if (s[i] == 'e' || s[i] == 'E')
			Char[4]++;
		else if (s[i] == 'f' || s[i] == 'F')
			Char[5]++;
		else if (s[i] == 'g' || s[i] == 'G')
			Char[6]++;
		else if (s[i] == 'h' || s[i] == 'H')
			Char[7]++;
		else if (s[i] == 'i' || s[i] == 'I')
			Char[8]++;
		else if (s[i] == 'j' || s[i] == 'J')
			Char[9]++;
		else if (s[i] == 'k' || s[i] == 'K')
			Char[10]++;
		else if (s[i] == 'l' || s[i] == 'L')
			Char[11]++;
		else if (s[i] == 'm' || s[i] == 'M')
			Char[12]++;
		else if (s[i] == 'n' || s[i] == 'N')
			Char[13]++;
		else if (s[i] == 'o' || s[i] == 'O')
			Char[14]++;
		else if (s[i] == 'p' || s[i] == 'P')
			Char[15]++;
		else if (s[i] == 'q' || s[i] == 'Q')
			Char[16]++;
		else if (s[i] == 'r' || s[i] == 'R')
			Char[17]++;
		else if (s[i] == 's' || s[i] == 'S')
			Char[18]++;
		else if (s[i] == 't' || s[i] == 'T')
			Char[19]++;
		else if (s[i] == 'u' || s[i] == 'U')
			Char[20]++;
		else if (s[i] == 'v' || s[i] == 'V')
			Char[21]++;
		else if (s[i] == 'w' || s[i] == 'W')
			Char[22]++;
		else if (s[i] == 'x' || s[i] == 'X')
			Char[23]++;
		else if (s[i] == 'y' || s[i] == 'Y')
			Char[24]++;
		else if (s[i] == 'z' || s[i] == 'Z')
			Char[25]++;
	}
	for (int i = 0; i < 26; i++) // if all of the character have appeared, then return true; otherwise, return false
	{
		if (Char[i] == 0)
			return (false);
	}
	return (true);
}

int main()
{
	string FileName = "PangramList.txt";
	string sentence;
	int T_sum = 0, N_sum = 0; // to record the number of the Pangram sentences
	ifstream Infile(FileName.c_str());
	while (Infile.peek() != EOF)
	{
		getline(Infile, sentence); // read a line every time	
		if (PangramCheck(sentence)) // Is a Pangram sentence
			T_sum++;
		else // not a Pangram sentence
			N_sum++;
	}
	Infile.close();
	answer1 = N_sum;
	answer2 = T_sum;
	return 0;
}
