//================================================================
//  PROGRAMMER    : CHEN, KE=HAN
//  DATE          : 2018-09-25
//  FILENAME      : HW01DB07611042.CPP 
//  DESCRIPTION   : This is a program to compute the increase in length of two items 
//================================================================
#include <iostream>
using namespace std;

double answer1; // declare answer1 as the increase length for the aluminum slab
double answer2; // declare the increase length for the copper slab

int main()
{
	double F, k, L, w, d, E1, E2;
	L = 3;
	w = 4;
	d = 2;
	F = 4;
	E1 = 68950;
	E2 = 110000;
	k = 1000;
	answer1 = F * k * L * 1000 / (w * 10 * d * E1); // calculate the answer1
	answer2 = F * k * L * 1000/ (w * 10 * d * E2); // calculate the answer2
	cout << "The increase length for the aluminum slab is " << answer1 << endl; // print the result of answer1
	cout << "The increase length for the copper slab is " << answer2 << endl; // print the result of answer2
	
	return 0;
}

