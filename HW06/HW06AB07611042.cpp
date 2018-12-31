//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-12-10
//  FILENAME     : HW06AB07611042.CPP
//  DESCRIPTION  : Bridge card game
//================================================================
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

int answer1, answer2, answer3, answer4;

int High_Card_Value(int a[]) // compute the high card value
{
	int sum = 0;
	for (int i = 0; i < 13; i++)
	{
		if (a[i] == 1)
			sum += 4;
		else if (a[i] == 13)
			sum += 3;
		else if (a[i] == 12)
			sum += 2;
		else if (a[i] == 11)
			sum += 1;
	}
	return (sum);
}
	
int main()
{
	int card[52];
	int first[13], second[13], third[13], forth[13];
	int Fir_Val, Sec_Val, Thi_Val, For_Val, tmp, b; 
	string filename = "CardGame.txt";
	ofstream Outfile;
	srand(time(0));
	
	for (int r = 0; r < 3; r++)
	{
		Outfile.open(filename.c_str(), ios::app); // open file, and append data 
		Outfile << r + 1 << "Round" << endl;
		cout << r + 1 << "Round" << endl;
		for (int i = 0; i < 52; i++) // put 1 to 52 to the card array
			card[i] = i + 1;
		for (int i = 0; i < 52; i++) // shuffle the card 52 times
		{
			b = rand() % 52; // choose a position randomly
			tmp = card[i]; // change the card position
			card[i] = card[b];
			card[b] = tmp;
		}
		for (int i = 0; i < 52; i++) // convert (1 to 52) to four (1 to 13)
			card[i] = (card[i] - 1) % 13 + 1;
		Outfile << "Player 1:" << endl;
		cout << "Player 1:" << endl;
		for (int i = 0; i < 13; i++) // fill in the corresponding array and write in and cout
		{
			first[i] = card[i];
			Outfile << first[i] << " ";
			cout << first[i] << " ";
		}
		Outfile << endl;
		cout << endl;
		Fir_Val = High_Card_Value(first);
		Outfile << "High card value is: " << Fir_Val << endl;
		cout << "High card value is: " << Fir_Val << endl;
		
		Outfile << "Player 2:" << endl; // the same as Player1
		cout << "Player 2:" << endl;
		for (int i = 13; i < 26; i++)
		{
			second[i - 13] = card[i];
			Outfile << second[i - 13] << " "; 
			cout << second[i - 13] << " ";
		}
		Outfile << endl;
		cout << endl;
		Sec_Val = High_Card_Value(second);
        Outfile << "High card value is: " << Sec_Val << endl;
        cout << "High card value is: " << Sec_Val << endl;
		  
		Outfile << "Player 3:" << endl; // the same as player 1
		cout << "Player 3:" << endl;
		for (int i = 26; i < 39; i++)
		{
			third[i - 26] = card[i];
			Outfile << third[i - 26] << " ";
			cout << third[i - 26] << " ";
		}
		Outfile << endl;
		cout << endl;
		Thi_Val = High_Card_Value(third);
        Outfile << "High card value is: " << Thi_Val << endl;
        cout << "High card value is: " << Thi_Val << endl; 

		Outfile << "Player 4:" << endl; // the same as player 1
		cout << "Player 4:" << endl;
		for (int i = 39; i < 52; i++)
		{
			forth[i - 39] = card[i];
			Outfile << forth[i - 39] << " ";
			cout << forth[i - 39] << " ";
		}
		Outfile << endl;
		cout << endl;
		For_Val = High_Card_Value(forth);
        Outfile << "High card value is: " << For_Val << endl;
        cout << "High card value is: " << For_Val << endl;  
		Outfile.close();
	}
	answer1 = Fir_Val; // store the answer
	answer2 = Sec_Val;
	answer3 = Thi_Val;
	answer4 = For_Val;
	return 0;
}
