#include <iostream> // read things from the screen and print on screen (keyboard)
#include <fstream> // read/write things from and to a file
#include <string> // if your program deals with string data

using namespace std;

int main() //only one main function in a project
{
	// INPUT
	double grade1;
	cout << "Enter Grage 1: ";
		cin >> grade1;

	double grade2;
	cout << "Enter Grage 2: ";
		cin >> grade2;

	double grade3;
	cout << "Enter Grage 3: ";
		cin >> grade3;

	// PROCESSONG
	double avg;
	avg = (grade1 + grade2 + grade3) / 3;


	// OUTPUT
	if (avg  >= 93) 
	{
		cout << "The average is A " << endl;
	}
	
	if (90 <= avg && avg < 93) // (avg >= 90 && avg < 93)
	{
		cout << "The average is A- " << endl;
	}

	if (80 <= avg && avg < 90)
	{
		cout << "The average is B " << endl;
	}
	
	if (70 <= avg && avg < 80)
	{
		cout << "The average is C " << endl;
	}


	if (avg < 70)
	{
		cout << "The average is F " << endl;
	}

	system("pause");
	return 0;
}

