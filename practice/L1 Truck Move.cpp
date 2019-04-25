
#include <iostream> // read things from the screen and print on screen. 
#include <fstream>  // read/write things from and to a file 
#include <string>	// if your program deals with string data

using namespace std;

int main()
{
	int choose;
	int charge;
	int truck;
	int truck1_status = 0;
	int truck2_status = 0;
	int total = 0;

	do
	{
		
		cout << "* TRUCK MORE SCHEDULE V 1.0 *" << endl;
		cout << "1- Dispatch Truck to work" << endl;
		cout << "2- Truck Returned Home" << endl;
		cout << "3- Report" << endl;
		cout << "0- Exit" << endl;

		cout << "What do u want to do? ";
		cin >> choose;

		if (choose == 1) // choose #1
		{
			cout << "Which Truck do u want to send <1 or 2>? ";
			cin >> truck;

			if (truck == 1) //choose the truck #1
			{
				if (truck1_status == 0)
				{
					cout << "How much are we charging for this? ";
					cin >> charge;
					total += charge;

					cout << "Truck #1 is dispatched.";
					truck1_status = 1;
				}

				else if (truck1_status == 1)
				{
					cout << "Sorry, truck 1 is currently busy.";
				}
			}

			else //choose the truck #2
			{
				if (truck2_status == 0)
				{
					cout << "How much are we charging for this? ";
					cin >> charge;
					total += charge;

					cout << "Truck #2 is dispatched.";
					truck2_status = 1;
				}

				else if (truck2_status == 1)
				{
					cout << "Sorry, truck 2 is currently busy.";
				}
			}
		}

		else if (choose == 2) //choose #2
		{
			cout << "Which truck returned home <1 or 2> ";
			cin >> truck;
			if (truck == 1)
			{
				if (truck1_status == 0)
					cout << "Truck 1 is already available.";
				if (truck1_status == 1)
				{
					cout << "Truck 1 is now available now.";
					truck1_status = 0;
				}
			}
			else //truck 2
			{
				if (truck2_status == 0)
					cout << "Truck 2 is already available.";
				if (truck2_status == 1)
				{
					cout << "Truck 2 is now available now.";
					truck2_status = 0;
				}
			}
		}
		
		else if (choose == 3) //choose #3
		{
			cout << "Total amount enarned today is $" << total << endl;
			//show the status of the truck
			if (truck1_status == 0)
				cout << "Truck #1 is available." 
			else if (truck1_status == 1)
				cout << "Truck #1 is dispatched.";
			if (truck2_status == 0)
				cout << "Truck #2 is available.";
			else if (truck2_status == 1)
				cout << "Truck #2 is dispatched.";
		}

	} while (choose != 0);

	system("pause");
	return 0;
}