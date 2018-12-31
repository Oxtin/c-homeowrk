//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-11-01
//  FILENAME     : HW04AB07611042.CPP
//  DESCRIPTION  : find perfect number
//================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int answer1;

int PerfectNumber(long int);

int main()
{
	for (int i = 1; i < 10000; i++)
	{
		if (PerfectNumber(i) > 0)
		{
			if (PerfectNumber(i) > answer1) // find the biggest perfect number under 10000
			{
				answer1 = PerfectNumber(i);
			}
			cout << setw(5) << PerfectNumber(i); // print the result
		
		}
	}
	cout << endl;
	cout << setw(5) << answer1 << endl;
	return 0;
}

int PerfectNumber(long int n) // if n is a perfect number it return positive number
{
	long int sum = 0;
	for (int i = 1; i < n; i++) // find n's factors but exclude itself
	{
		if (n % i == 0)
		{
			sum = sum + i; // sum n's all factors
		}
	}
	if (sum == n)
	{
		return (n);
	}
	else // n is not perfect number
	{
		return (-1);
	}
}
