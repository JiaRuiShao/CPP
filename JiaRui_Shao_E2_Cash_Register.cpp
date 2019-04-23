#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//INPUT
	int choice;
	int item;
	int code;
	int count = 0;
	double unit_price;
	double weight;
	double price;
	double total = 0;
	double cash_in;
	double cash_out;

	//WHILE LOOP
	do
	{
		cout << "1- New Sale" << endl;
		cout << "2- Cash Out" << endl;
		cout << "3- Cash In" << endl;
		cout << "4- Report" << endl;
		cout << "0- Exit" << endl;

		cout << "What do you want to do?";
		cin >> choice;

		// choice 1
		if (choice == 1)
		{
			cout << "How many items in this sale?";
			cin >> item;

			//for loop to input the items
			for (int i = 1; i <= item; i++)
			{
				cout << "Item Code: ";
				cin >> code;
				count++;

				if (code < 100)
				{
					//INPUT
					cout << "Price Per Pound: ";
					cin >> unit_price;

					cout << "Item Weight: ";
					cin >> weight;

					//CALCULATION
					price = unit_price * weight;
					total += price;

					//OUTPUT
					cout << "You successfully make a sale!" << endl;
				}

				else
				{
					//INPUT
					cout << "Item Price: ";
					cin >> unit_price;

					//CALCULATION
					price = unit_price * (1 + 0.1); //apply tax to the item
					total += price;

					//OUTPUT
					cout << "You successfully make a sale!" << endl;
				}
			}
		}

		// choice 2
		if (choice == 2)
		{
			cout << "Cash-out amount? ";
			cin >> cash_out;

			if (cash_out <= total)
			{
				total -= cash_out;
				cout << "You successfully cash out $" << cash_out << endl;
			}

			else
				cout << "The cash is not enough." << endl;
		}

		// choice 3
		if (choice == 3)
		{
			//INPUT
			cout << "Cash-in amount? ";
			cin >> cash_in;

			//CALCULATION
			total += cash_in;

			//OUTPUT
			cout << "You successfully cash in $" << cash_in << endl;
		}

		// choice 4
		if (choice == 4)
		{
			cout << "# of sales:" << count << endl;
			cout << "Total: $" << total << endl;
		}

	} while (choice != 0);

	system("pause");
	return 0;
}