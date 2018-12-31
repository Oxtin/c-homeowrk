//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-11-01
//  FILENAME     : HW0DB07611042.CPP
//  DESCRIPTION  : Two Dice Sum
//================================================================

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

double answer1;

double answer2;

double answer3;

const int size = 11; // the size of array because there are 11 numbers(2 to 12)

int Rand(void) // generate random numbers (1 to 6)
{
	return (rand() % 6 + 1);
}

int SumRand(void) // compute the sum of two dices
{
	return (Rand() + Rand());
}

void Roll(int* v, int times) // compute how many times each number appears
{
	for (int i = 0; i < times; i++)
        {
		v[SumRand() - 2]++;
        }

}

void print(int* v) // print the result
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(6) << right << v[i]; 
	}
	cout << endl;
}

int main()
{
	int data1[size], data2[size], data3[size];

	for (int i = 0; i < 11; i++) // let each element of the arrays goes to 0
	{
		data1[i] = 0;
		data2[i] = 0;
		data3[i] = 0;
	}
	srand(int(time(0)));
	Roll(data1, 1000); // do 1000 times
	Roll(data2, 10000); // do 10000 times
	Roll(data3, 100000); // do 100000 times
	cout << "        sum";
	for (int i = 2; i <= 12; i++)
	{
		cout << setw(6) << right << i;
	}
	cout << "\n=============================================================================" << endl;
	cout << setw(11) << right << "1000times";
	print(data1);
	cout << setw(11) << right << "10000times";
	print(data2);
	cout << setw(11) << right << "100000times";
	print(data3);
	answer1 = double (data3[5]) / 100000; // store the answer1
	answer2 = double (data3[0]) / 100000;
	answer3 = double (data3[10]) / 100000;
	return 0;	
}
