#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//class
class City
{
public:
	string Name;
	int NumOfOutages;
	int TotalCust;
};
//prototype
void ReadFile(City city[], int &count);
void QueryCity(City city[], int count);
void CityWithMostOutage(City city[], int count);

//main function
int main()
{
	class City city[500];
	int choice = 0;
	int count = 0;

	ReadFile(city, count);

	//main menu
	do
	{
		cout << "LIPA Operation Desk" << endl;
		cout << "===================" << endl;
		cout << "1- Query City" << endl;
		cout << "2- City with most outage" << endl;
		cout << "0- Exit" << endl;

		cout << "What do u want?";
		cin >> choice;

		if (choice == 1)
		{
			QueryCity(city, count);
		}

		else if (choice == 2)
		{
			CityWithMostOutage(city, count);
		}

	} while (choice != 0);

	system("pause");
	return 0;
}

//other function
void ReadFile(City city[], int &count)
{
	ifstream file("data.txt");

	if (!file)
	{
		cout << "There's no file exist." << endl;
	}

	else
	{
		while (!file.eof())
		{
			file >> city[count].Name;
			if (city[count].Name == "")
			{
				return;
			}
			file >> city[count].NumOfOutages;
			file >> city[count].TotalCust;
			count++;
		}
		file.close();
	}
}

void QueryCity(City city[], int count)
{
	string mycity;

	cout << "What is the city u want to search? ";
	cin >> mycity;

	for (int i = 0; i < count; i++)
	{
		if (mycity == city[i].Name)
		{
			cout << mycity << " city has " << city[i].NumOfOutages << " outages and " << city[i].TotalCust << " customers." << endl;
		}
	}
	cout << endl;
}

void CityWithMostOutage(City city[], int count)
{
	int max_index = 0;

	for (int i = 0; i < count; i++)
	{
		double outage_percent = 0;

		if (city[i].TotalCust != 0)
		{
			outage_percent = city[i].NumOfOutages / city[i].TotalCust;
		}

		else if (city[i].TotalCust == 0)
		{
			cout << "There's no customers." << endl;
		}

		if (outage_percent > city[max_index].NumOfOutages / city[max_index].TotalCust)
		{
			max_index = i;
		}
	}

	cout << city[max_index].Name << " is the city with the most precentage of customers without power." << endl;
	cout << endl;
}