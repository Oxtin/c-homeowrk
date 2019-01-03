//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2019-1-3
//  FILENAME     : HW0DB07611042.CPP
//  DESCRIPTION  : k-means
//================================================================
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#define k 3
using namespace std;

int answer1, answer2, answer3;

struct iris // define an iris struct
{
	float x;
	float y;
	string name;
};

float distance_two_point(iris point1, iris point2) // compute the distance of two points
{
	return sqrt(pow((point2.x - point1.x), 2) + pow(point2.y - point1.y, 2));
}

int which_group(iris* centers, iris current_iris) // determine the current point goes to which group
{
	// compare the distance of the current point and three center points
	float distance = distance_two_point(centers[0], current_iris);
	int group = 0;
	for (int i = 1; i < k; i++) // find the smallest distance and attribute the current point to the corresponding group
	{
		if (distance_two_point(centers[i], current_iris) < distance)
		{
			distance = distance_two_point(centers[i], current_iris);
			group = i;
		}
	}
	return group;
}

float compute_error(vector<iris> Grouped_iris[], iris centers[]) // compute the sum of the distance of the points and its center point
{
	float error = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < Grouped_iris[i].size(); j++)
			error += distance_two_point(Grouped_iris[i][j], centers[i]);	
	}
	return error;
}

iris get_new_center(vector<iris> grouped_Iris) // compute the new center point
{
	float X = 0, Y = 0;
	int size = grouped_Iris.size();
	iris new_center;

	for (int i = 0; i < size; i++)
	{
		X += grouped_Iris[i].x;
		Y += grouped_Iris[i].y;
	}
	new_center.x = X / size; // find the centroid point
	new_center.y = Y / size;
	return new_center;
}



void Attribute_and_Display(iris Iris_in[], int Size) 
{
	iris center[k];
	int Index = 0, Ans[3] = {0};
	vector<iris> Grouped_iris[k];
	float old_error, new_error;
	ofstream f("iris.out");

	for(int i = 0; i < k; i++) // initialize the center point. I use the 3 point in the begining
	{
		center[i].x = Iris_in[i].x;
		center[i].y = Iris_in[i].y;
	}
	
	for (int i = 1; i < Size; i++) // append the current point to its corresponding group
	{
		Index = which_group(center, Iris_in[i]);
		Grouped_iris[Index].push_back(Iris_in[i]);
	}

	//find the error value inorder to approximate the true value
	old_error = -1; 
	new_error = compute_error(Grouped_iris, center);
	
	while (abs(new_error - old_error) >= 1) // I set 1 which is the totol error value that can be accepted
	{
		for (int i = 0; i < k; i++)
			center[i] = get_new_center(Grouped_iris[i]);
		old_error = new_error;
		new_error = compute_error(Grouped_iris, center);
		for (int i = 0; i < k; i++) // clear all the point in the Grouped_iris
			Grouped_iris[i].clear();	
		for (int i = 0; i <  Size; i++) // put the points in the corresponding group according to the new center points
		{
			Index = which_group(center, Iris_in[i]);
			Grouped_iris[Index].push_back(Iris_in[i]);
		}
	}
	for (int i = 0; i < k; i++) // print the result
	{
		cout << "The " << i + 1  << " group:" << endl;
		for (int j = 0; j < Grouped_iris[i].size(); j++)
		{
			cout << Grouped_iris[i][j].name << " " << Grouped_iris[i][j].x << " " << Grouped_iris[i][j].y << endl;
			f << Grouped_iris[i][j].name << " " << Grouped_iris[i][j].x << " " << Grouped_iris[i][j].y << endl;
			Ans[i]++;
		}
	}
	answer1 = Ans[0];
	answer2 = Ans[1];
	answer3 = Ans[2];
		cout << "Group1 have " << answer1 << " points" << endl;
		cout << "Group2 have " << answer2 << " points" << endl;
		cout << "Group3 have " << answer3 << " points" << endl;
	f.close();
	return;
}


int main()
{
	iris Iris[256];
	ifstream f1("iris.data"); // open file and read it
	int index = 0;
	
	while(f1 >> Iris[index].name >> Iris[index].x >> Iris[index].y)
		index++;
	f1.close();
	Attribute_and_Display(Iris, index);
	return 0;	
}
