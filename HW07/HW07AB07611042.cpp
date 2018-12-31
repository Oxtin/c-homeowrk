//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-12-26
//  FILENAME     : HW07AB07611042.CPP
//  DESCRIPTION  : Find the longest reversable word
//================================================================
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string data[50000]; // All words in words.txt

string Reverse[50000]; // All words that is reverse in words.txt

int dataNum = 0, answer1, answer2;

string longest_word;

void Rever(void); // the function that can reverse the word

int check_init(void); // to check if the reverse word is in the data

int main()
{
	string fileName = "words.txt";
	ifstream f1;
	string tmp;
	
	f1.open(fileName.c_str()); // read the file
	while (f1 >> tmp)
	{
		if (tmp[0] >= 'A' && tmp[0] <= 'Z') // if the first character is upper then change it into lower
			tmp[0] = tmp[0] + 32;
		data[dataNum] = tmp;
		dataNum++; // computer how many words in the data
	}
	f1.close();
	Rever();
	answer1 = dataNum;
	answer2 = check_init();
	cout << "The longest word that can be reverse is: " << longest_word << endl;
	cout << "There are " << answer1 << " words.\n";
	cout << "The longest word has " << answer2 << " characters.\n";
	return 0;
}

void Rever(void)
{
	for (int i = 0; i < dataNum; i++)
		Reverse[i] = string(data[i].rbegin(), data[i].rend());
}

int check_init(void)
{
	int Max = 0; // to store the number of the longest word
	for (int i = 0; i < dataNum; i++)
	{
		for (int j = 0; j < dataNum; j++)
		{
			if (Reverse[i] == data[j])
			{
				if (Reverse[i].length() > Max)
				{	
					Max = Reverse[i].length();
					longest_word = data[j];
				}
			}
		}
	}
	return (Max);
}

