//Ticket Master
# include <iostream>;
# include <fstream>;
# include <string>;

using namespace std;

//Protoytpe
int *add_ticket(int section_num[], string team_name[], int price[], int &count);
void display_ticket(int section_num[], string team_name[], int price[], int count);
void budget(int section_num[], string team_name[], int price[], int count);
int interested_event(int &lowest_price, string team_name[], int price[], int count, bool &team_exist);

//Main function
int main()
{
	string team_name[50];
	int section_num[50];
	int price[50];
	int count = 0;
	int choice;

	//main menu
	do
	{
		cout << "Ticket Master" << endl;
		cout << "=============" << endl;
		cout << "1- Add new ticket" << endl;
		cout << "2- Display all tickets" << endl;
		cout << "3- Display tickets by budget" << endl;
		cout << "4- Display cheapest tickets by event" << endl;
		cout << "0- Exit" << endl;

		cout << "What do u want to do? ";
		cin >> choice;

		//choice is 1 | Add new ticket
		if (choice == 1)
		{
			add_ticket(section_num, team_name, price, count);
		}

		//choice is 2 | Display all tickets
		if (choice == 2)
		{
			display_ticket(section_num, team_name, price, count);
		}

		//choice is 3 | Display tickets by budget
		if (choice == 3)
		{
			budget(section_num, team_name, price, count);
		}

		//choice is 4 | Display cheapest tickets by event
		if (choice == 4)
		{
			bool team_exist = true;
			int lowest_price = 100000000;

			interested_event(lowest_price, team_name, price, count, team_exist);

			if (team_exist == false)
				cout << "Cannot find the ticket of this team." << endl;
			else
				cout << "The cheaptest price for this event is: " << lowest_price << endl;

		}

	} while (choice != 0);

	system("pause");
	return 0;
}

//Functions
int *add_ticket(int section_num[], string team_name[], int price[], int &count)
{
	char add_ticket = 'y';

	while (add_ticket == 'y')
	{
		cout << "Enter ticket number: ";
		cin >> section_num[count];

		cout << "Enter the name of the team Knicks is playing against: ";
		cin >> team_name[count];

		cout << "Enter ticket price: ";
		cin >> price[count];

		cout << "Would u like to add another ticket? (y/n)";
		cin >> add_ticket;

		count++;
	}

	return section_num, team_name, price;
}
void display_ticket(int section_num[], string team_name[], int price[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "section: " << section_num[i] << endl;
		cout << "team name: " << team_name[i] << endl;
		cout << "price: " << price[i] << endl;
	}
}

void budget(int section_num[], string team_name[], int price[], int count)
{
	int budget;
	cout << "What is your budget? ";
	cin >> budget;

	for (int i = 0; i < count; i++)
	{
		if (budget >= price[i])
		{
			cout << "section: " << section_num[i] << endl;
			cout << "team name: " << team_name[i] << endl;
			cout << "price: " << price[i] << endl;
		}

	}
}

int interested_event(int &lowest_price, string team_name[], int price[], int count, bool &team_exist)
{
	string team;

	cout << "What is your interested team: ";
	cin >> team;

	for (int i = 0; i < count; i++)
	{
		if (team == team_name[i])
		{
			if (lowest_price > price[i])
				lowest_price = price[i];
		}

		else
			team_exist = false;
	}

	return team_exist;
}