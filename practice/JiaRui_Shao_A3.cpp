/*Your task is to write a little utility program to assist a local insurance agency 
on calculating monthly cost of car insurance based on personal information and driving history of the individual requesting it.

These are the requirements for the program:
Req 1: The base monthly cost of insuring a car is $50.00 -- this is the starting cost, we will add to this cost as we collect more information (see the rest of the requirements)
Req 2: Your program should get the age of the driver from the user. 
If the driver is under the age of 25, the monthly premium goes up $100; 
otherwise, If the driver is under the age of 35, the monthly premium goes up $20.
For example, for a 23 year old driver, you should add $100 to the base premium. For a 28 year old driver, you should add only $20 to the base premium. 
Any driver over the age of 35, does not get any additional premium due to age.
Req 3: Program should get the number of accidents in the last 5 years from the user. 
Up to one accident is forgiven under accident forgiveness policy. 
If the number of accidents is less than 3, then you add $40 per accident. 
If the number of accidents is more than or equal to 3, you add $60 per accident to the monthly premium. 
If driver had more than 4 accidents in the past 5 years, we cannot provide insurance (let the user know with a message).
Number of Accidents: Accident Surcharge

1 Accident None = Accident Forgiveness, no additional charge
2 Accidents $40 per accident = $80 additional charge
3 Accidents $60 per accident = $180 additional charge
4 Accidents $60 per accident = $240 additional charge
5 Accidents Can not insure
Use the following test cases to make sure that your program is functioning properly. 

Based on the above 3 requirements, compute and output the monthly premium for the driver. 

Test Case 1: 24 years old driver with no accident should output $150.00.
Test Case 2: 24 years old driver with 3 accidents should output $330.00.
Test Case 3: 26 years old driver with no accidents should output $70.00.
Test Case 4: 50 years old driver with 2 accidents should output $130.00.
Submit the cpp file for grading. 

*/

#include <iostream> // read things from the screen and print on screen. 
#include <fstream>  // read/write things from and to a file 
#include <string>	// if your program deals with string data

using namespace std;

int main()
{
	//INPUT
	int age;
	int accident_num;
	int primium = 50;

	cout << "What is your age: ";
	cin >> age;

	cout << "What is the number of car accidents in the last 5 years: ";
	cin >> accident_num;

	//CALCULATION

	   //age
	if (age >= 25) 
	{
		if (age >= 35)
			primium += 0;
		else
			primium += 20;
	}
	else
	{
		primium += 100;
	}

	   //accident number
	{
		if (accident_num < 2)
			primium += 0;
		else if (accident_num < 3)
			primium += 80;
		else if (accident_num < 4)
			primium += 180;
		else if (accident_num < 5)
			primium += 240;
		else
			cout << "Sorry, we cannot provide you with insurance." << endl;
	}

	//OUTPUT
	cout << "The monthly premium is: " << primium << endl;

	system("PAUSE");
	return 0;
}