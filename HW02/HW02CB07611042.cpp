//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-10-09
//  FILENAME     : HW02CB07611042.CPP
//  DESCRIPTION  : SOLVE QUADRATIC PROBLEM
//================================================================
#include <cmath>
#include <iostream>
using namespace std;

double answer1;
int main()
{
	double a, b, c;
	cout << "Quadratic equation is: ax^2 + bx + c = 0" << endl;
	cout << "ENTER a, b, c: " << endl;
	cin >> a >> b >> c;
	answer1 = b * b - 4 * a * c; // calculate (b^2 - 4ac) and put the result into answer1
	if (a == 0) // The coefficient a = 0
	{
		if (b == 0) // if a = 0 and b = 0 , there is no solution
		{
			cout << "No solution" << endl;
		}
		else
		{
			cout << "Only one solutino: " << -c / b << endl;
		}
	}
	else // The coefficient a is not equal to 0
	{
		if (answer1 >= 0) // When the discriminant is positive or equal to 0
		{
			cout << "Two real solution: " << endl; 
			cout << "First solution: " << (-b + sqrt(answer1)) / (2 * a) << endl;
			cout << "Second solution: " << (-b - sqrt(answer1)) / (2 * a) << endl;
		}
		else // When the discriminant is negative
		{
			cout << "Two complex solution: " << endl;
			cout << "First solution: " << -b / (2 * a) << " + i" << sqrt(-answer1) / (2 * a) << endl;
			cout << "Second solution: " << -b / (2 * a) << " - i" << sqrt(-answer1) / (2 * a) << endl;
		}
	}
	return 0;
}
