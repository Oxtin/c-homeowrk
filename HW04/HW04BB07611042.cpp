//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-11-06
//  FILENAME     : HW0BB07611042.CPP
//  DESCRIPTION  : Data processing and sorting
//================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int answer1;

int answer2;

void BubbleSort(int v[][2], int n) // Use bubble sort to arrange the order of data
{
	int tmp1, tmp2;
		
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (v[j][1] > v[j - 1][1])
			{	
				tmp1 = v[j][0]; // change part number
				v[j][0] = v[j - 1][0];
				v[j - 1][0] = tmp1;
				tmp2 = v[j][1]; // change quantity
				v[j][1] = v[j - 1][1];
				v[j - 1][1] = tmp2;
				
			}
}

int main()
{
	const int rol = 7; // size of the data
	const int col = 2;
	int data[rol][col] = {1001, 62, 949, 85 ,1050, 33, 1200, 23, 867, 125, 346, 59, 1025, 105};
	
	BubbleSort(data, rol);
	cout << "  Part No." << "     Quantity" << endl; // print the result
	cout << "==========================" << endl;
	for (int i = 0; i < rol; i++)
	{	
		for (int j = 0; j < col; j++)
		{	
			cout << setw(7) << right << data[i][j] << "     ";
		}
		cout << endl;
	}
	answer1 = data[0][0];
	answer2 = data[rol - 1][0];
	return 0;
}
