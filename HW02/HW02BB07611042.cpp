//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-10-09
//  FILENAME     : HW02BB07611042.CPP
//  DESCRIPTION  : COMPUTE BOWLING SCORE
//================================================================
#include <iostream>
using namespace std;

int answer1;
int main()
{
	int a, b, c; // declare three integers as three numbers of three throws
	cout << "How many pins knocked down in three throws" << endl;
	cin >> a >> b >> c;
	if ((a >= 0 && a <= 10) && (b >= 0 && b <= 10) && (c >= 0 && c <= 10)) // Tell if a, b, c are in the range of 0-10
		if((a < 10) && ((a + b) > 10)) // A error case that the first two trows over 10 pins when the first throw is not strike
		{
			cout << "error input" << endl;
		}
		else if(a == 10) // The first throw is strike
		{
			answer1 = 10 + b + c;
			cout << "Your score is " << answer1 << endl;
		}
		else if ((a + b) == 10) // The first throw is not strike but the second throw clear the remainded
		{
			answer1 = 10 + c;
			cout << "Your score is " << answer1 << endl;
		}
		else // the first two throw fail to clear 10 pins
		{
			answer1 = a + b;
			cout << "Your score is " << answer1 << endl;
		}
	else // Tell if the user intput invalid numbers
	{
		cout << "error input" << endl;
	}
	return 0;
}
