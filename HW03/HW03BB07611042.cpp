//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-10-18
//  FILENAME     : HW03BB07611042.CPP
//  DESCRIPTION  : Calculation of prime numbers
//================================================================
#include <iostream>
#include <cmath>
using namespace std;

int answer1;

int main()
{
	int i = 2; // initialize the number which is 2
	int n = 2; // initialize the divisor which is 2
	
	while (i < 1000)
	{
		while (i % n != 0) // tell if the number is divisible by any number from 2 to itself
		{
			n++;
		}
		if (i / n ==1) // if n is equal to i, i is a prime number
		{
			if (i > answer1) // store the largest prime number to answer1
			{
				answer1 = i;
			}
		}
		n = 2;
		i++;
	}
	cout << "the biggest prime number less than 1000 is: " << answer1 << endl; // print the result
	return 0;
}
