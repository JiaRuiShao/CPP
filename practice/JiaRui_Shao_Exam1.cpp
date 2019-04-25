#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int choice;
	int min;
	int count = 0;
	int day;
	double charge;
	double total = 0;
	char quote = 'y';
	char ph_service;

	do // main loop to repeat the main menu when quote == 'y'
	{
		cout << "Need Office Space?" << endl;
		cout << "==================" << endl;
		cout << "1- Private Office" << endl;
		cout << "2- Colocation" << endl;
		cout << "3- Temporary Workspace" << endl;

		cout << "What type of space?";
		cin >> choice;

		//Choose 1- Private Office
		if (choice == 1)
		{
			count++;
			
			cout << "Phone service? (y/n) ";
			cin >> ph_service;

			//If need phone service
			if (ph_service == 'y')
			{
				//INPUT
				cout << "How many minutes do you need? ";
				cin >> min;

				//CALCULATION
				charge = 1000 + min / 2;
				total += charge;

				//OUTPUT
				cout << "Your monthly charge is $" << charge << endl;
			}

			//If don't need phone service
			if (ph_service == 'n')
			{
				cout << "Your monthly charge is $1000" << endl;
				total += 1000;
			}
		}

		//Choose 2- Colocation
		if (choice == 2)
		{
			count++;

			cout << "Phone service? (y/n) ";
			cin >> ph_service;

			//If need phone service
			if (ph_service == 'y')
			{
				//INPUT
				cout << "How many minutes do you need? ";
				cin >> min;

				//CALCULATION
				charge = 500 + min / 2;
				total += charge;

				//OUTPUT
				cout << "Your monthly charge is $" << charge << endl;
			}

			//If don't need phone service
			if (ph_service == 'n')
			{
				cout << "Your monthly charge is $500" << endl;
				total += 500;
			}

		}

		//Choose 3- Temporary Workspace
		if (choice == 3)
		{
			count++;

			cout << "How many days do you need? ";
			cin >> day;
			cout << "Phone service? (y/n) ";
			cin >> ph_service;

			//If need phone service
			if (ph_service == 'y')
			{
				//INPUT
				cout << "How many minutes do you need? ";
				cin >> min;

				//CALCULATION
				charge = day * 60 + min / 2;
				total += charge;

				//OUTPUT
				cout << "Your monthly charge is $" << charge << endl;
			}

			//If don't need phone service
			if (ph_service == 'n')
			{
				charge = day * 60;
				total += charge;

				cout << "Your monthly charge is " << charge << endl;
			}

		}

		cout << "Another quote? (y/n)";
		cin >> quote;

	} while (quote == 'y');

	cout << "Average quotation provided was $" << total / count << endl;

	system("pause");
	return 0;
}