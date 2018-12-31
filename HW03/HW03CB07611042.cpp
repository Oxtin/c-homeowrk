//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-10-18
//  FILENAME     : HW03CB07611042.CPP
//  DESCRIPTION  : HAPPY NUMBER
//================================================================

#include <iostream>
#include <cmath>
using namespace std;

int answer1 = 0;
int num, i, n = 1;
int* ptr; // declare a pointer which is used to produce a Dynamic memory allocation

int check(int, int, int*); // Check if the recent number is repeat. To end the infinite loop.

int main()
{
	while (n < 1000)
	{
		num = n;
		i = 0;
		ptr = new int [1000];
		while (num != 1)
		{
			if(num < 10) // compute the value which the question asks
			{	
				num = pow(num, 2);
			}
			else if (num >= 10 && num < 100)
			{
				num = pow(num / 10, 2) + pow(num % 10, 2);
			}
			else
			{
				num = pow(num / 100, 2) + pow((num % 100) / 10, 2) + pow(num % 10, 2);
			}
			if (check(num, i, ptr) > 0) // if check(num, i, ptr) > 0 , implies the loop won't stop
			{
				break;
			}
			ptr[i] = num; 
			i++;
		}
		if (num == 1) // if the moment num = 1, implies n is a happy number
		{
			if (n > answer1) // to store the biggest happy number
                        {
                                answer1 = n;
                        }
			cout << n << " ";
		}		
		delete [] ptr; // clear the dynamic memory  
		n++;
	}
	cout << endl;
	return 0;
	
}

int check(int a, int index, int* v)
{
	for (int i = 0; i < index; i++)
	{	
		if (v[i] == a)
		{
			return (1); // the loop won't stop
		}
	}
	return (-1); // there is no element in the array equals to a
}

