//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-10-19
//  FILENAME     : HW03EB07611042.CPP
//  DESCRIPTION  : find twin prime numbers
//================================================================
#include <iostream>
using namespace std;

int answer1;

int answer2;

int rem;

int find_pairs(int*, int); // To find the prime number whose next one prime number is itself +2

int main()
{
	int num = 0;
	int i = 2, index = 0;
        int n = 2;
        int array[1000]; // An array which stores prime number under 1000

        while(i < 1000) // find the prime number and stores it into an array
        {
                rem = i;
                while(rem % n != 0)
                {
                        n++;
                }
                if (rem / n == 1)
                {
                        array[index] = i;
                        index++;
                }
		n = 2;
                i++;
        }
	
	while (num < index)
	{
		if(find_pairs(array, num) > 0) // if we find an one of the twin prime number
		{
			cout << "(" << find_pairs(array, num) << "," << find_pairs(array, num) + 2 << ") ";
			if(find_pairs(array, num) > answer1) // store the biggest twin prime numbers
			{
				answer1 = find_pairs(array, num);
				answer2 = find_pairs(array, num) + 2;
			}
		}
		num++;
	}
	cout << endl;
	cout <<"The biggest twin prime numbers are: (" << answer1 << "," << answer2 << ")" << endl;
	
	return 0;
}

int find_pairs(int* v, int i)
{
	if(v[i] + 2 == v[i + 1])
	{
		return (v[i]);
	}
	else // if v[i] is not one of the twin prime number, then return -1
	{
		return (-1);
	}
}
