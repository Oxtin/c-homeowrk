//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-10-19
//  FILENAME     : HW03DB07611042.CPP
//  DESCRIPTION  : Paper, Scissors, Stone game
//================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int change_input(char); // A function that changes R, S, P into numbers(1 to 3) 

int answer1;

int main()
{
	srand(time(NULL));

        int min = 1; // the lower limit of the random numbers
        int max = 3; // the upper limit of the random numbers
        int x;       // x is for random numbers
	char input;
	int round = 0;
	int cwin = 0; // How many times does computer win
	int pwin = 0; // How many times does player win
	
	cout << "enter R,S,P for Rock, Scissors, and Paper" << endl;
	while (cin >> input)
	{
		if (input != 'R' && input != 'S' && input != 'P') // check the error input
		{
			cerr << "Error input !" << endl; 
		}
		else
		{
			x = rand() % (max - min + 1) + min; // generate a random number
			round++; // sum the round
			if (x == change_input(input)) // the situation of draw
			{
				cout << "draw" << endl;
			}
			else if ((x == 1 && change_input(input) == 3) || // when player wins
					(x == 2 && change_input(input) == 1) || 
						(x == 3 && change_input(input) == 2))
			{
				cout << "You Win this round" << endl;
				pwin++;
			}
			else // when computer wins
			{
				cout << "Computer wins this round" << endl;
				cwin++;
			}
			
			if (pwin == 3) // player wins 3 rounds and is faster than the computer does
			{
				cout << endl;
				cout << "You win the game" << endl;
				break;
			}
			if (cwin == 3) // computer wins 3 rounds and is faster than the player does
			{
				cout << endl;
				cout << "Computer wins the game" << endl;
				break;
			}
		}
		
	}
	answer1 = round;
	cout << "Total round is: " << round << endl;
	return 0;
}

int change_input(char a)
{
	if (a == 'R') 		// 1 represents R
		return (1);
	else if (a == 'S') 	// 2 represents S
		return (2);
	else         		// 3 represents P
		return (3);
}
