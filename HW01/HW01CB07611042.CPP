//================================================================
//  PROGRAMMER  : CHEN, KE-HAN
//  DATE        : 2018-09-25
//  FILENAME    : HW01CB07611042.CPP 
//  DESCRIPTION : This is a program to calculate the speed of car 
//================================================================
#include <iostream>
using namespace std;

double answer1; // declare the answer1 as a double variable

int main()
{
	double fe, fr; // declare the fe,fr as double variables
	fe = 2e10;
	fr = 2.00000035e10;
	answer1 = 6.685e8 * (fr - fe) / (fr + fe); // calculate the speed of the car
	cout << "The speed is " << answer1  << "miles/hour" << endl; // print the answer

	return 0;
}
