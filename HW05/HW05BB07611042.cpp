//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-11-29
//  FILENAME     : HW05BB07611042.CPP
//  DESCRIPTION  : Game of Life
//================================================================
#include <iostream>
#include <iomanip>
using namespace std;

int answer1, answer2, answer3, tol;

int main()
{
	int board[22][22] = {0};
	int ref[22][22] = {0}; // This is for rewriting the board
	int n, sum;
	
	cout << "Enter a number for generation:" << endl;
	cin >> n;
	// Initialize the board
	board[9][9] = 1; board[9][11] = 1; board[10][10] = 1; board[11][10] = 1; board[12][9] = 1; board[12][11] = 1;
	// Print the generation 1
	cout << "Generation 1:" << endl; 
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
			cout << setw(2) << board[i][j];
		cout << '\n';
	}
	cout << "There are 6 cells.\n";
	answer1 = 6;
	// After gneration 1
	for (int k = 1; k < n; k++)
	{
		tol = 0;
		for (int i = 1; i < 21; i++) // Rewrite board in ref
		{		
			for (int j = 1; j < 21; j++)
				ref[i][j] = board[i][j];
		}
		for (int i = 1; i < 21; i++)
		{
			sum = 0;
			for (int j = 1; j < 21; j++)
			{ // Use sum to compute the number surround with the current cell
				sum = ref[i-1][j-1] + ref[i-1][j] + ref[i-1][j+1] + ref[i][j-1] + 
					ref[i][j+1] + ref[i+1][j-1] + ref[i+1][j] + ref[i+1][j+1];
				if (ref[i][j] == 0) // If the current cell is dead
				{
					if (sum == 3) // It would revive if sum = 3
						board[i][j] = 1;
				}
				else // If the current cell is live
				{
					if (sum < 2 || sum > 3) // It would die when sum < 2 or > 3
						board[i][j] = 0;
				}
			}
		}
		for (int i = 1; i < 21; i++) // Compute how many cells remain.
		{
			for (int j = 1; j < 21; j++)
				tol = tol + board[i][j];
		}
		cout << "Generation " << k + 1 << ":\n"; // Print the result
		for (int i = 1; i < 21; i++)
    	{
        	for (int j = 1; j < 21; j++)
            	cout << setw(2) << board[i][j];
        	cout << '\n';
    	}
		cout << "There are " << tol << " cells.\n";
		if (k == 1)
			answer2 = tol;
		if (k == 2)
			answer3 = tol;
	}
	return 0;
}
