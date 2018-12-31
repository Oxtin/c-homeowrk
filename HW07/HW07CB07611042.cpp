//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-12-26
//  FILENAME     : HW07CB07611042.CPP
//  DESCRIPTION  : eight queen
//================================================================
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int* ptr;

int answer1 = 0;

void Initial_Array(int); // dynamic allocation a array

bool Check(int); // to check if the current queen will be attacked

void N_Queen(int, int);

ofstream f ("eight_queen.txt"); // open a file to write it

int main()
{
	int num;

	cout << "Enter a number for n_queen" << endl;
	cin >> num;
	Initial_Array(num);
	N_Queen(0, num);
	f.close();
	delete [] ptr;
	return 0;
}

void Initial_Array(int n)
{
	ptr = new int[n];
	for (int i = 0; i < n; i++)
		ptr[i] = 0;
}

bool Check(int N)
{
	for (int i = 0; i < N; i++)
	{
		if (ptr[i] == ptr[N] || (N - i) == abs(ptr[N] - ptr[i])) // int the same row or in the same slash will be attqcked
			return (false);
	}
	return (true); // safe
}

void N_Queen(int col, int n) // col from 0 to n - 1
{
	for (int i = 1; i <= n; i++)
	{
		ptr[col] = i;
		if (col == (n - 1) && Check(col)) // if we correctly place the last queen, we will get one solution
		{
			for (int j = 0; j < n; j++) // print and write the result
			{	
				cout << ptr[j] << " ";
				f << ptr[j] << " ";
			}
			cout << endl;
			f << endl;
			answer1 = ptr[n - 1];
			return;
		}
		else if (Check(col)) // Chech the next column
			N_Queen(col + 1, n);
	} // if run over this loop but don't have a solution, it will run to the previous N_Queen funcion
}
