#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Prototype
void read_file(string airport[], int delay[], int &count);
void avg_delay(string airport[], int delay[], int count);
void max_delay(string airport[], int delay[], int count);
void filght_count(string airport[], int delay[], int count);

//Main Function
int main()
{
	int choice;
	int count = 0;
	string airport[1000];
	int delay[1000];

	//Function 0 | check file exist or not and read from file
	read_file(airport, delay, count);

	//main menu
	do
	{
		cout << "Airport Delay Report" << endl;
		cout << "1- Average Delay" << endl;
		cout << "2- Maxium Delay" << endl;
		cout << "3- Flight Count" << endl;
		cout << "0- Exit" << endl;

		cout << "What do u want to do? ";
		cin >> choice;

		//choice 1 | Average Delay
		if (choice == 1)
		{
			avg_delay(airport, delay, count);
		}

		//choice 2 | Maxium Delay
		if (choice == 2)
		{
			max_delay(airport, delay, count);
		}

		//choice 3 | Flight Count
		if (choice == 3)
		{
			filght_count(airport, delay, count);
		}


	} while (choice != 0);

	system("pause");
	return 0;
}

//Function 0 | check file exist or not and read from file
void read_file(string airport[], int delay[], int &count)
{
	//check file exist or not
	fstream check_file;
	check_file.open("airline_delays.txt");

	if (check_file.fail())
	{
		cout << "This file doesn't exist." << endl;
	}

	else
	{
		//read from file
		ifstream file("airline_delays.txt");

		while (!file.eof())
		{
			file >> airport[count];
			file >> delay[count];
			count++;
		}

		//close the file
		check_file.close();
	}
}

//Function 1 | Average Delay
void avg_delay(string airport[], int delay[], int count)
{
	string code;
	int count1 = 0;
	double total = 0;

	cout << "Enter Airport Code: ";
	cin >> code;

	for (int i = 0; i < count; i++)
	{
		if (code == airport[i] || code == "All")
		{
			count1++;
			total += delay[i];
		}
	}

	cout << total/ count1 << endl;

}

//Function 2 | Maximum Delay
void max_delay(string airport[], int delay[], int count)
{
	int max_delay = -1;
	string max_airport;

	for (int i = 0; i < count; i++)
	{
		if (max_delay < delay[i])
		{
			max_delay = delay[i];
			max_airport = airport[i];
		}
	}

	cout << max_delay / 60.0 << endl;
	cout << max_airport << endl;

}

//Function 3 | filght count
void filght_count(string airport[], int delay[], int count)
{
	string code;
	int min_delay;
	int count2 = 0;

	cout << "Which airport: ";
	cin >> code;
	cout << "Minimum delay: ";
	cin >> min_delay;

	for (int i = 0; i < count; i++)
	{
		if (code == "All" || code == airport[i])
		{
			if (delay[i] >= min_delay)
			{
				count2++;
			}
		}
	}

	cout << count2 << endl;
}