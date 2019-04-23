#include <iostream>

using namespace std;

int main()
{
	double total = 0;
	int numSales = 0;

	int choice;
	do // the main program loop, displays the menu every time it runs
	{
		cout << "EZ Cash Register Pro XL v3.62" << endl;
		cout << "1- New Sale" << endl;
		cout << "2- Cash Out" << endl;
		cout << "3- Cash In" << endl;
		cout << "4- Report" << endl;
		cout << "0- Exit" << endl;
	
		cout << "What do you want to do? ";
		cin >> choice;

		if (choice == 1)
		{
			int itemCount;
			cout << "# of items: ";
			cin >> itemCount;

			double subTotal = 0;
			for (int i = 0; i < itemCount; i++)
			{
				int productCode;
				cout << "Product Code: ";
				cin >> productCode;

				double unitPrice;
				cout << "Unit Price: ";
				cin >> unitPrice;

				if (productCode < 100)
				{
					double weight;
					cout << "Weight: ";
					cin >> weight;

					subTotal += unitPrice * weight;
				}
				else
				{
					subTotal += unitPrice * 1.1;
				}
			}

			total += subTotal;

		}
		else if (choice == 2)
		{
			double amount;
			cout << "How much: ";
			cin >> amount;
			total -= amount;
		}
		else if (choice == 3)
		{
			double amount;
			cout << "How much: ";
			cin >> amount;
			total += amount;
		}
		else if (choice == 4)
		{
			
			cout << "# of Sales: " << numSales << endl;
			cout << "Total     : " << total << endl;
		}
		else if (choice != 0)
		{
			cout << "Invalid choice!" << endl;
		}

	} while (choice != 0);
	
	cout << "Thank you for using EZ Cash -- hope to see you soon!" << endl;

	system("PAUSE");
	return 0;
}