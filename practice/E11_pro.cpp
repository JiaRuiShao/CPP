#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// we want to keep a list of cities
// for that, let's define a City class
// where each city has a Name, Number of 
// outages and total number of customers.
class City
{
public:
	string Name;
	int Outages;
	int Customers;
};

// notice that cityCount is by reference
void LoadFile(City cities[], int &cityCount)
{
	// I will use the full path here because some of you
	// have troble placing the files to the correct location.
	// notice that I use double \\ because "\" is an escape character
	// following statement opens the file
	ifstream fileIn("C:\\Users\\akoc\\Desktop\\data.txt");

	// before reading the file, set the number of cities to zero
	// we will inrement it as we read information from the file
	cityCount = 0;

	// start reading the file and continue
	// reading until we get to the end of the file
	while (!fileIn.eof())
	{
		// first we read the name, then outages, then customers
		fileIn >> cities[cityCount].Name;
		fileIn >> cities[cityCount].Outages;
		fileIn >> cities[cityCount].Customers;
		// increment city count so the next repetition
		// of the loop will fill in the next box of cities array
		cityCount++;
	}
}

void QueryCity(City cities[], int cityCount)
{
	string name;
	cout << "What is the city name: ";
	cin >> name;

	bool found = false;

	for (int i = 0; i < cityCount; i++)
	{
		if (cities[i].Name == name)
		{
			cout << "Found city: " << name << endl;
			cout << "Outages: " << cities[i].Outages << endl;
			cout << "Customers: " << cities[i].Customers << endl;
			found = true;
		}
	}

	if (found == false)
	{
		cout << "Could not find a city with that name" << endl;
	}
}

void CityWithMostOutage(City cities[], int cityCount)
{
	int maxIndex = 0;
	double outagePercentMax = cities[maxIndex].Outages / cities[maxIndex].Customers;

	for (int i = 1; i < cityCount; i++)
	{
		double outagePercentCurrent = cities[i].Outages / cities[i].Customers;

		if (outagePercentCurrent > outagePercentMax)
		{
			maxIndex = i;
			outagePercentMax = outagePercentCurrent;
		}
	}

	cout << "City with most outage is:" << endl;
	cout << "Name: " << cities[maxIndex].Outages << endl;
	cout << "Outages: " << cities[maxIndex].Outages << endl;
	cout << "Customers: " << cities[maxIndex].Customers << endl;
}

int main()
{
	City cities[400];
	int cityCount;

	LoadFile(cities, cityCount);

	while (true)
	{
		cout << "1- Query City By Name" << endl;
		cout << "2- City With Most Outage" << endl;
		cout << "0- Exit" << endl;
		int choice;
		cin >> choice;

		if (choice == 1)
		{
			QueryCity(cities, cityCount);
		}
		else if (choice == 2)
		{
			CityWithMostOutage(cities, cityCount);
		}
		else if (choice == 0)
		{
			break;
		}
	}



	system("PAUSE");
	return 0;
}