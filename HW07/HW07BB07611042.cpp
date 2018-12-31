//================================================================
//  PROGRAMMER   : CHEN, KE-HAN
//  DATE         : 2018-12-26
//  FILENAME     : HW07BB07611042.CPP
//  DESCRIPTION  : Use class to calculate the data
//================================================================
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class person // Define a person data type
{
	private:
		string FirstName;
		string LastName;
		int Age;
	public:
		person(string = "", string = "", int = 0);
		string getFirstName(void) {return (FirstName);}
		string getLastName() {return (LastName);}
		int getAge() {return (Age);}
		void setFirstName(string inFirst) {FirstName = inFirst;}
		void setLastName(string inLast) {LastName = inLast;}
		void setAge(int inAge) {Age = inAge;}
};
		
person :: person(string F, string L, int A) 
{
	FirstName = F; 
	LastName = L; 
	Age = A;
}

person* dataptr; // define a person pointer to point to our data

int dataLen; // the number of the people in the data

int answer1, answer2, answer3, answer4;

void MallocData(void); // use dynamic Memory allocattion

void ReadinData(void); // read the data in the file into the array pointed by dataptr

int calculateAvgAge(person*, int); // compute the average age in the array

int calculateMaxAge(person*, int); // compute the max age in the array

int calculateMinAge(person*, int); // compute the min age in the array

string Max_FirName, Max_LasName, Min_FirName, Min_LasName;

int main()
{
	MallocData();
	ReadinData();
	answer1 = dataLen;
	answer2 = calculateAvgAge(dataptr, dataLen);
	answer3 = calculateMaxAge(dataptr, dataLen);
	answer4 = calculateMinAge(dataptr, dataLen);
	cout << "There are " << answer1 << " people in the data.\n";
	cout << "The average of the age is " << answer2 << endl;
	cout << "The eldest is " << Max_FirName  << " " << Max_LasName << " who is " << answer3 << " years old.\n";
	cout << "The youngest is " << Min_FirName  << " " << Min_LasName << " who is " << answer4 << " years old.\n";
	delete [] dataptr;
	return 0;
}

void MallocData(void)
{
	string tmp;
	int lines = 0;	
	ifstream f1;
	
// every time read a line to compute how many people in the file
	f1.open("person.txt");
	while (getline(f1, tmp))
		lines++;
	f1.close();
	dataptr = new person[lines]; // dynamic memory allocation
	dataLen = lines;
}

void ReadinData(void)
{
	string FirName, LasName;
	int age, index = 0;
	ifstream f2;

	f2.open("person.txt");
	while (f2 >> FirName >> LasName >> age) // read the specific data
	{
		dataptr[index].setFirstName(FirName);
		dataptr[index].setLastName(LasName);
		dataptr[index].setAge(age);
		index++;
	}
	f2.close();
}

int calculateAvgAge(person* ptr1, int len1)
{
	int tol = 0;
	for (int i = 0 ; i < len1; i++)
		tol += ptr1[i].getAge();
	return (tol / len1);
}

int calculateMaxAge(person* ptr2, int len2)
{
	int Max = 0;
	for (int i = 0; i < len2; i++)
	{
		if (ptr2[i].getAge() > Max)
		{
			Max = ptr2[i].getAge();
			Max_FirName = ptr2[i].getFirstName();
			Max_LasName = ptr2[i].getLastName();
		}	
	}
	return (Max);
}

int calculateMinAge(person* ptr3, int len3)
{
	int Min = 100;
	for (int i = 0; i < len3; i++)
	{
		if (ptr3[i].getAge() < Min)
		{
			Min = ptr3[i].getAge();
			Min_FirName = ptr3[i].getFirstName();
			Min_LasName = ptr3[i].getLastName();
		}
	}
	return (Min);
}
