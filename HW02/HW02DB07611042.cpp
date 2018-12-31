//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-10-09
//  FILENAME     : HW02DB07611042.CPP
//  DESCRIPTION  : BLACKJACK GAME
//================================================================
#include <iostream>
using namespace std;

int answer1, answer2;
int main()
{
	int a, b, c;
	
	cout << "Enter three numbers of your cards" << endl;
	cin >> a >> b >> c;
	if ((a > 13) || (b > 13) || (c > 13)) // Check if a, b, c are out of range
	{
		cout << "You input wrong numbers" << endl;
	}
	else
	{
		int tmp;

		answer2 = a + b + c; // compute the sum of three numbers
		if (a > 10) // change 11, 12, 13 into 10
		{
			a = 10;
		}
		if (b > 10)
		{
			b = 10;
		}
		if (c > 10)
		{
			c = 10;
		}
		if (a > b) // change the position that a, b, c are from the smallest to the largest
		{
			tmp = a;
			a = b;
			b = tmp;
		}
		if (b > c)
		{
			tmp = b;
                	b = c;
                	c = tmp;
		}
		if (a > b)
		{
			tmp = a;
                	a = b;
                	b = tmp;
		}
		if ((a == 1) && (b == 1) && (c == 1)) // When the three cards are all 1
		{
			answer1 = 13;
		}
		else if ((a == 1) && (b == 1) && (c != 1)) // When there are two number 1
		{
			if ((12 + c) > 21)
			{
				answer1 = 2 + c;
			}
			else
			{
				answer1 = 12 + c;
			}
		}	
		else // When there is only one number 1 or none of the three cards are number 1
		{
			answer1 = a + b + c;
		}
		cout << "the total value is " << answer1 << endl; // print the result
		cout << "the total sum is " << answer2 << endl;
	}
	return 0;
}
