//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-10-09
//  FILENAME     : HW02AB07611042.CPP
//  DESCRIPTION  : COMPUTE THREE NUMBERS
//================================================================
#include <iostream>
using namespace std;

int answer1, answer2, answer3;
int main()
{
	int a, b, c; // declear three variables as integers
	cout << "Input three different integers: " << endl;
	cin >> a >> b >> c;
	answer1 = a + b + c; // calculate the sum
	answer2 = answer1 / 3; // calaulate the average
	cout << "Sum is " << answer1 << endl;
	cout << "Average is " << answer2 << endl;
	cout << "Product is " << a * b * c << endl; // calaulate the product and print the result
	
	// tell the the relation between a, b, c
	if(a >= b && a >= c) // a is the biggest
	{
		if(b > c)
		{
			answer2 = c;
			answer3 = a; 
			cout << "Smallest number is " << answer2 << endl;
			cout << "Largest number is " << answer3 << endl;
		}
		else
		{
			answer2 = b;
			answer3 = a;
			cout << "Smallest number is " << answer2 << endl;
                        cout << "Largest number is " << answer3 << endl;
		}
	}
	else if(b >= a && b >= c) // b is the biggest
	{
		if(a > c)
                {
			answer2 = c;
                        answer3 = b;
                        cout << "Smallest number is " << answer2 << endl;
                        cout << "Largest number is " << answer3 << endl;
                }
                else
                {
			answer2 = a;
                        answer3 = b;
                        cout << "Smallest number is " << answer2 << endl;
                        cout << "Largest number is " << answer3 << endl;
                }

	}
	else // c is the biggest
	{
		if(a > b)
                {
			answer2 = b;
                        answer3 = c;
                        cout << "Smallest number is " << answer2 << endl;
                        cout << "Largest number is " << answer3 << endl;
                }
                else
                {
			answer2 = a;
                        answer3 = c;
                        cout << "Smallest number is " << answer2 << endl;
                        cout << "Largest number is " << answer3 << endl;
                }

	}
	return 0;
}
