//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-11-01
//  FILENAME     : HW04CB07611042.CPP
//  DESCRIPTION  : greatest common divisor
//================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int answer1;

int answer2;

int answer3;

int gcd(int, int);

int main()
{
	cout << "    ";
	for (int i = 1; i <= 20; i++)
	{
		cout << setw(2) << right << i << "  ";
	}
	cout << "\n==================================================================================" << endl;
	for (int i = 1; i <= 20; i++) // print the result and arrange them
	{
		cout << setw(2) << right << i << "| ";
		for (int j = 1; j <= 20; j++)
		{
			cout << setw(2) << right << gcd(i,j) << "  "; 
		}
		cout << endl;
	}
	answer1 = gcd(10,15); // store the answer that the question ask
	answer2 = gcd(2, 17);
	answer3 = gcd(20, 20);
	return 0;
}

int gcd(int a, int b) // use recusive function to write gcd
{
	if (a % b == 0)
	{
		return (b);
	}
	else
	{
		return (gcd(b, a % b)); // if a is not divisible with b, then redo the function of (b, a & b)
	}
}
