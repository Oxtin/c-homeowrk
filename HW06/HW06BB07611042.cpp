//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-12-11
//  FILENAME     : HW06BB07611042.CPP
//  DESCRIPTION  : Morse_Cord
//================================================================
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int answer1, answer2;

string Code(char a) // Change the charactr in a word into a corresponding Morse_Code
{
	if (a == 'a' || a == 'A')
		return (".-");
	else if (a == 'b' || a == 'B')
		return ("-...");
	else if (a == 'c' || a == 'C')
		return ("-.-.");
	else if (a == 'd' || a == 'D')
		return ("-..");
	else if (a == 'e' || a == 'E')
		return (".");
	else if (a == 'f' || a == 'F')
		return ("..-.");
	else if (a == 'g' || a == 'G')
		return ("--.");
	else if (a == 'h' || a == 'H')
		return ("....");
	else if (a == 'i' || a == 'I')
		return ("..");
	else if (a == 'j' || a == 'J')
		return (".---");
	else if (a == 'k' || a == 'K')
		return ("-.-");
	else if (a == 'l' || a == 'L')
		return (".-..");
	else if (a == 'm' || a == 'M')
		return ("--");
	else if (a == 'n' || a == 'N')
		return ("-.");
	else if (a == 'o' || a == 'O')
		return ("---");
	else if (a == 'p' || a == 'P')
		return (".--.");
	else if (a == 'q' || a == 'Q')
		return ("--.-");
	else if (a == 'r' || a == 'R')
		return (".-.");
	else if (a == 's' || a == 'S')
		return ("...");
	else if (a == 't' || a == 'T')
		return ("-");
	else if (a == 'u' || a == 'U')
		return ("..-");
	else if (a == 'v' || a == 'V')
		return ("...-");
	else if (a == 'w' || a == 'W')
		return (".--");
	else if (a == 'x' || a == 'X')
		return ("-..-");
	else if (a == 'y' || a == 'Y')
		return ("-.--");
	else if (a == 'z' || a == 'Z')
		return ("--..");
	else if (a == '0')
		return ("-----");
	else if (a == '1')
		return (".----");
	else if (a == '2')
		return ("..---");
	else if (a == '3')
		return ("...--");
	else if (a == '4')
		return ("....-");
	else if (a == '5')
		return (".....");
	else if (a == '6')
		return ("-....");
	else if (a == '7')
		return ("--...");
	else if (a == '8')
		return ("---..");
	else if (a == '9')
		return ("----.");
	else if (a == '.')
		return (".-.-.-");
	else if (a == ',')
		return ("--..--");
	else if (a == '?')
		return ("..--..");
	else
		return (NULL);
}

string Change_Word(string s1, int len)
{
	string s2, Space = " "; // change into the Morse_Code and add a space to every character
	for (int i = 0; i < len - 1; i++)
		s2.append(Code(s1[i]) + Space);
	s2.append(Code(s1[len - 1])); // But the last character don't need the space
	return (s2);
}

int Num_Char(string s, int len) // compute how many character in a word
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != ' ' && s[i] != ',' && s[i] != '.') // Excluding space, comma, and period
			sum++;
	}
	return (sum);
}

int main()
{
	int index = 0, Char = 0;
	ifstream Infile;
	ofstream Outfile;
	string InName = "MorseCode.txt", OutName = "MorseCode.dat", Word;
	Infile.open(InName.c_str()); // open the file we want to read
	Outfile.open(OutName.c_str()); // open the file we want to write
	while (Infile.good())
	{
		if (Infile >> Word) // Read a word
		{
			index++; // compute how many words there are
			Char += Num_Char(Word, Word.length()); // compute how many characters there are
		}
		if (Infile.peek() == EOF) // the last word don't need the three spaces
		{
			Outfile << Change_Word(Word, Word.length()) << endl;
			cout << Change_Word(Word, Word.length()) << endl;
		}
		else
		{
			Outfile << Change_Word(Word, Word.length()) << "   ";
			cout << Change_Word(Word, Word.length()) << "   ";
		}
	}
	Infile.close(); // close the read file
	Outfile.close(); // close the written file
	answer1 = index;
	answer2 = Char;
	return 0;
}
