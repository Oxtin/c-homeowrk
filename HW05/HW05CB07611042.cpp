//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-11-22
//  FILENAME     : HW0CB07611042.CPP
//  DESCRIPTION  : Magic square
//================================================================
#include <iostream>
#include <iomanip>
using namespace std;

int answer1;
int answer2;

int main()
{
	int n, row = 0, col;
	cout << "Enter an odd number" << endl;
	cin >> n;
	col = n / 2; // initialize the order of the col
	int data[1000][1000] = {0}; // open a big array and initializ it with 0
	data[row][col] = 1; // fill 1 in the array
	for (int i = 2; i <= n * n; i++)
	{
		if (row == 0 && col == n - 1) // the top-right corner
			data[++row][col] = i; // fill below it
		else
		{
			if (row == 0) // in the first row
			{
					row = n - 1; // go to the lowest low
					data[row][++col] = i;
			}
			else
			{
				if (col == n - 1) // the rightest col
				{
						col = 0; // go to first col
						data[--row][col] = i;
				}
				else
				{
					if (data[row - 1][col + 1] != 0) // when there are number which is already filled in 
						data[++row][col] = i; // fill it below it
					else
						data[--row][++col] = i; // the general case
				}
			}
		}
	}
	for (int i = 0; i < n; i++) // print the result
	{	
		for (int j = 0; j < n; j++)
			cout << setw(4) << data[i][j];
		cout << endl;
	}
	answer1 = data[0][0];
	answer2 = data[n - 1][n - 1];
	return 0;
}
