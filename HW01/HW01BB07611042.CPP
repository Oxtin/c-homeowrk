//================================================================
//  PROGRAMMER : CHEN, KE-HAN
//  DATE       : 2018-09-25
//  FILENAME   : HW01BB07611042.CPP 
//  DESCRIPTION: This is a program to compute the average of three numbers
//================================================================
#include <iostream>
using namespace std;

double answer1; // declare a double variable in global

int main( )
{
	double a, b, c; // declare three double variables
	cout << "Enter three numbers" << endl;
	cin >> a >> b >> c;
	answer1 = (a + b + c) / 3.0; // calculate the average of three numbers
	cout  << "The average grade is "<< answer1 << endl; // print the answer1
	return 0;
}
