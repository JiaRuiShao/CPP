/*
Your job is to create a reservation system for a restaurant. The restaurant has 20 tables.
Here is the functionality required for this system (you may want to display a menu and let user choose options 1 to 4,
make sure to put your program in a loop so program does not exit until user chooses menu 0):

1- Reserve a Table
User needs to input the table number (Tables are numbered from 0 to 19).
If the table is not available (reserved), inform the user that the selected table is not available.
If the table is available, then ask for the name (name is a single word, no space) and mark the table as reserved.

2- Clear Reservation
User needs to input the table number (Tables are numbered from 0 to 19).
If the table is not reserved, inform the user that the selected table is already available (nothing to clear).
If the table is reserved, mark it as available. That table is no longer reserved.

3- Report
Prints out the state of each table. Each table is printed on a separate line -- so your report will print out 20 rows.
If reserved, it will print out the name on the reservation next to the table number.
If available, it should print out "available".

0- Exit Program.

I would recommend either:

a) keeping two arrays (parallel arrays!), both are size 20, one of type boolean (true/false -- reserved/available)
and the other one of type string (name on reservation if reserved, blank otherwise).

b) keeping a single array of size 20 of type string. At the beginning of the program, set all the tables to "AVAILABLE".
As tables get reserved, set the table array item as the name on the reservation .
If the value on a table is "AVAILABLE" then the table is available (not reserved) otherwise, the table is reserved and the value is the name on the reservation.

*/
#include<iostream>
#include<fstream>
#include <string>

using namespace std;

int main()
{
	//INPUT
	int num;
	bool status[20] = { false };
	string names[20];
	int choice;

	//PROCESSING
	do
	{
		cout << "Reservation System" << endl;
		cout << "==================" << endl;
		cout << "1- Reserve a table" << endl;
		cout << "2- Clear Reservation" << endl;
		cout << "3- Report" << endl;
		cout << "0- Exit" << endl;

		cout << "What do u want to do? ";
		cin >> choice;

		if (choice == 1)
		{
			cout << "Which table u want to reserve? ";
			cin >> num;

			//If the room is available
			if (status[num] == false)
			{
				//ask for the name
				cout << "What's u name: ";
				cin >> names[num];

				//mark the table as reserved
				status[num] = true;
			}

			//If the room is reserved
			else if (status[num] == true)
			{
				cout << "Sorry, this table is not available." << endl;
			}
		}

		else if (choice == 2)
		{
			cout << "U want to clear which table's reservation? ";
			cin >> num;

			//If the room is available
			if (status[num] == false)
			{
				cout << "This table is already available." << endl;
			}

			//If the room is reserved
			if (status[num] == true)
			{
				status[num] = false;
				cout << "This table is available now." << endl;
			}
		}

		else if (choice == 3)
		{
			for (int i = 0; i < 20; i++)
			{
				if (status[i] == true)
					cout << "The table " << i << " is reserved. The reservor is " << names[i] << endl;
				else
					cout << "The table " << i << " is available." << endl;
			}
		}

		else if (choice != 0 && choice != 1 && choice != 2 && choice != 3)
			cout << "There's no such choice!" << endl;

	} while (choice != 0);


	//OUTPUT

	system("pasue");
	return 0;
}