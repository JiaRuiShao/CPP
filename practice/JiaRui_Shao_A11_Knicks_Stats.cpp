#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//class
class Player 
{
public:
	string Name;
	int Points;
	int Rebounds;
	int Assists;
};
//prototype
void ReadFile(Player player[], int &count);
void MostScore(Player player[], int count);
void DDouble(Player player[], int count);
void TDouble(Player player[], int count);
void Report(Player player[], int count);

//main function
int main()
{
	class Player player[20];
	int choice;
	int count = 0;

	//read the file
	ReadFile(player, count);

	//main menu
	do
	{
		cout << "Knicks Stats App Main Menu" << endl;
		cout << "==========================" << endl;
		cout << "1- Most Scorer Player" << endl;
		cout << "2- Double-Double" << endl;
		cout << "3- Triple-Double" << endl;
		cout << "4- Report" << endl;
		cout << "0- Exit" << endl;

		cout << "What do u want to do: ";
		cin >> choice;

		if (choice == 1)
		{
			MostScore(player, count);
		}

		else if (choice == 2)
		{
			DDouble(player, count);
		}

		else if (choice == 3)
		{
			TDouble(player, count);
		}

		else if (choice == 4)
		{
			Report(player, count);
		}

	} while (choice != 0);

	system("pasue");
	return 0;
}
//other functions
void ReadFile(Player player[], int &count)
{
	//check the file exist or not
	ifstream file("knicks.txt");

	if (!file)
	{
		cout << "This file does not exist." << endl;
	}

	while (!file.eof())
	{
		file >> player[count].Name;
		if (player[count].Name == "")
		{
			return;
		}
		file >> player[count].Points;
		file >> player[count].Rebounds;
		file >> player[count].Assists;
		count++;
	}
	
	file.close();
}

void MostScore(Player player[], int count)
{
	int most_point=-1;
	string most_point_name;

	for (int i = 0; i < count; i++)
	{
		if (most_point < player[i].Points)
		{
			most_point = player[i].Points;
			most_point_name = player[i].Name;
		}
	}

	cout << "Most scorer player is " << most_point_name << "!" << endl;
	cout << endl;
}

void DDouble(Player player[], int count)
{
	for (int i = 0; i < count; i++)
	{
		int dcount = 0;

		if (player[i].Points > 9)
		{
			dcount++;
		}

		if (player[i].Rebounds > 9)
		{
			dcount++;
		}

		if (player[i].Assists > 9)
		{
			dcount++;
		}

		if (dcount >= 2)
		{
			cout << player[i].Name << " achieved double double." << endl;
		}
	}

	cout << endl;
}

void TDouble(Player player[], int count)
{
	for (int i = 0; i < count; i++)
	{
		int tcount = 0;
		
		if (player[i].Points > 9)
		{
			tcount++;
		}

		if (player[i].Rebounds > 9)
		{
			tcount++;
		}

		if (player[i].Assists > 9)
		{
			tcount++;
		}

		if (tcount > 2)
		{
			cout << player[i].Name << " achieved triple double." << endl;
		}
	}

	cout << endl;
}

void Report(Player player[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << player[i].Name << endl;
		cout << "Points: " << player[i].Points << " | Assist: " << player[i].Assists << " | Rebound: " << player[i].Rebounds << endl;
		cout << endl;
	}
}