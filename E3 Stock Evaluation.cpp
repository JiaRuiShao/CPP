#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int choice;
	char choice_2 = 'y';
	int yr_num;
	double market_value;
	double earnings_per_share;
	double desired_return;
	double rate_earning;
	double total = 0;

	do // while loop
	{
		//main menu
		cout << "Welcome to STOCK Valuation v1.1" << endl;
		cout << "===============================" << endl;
		cout << "Method 1: Zero Growth" << endl;
		cout << "Method 2: Constant Growth" << endl;
		cout << "Method 2: Limited Growth" << endl;

		//ask the user to choose a method
		cout << "Which method do you want to use? ";
		cin >> choice;

		// Method 1 Zero Growth
		if (choice == 1)
		{
			//INPUT
			cout << "This year's earning's per share? ";
			cin >> earnings_per_share;
			cout << "Desired rate of return? ";
			cin >> desired_return;

			//CALCULATION
			market_value = earnings_per_share / desired_return;

			//OUTPUT
			cout << "The present fair market value of the stock is " << market_value << endl;
			cout << "Do you want to compute another one? (y/n) ";
			cin >> choice_2;
		}


		// Method 2 Constant Growth
		if (choice == 2)
		{
			//INPUT
			cout << "This year's earning's per share? ";
			cin >> earnings_per_share;
			cout << "Desired rate of return? ";
			cin >> desired_return;
			cout << "Growth rate of earning? ";
			cin >> rate_earning;

			//CALCULATION
			market_value = earnings_per_share / (desired_return - rate_earning);

			//OUTPUT
			cout << "The present fair market value of the stock is " << market_value << endl;
			cout << "Do you want to compute another one? (y/n) ";
			cin >> choice_2;
		}


		// Method 3 Limited Growth
		if (choice == 3)
		{
			//INPUT
			cout << "This year's earning's per share? ";
			cin >> earnings_per_share;
			cout << "Desired rate of return? ";
			cin >> desired_return;
			cout << "Growth rate of earning? ";
			cin >> rate_earning;
			cout << "Number of years earnings will grow? (less than 50)";
			cin >> yr_num;

			//CALCULATION
			if (yr_num >= 50)
			{
				cout << "Error. The year must be less than 50." << endl;
			}
			else //yr_num < 50
			{
				//Calculate the future earning up to yr_num year
				for (int i = 1; i <= yr_num; i++)
				{
					market_value = earnings_per_share * pow ((1 + rate_earning) , i) / pow ((1 + desired_return) , i);
					total += market_value;
				}
				
				//Calculate the future earning after year yr_num
				for (int j = yr_num + 1; j <= 50; j++)
				{
					market_value = earnings_per_share * pow((1 + rate_earning), yr_num) / pow((1 + desired_return), j);
					total += market_value;
				}
			}

			//OUTPUT
			cout << "The present fair market value of the stock is " << total << endl;
			cout << "Do you want to compute another one? (y/n) ";
			cin >> choice_2;
		}

	} while (choice_2 == 'y');

	system("pause");
	return 0;
}