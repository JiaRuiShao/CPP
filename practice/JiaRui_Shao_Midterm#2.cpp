//JiaRui Shao
# include <iostream>;
# include <fstream>;
# include <string>;

using namespace std;

//Protoytpe
void read_file(string state[], double cost[], int &count);
void save_file(string state[], double cost[], int count);
void creat_mail(string state[], double cost[], int &count);
void search_mail_state(string state[], double cost[], int count);
void search_mail_cost(string state[], double cost[], int count);
void grand_report(string state[], double cost[], int count);

//Main function
int main()
{
	int choice = 0;
	string state[1000];
	double cost[1000];
	int count = 0;

	read_file(state, cost, count);

	cout << "==============================================" << endl;
	cout << "Welcome to FedEx in the middle of nowhere. :-)" << endl;
	cout << "This tool will help you keep track of packages." << endl;
	cout << "==============================================" << endl;

	//main menu
	do
	{
		cout << "1- Creat New Mail" << endl;
		cout << "2- Search Mail (by state)" << endl;
		cout << "3- Search Mail (by cost)" << endl;
		cout << "4- Grand Report" << endl;
		cout << "0- Exit" << endl;

		cout << "What do u want to do? ";
		cin >> choice;

		//choice is 1 | Creat New Mail
		if (choice == 1)
		{
			creat_mail(state, cost, count);
		}

		//choice is 2 | Search Mail (by state)
		if (choice == 2)
		{
			search_mail_state(state, cost, count);
		}

		//choice is 3 | Search Mail (by cost)
		if (choice == 3)
		{
			search_mail_cost(state, cost, count);
		}

		//choice is 4 | Grand Report
		if (choice == 4)
		{
			grand_report(state, cost, count);
		}

	} while (choice != 0);

	system("pause");
	return 0;
}

//function 0 | read file
void read_file(string state[], double cost[], int &count)
{
	//check whether the file exist or not
	fstream check_file;
	check_file.open("package.txt");

	if (check_file.fail())
	{
		cout << "There's no such file exist." << endl;
	}

	else
	{
		//read from file
		ifstream file("package.txt");

		while (!file.eof())
		{
			file >> state[count];
			file >> cost[count];
			count++;
		}

		file.close();
	}
}

// function 0.5 | save the file
void save_file(string state[], double cost[], int count)
{
	ofstream myfile("package.txt", ios::app);
	myfile << state[count];
	myfile << " ";
	myfile << cost[count];
	myfile << "\n";

	myfile.close();

}

//function 1 | Creat New Mail
void creat_mail(string state[], double cost[], int &count)
{
	//ask the user to input the data
	cout << "Destination State (2 letter, no space): ";
	cin >> state[count];
	cout << "Cost of this delivery? ";
	cin >> cost[count];

	//save the data to file
	save_file(state, cost, count);

	count++;
}

//function 2 | Search Mail (by state)
void search_mail_state(string state[], double cost[], int count)
{
	string mystate;

	//ask the user to enter the destination state
	cout << "Enter the state you want to see (two letter, no space): ";
	cin >> mystate;

	for (int i = 0; i < count; i++)
	{
		if (mystate == state[i])
		{
			cout << "Package to " << mystate << " for $" << cost[i] << endl;
		}
	}
}

//function 3 | Search Mail (by cost)
void search_mail_cost(string state[], double cost[], int count)
{
	double mycost;

	//ask the user to enter the destination state
	cout << "Enter minimum package price: ";
	cin >> mycost;

	for (int i = 0; i < count; i++)
	{
		if (mycost < cost[i])
		{
			cout << "Here are the packages that are larger in value than 6:" << endl;
			cout << "Package to " << state[i] << " for $" << cost[i] << endl;
		}
	}
}

//function 4 | Grand Report
void grand_report(string state[], double cost[], int count)
{
	double total = 0;

	cout << "Here are all the packages for today:" << endl;

	for (int i = 0; i < count; i++)
	{
		cout << "Package to " << state[i] << " for $" << cost[i] << endl;
		total += cost[i];
	}

	cout << "Total cost for all packages today so far is $" << total << "." << endl;
}
