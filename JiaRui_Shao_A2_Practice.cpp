/*
You are to write a program that would help me compute average grade of a student. 
I would like to enter a set of grades into the program, 
I will let the program know that I am done entering the grades by entering -1 as the grade. 
So until I enter -1, the program should keep asking me for another grade to enter. 
Once I am done entering grades, the program should output the average grade and sum of the grades. 
Make sure that you are using for loop for this program (no while loop). 
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	//Input
	int total = 0;
	int avg;
	int j = 0;

	//Loop
	while (grade != -1)
	{
		int grade;
		cout << "Enter Grade: ";
		cin >> grade;
		total += grade; //total = total + grade
		j = j + 1;

	}

	//Output
	avg = total / j;
	cout << "Total grade: " << total << endl;
	cout << "Average grade: " << avg << endl;
	
	system("pause");
	return 0;

}