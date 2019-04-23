# include <iostream>
# include <fstream>
# include <string>

using namespace std;

int main()
{
	int choice;
	int temperature;
	int lowest_tem = 201;
	int highest_tem = -201;
	double total = 0;
	int count = 0;

	do // use while loop to repeat the main menu
	{
		cout << "Welcome to Sensor Monitor 1.5 " << endl;
		cout << "1- Submit Tempreture Reading" << endl;
		cout << "2- Tempreture Report" << endl;
		cout << "0- Exit" << endl;

		cout << "What do u ant to do? ";
		cin >> choice;

		// 1- Submit Tempreture Reading
		if (choice == 1)
		{
			cout << "What is the temperature? ";
			cin >> temperature;

			// If temperature is out of the range
			if (temperature < -200 || temperature > 200)
			{
				cout << "Temp. is out of range [-200,200]" << endl;
			}
			// If temperature is in the range
			else
			{
				if (temperature < lowest_tem)
				{
					lowest_tem = temperature;
					cout << "This is the lowest temperature recorded yet." << endl;
				}

				if (temperature > highest_tem)
				{
					highest_tem = temperature;
					cout << "This is the highest temperature recorded yet." << endl;
				}

				// total temperature
				total += temperature;
				count++;
			}
		}

		// 2- Tempreture Report
		else if (choice == 2)
		{
			cout << "The lowest temperature is " << lowest_tem << endl;
			cout << "The highest temperature is " << highest_tem << endl;
			cout << "The average temperature is " << total / count << endl;
		}

	} while (choice != 0);

	system("pause");
	return 0;
}