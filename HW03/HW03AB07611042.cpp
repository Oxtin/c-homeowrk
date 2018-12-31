//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-10-18
//  FILENAME     : HW03AB07611042.CPP
//  DESCRIPTION  : Calculation of pi
//================================================================
#include <iostream>
#include <cmath>
using namespace std;

double answer1;

int main()
{
	double  index = 0; 
	double 	errors = 0;
	answer1 = 0;

	while (index <= 1000) // when k = 1000 calculate the answer
	{
		answer1 = answer1 + (pow(-1, index) / (2 * index + 1));
		index++;
	}
	answer1 = answer1 * 4;
        errors = answer1 - 3.141592653589793238463; // compute the errors
        cout << "when k = 1000: " << answer1 << endl;
        cout << "errors: " << errors << endl;
	
	answer1 = 0; // reset the value of answer1 and index
	index = 0;
	while (index <= 10000) // when k = 10000, calculate the answer
        {
                answer1 = answer1 + (pow(-1, index) / (2 * index + 1));
                index++;
        }
	answer1 = answer1 * 4;
        errors = answer1 - 3.141592653589793238463; // compute the errors
        cout << "when k = 10000: " << answer1 << endl;
        cout << "errors: " << errors << endl;
	
	index = 0; // reset the value of answer1 and index
	answer1 = 0;
	while (index <= 100000) // when k = 100000, calculate the answer1
        {
                answer1 = answer1 + (pow(-1, index) / (2 * index + 1));
                index++;
        }
	
	answer1 = answer1 * 4;
	errors = answer1 - 3.141592653589793238463; // compute the errors
	cout << "when k = 100000: " << answer1 << endl;
	cout << "errors: " << errors << endl;
	return 0;
}
