#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Car
{
public:
	string Model;
	double MPG;
	int Horsepower;
	string Origin;
};

//Prototype
void ReadFile(Car cars[], int &count);
void SearchCar(Car cars[], int count);
void BWReport(Car cars[], int count);
void OriginReport(Car cars[], int count);

//Main function
int main()
{
	Car cars[500];
	int count = 0;
	int choice;

	ReadFile(cars, count);

	do
	{
		cout << "Welcome to Antique Car Search" << endl;
		cout << "=============================" << endl;
		cout << "1- Search Car" << endl;
		cout << "2- Green Best/Worst Report" << endl;
		cout << "3- Car Origin Report" << endl;
		cout << "0- Exit" << endl;

		cout << "Make a Choice: ";
		cin >> choice;


		if (choice == 1)
		{
			SearchCar(cars, count);
		}

		else if (choice == 2)
		{
			BWReport(cars, count);
		}

		else if (choice == 3)
		{
			OriginReport(cars, count);
		}

	} while (choice != 0);

	system("pause");
	return 0;
}

void ReadFile(Car cars[], int &count)
{
	//check the file exist or not
	ifstream file("cars.txt");

	if (!file)
	{
		cout << "This file does not exist." << endl;
	}

	while (!file.eof())
	{
		file >> cars[count].Model;
		if (cars[count].Model == "")
		{
			return;
		}
		file >> cars[count].MPG;
		file >> cars[count].Horsepower;
		file >> cars[count].Origin;
		count++;
	}

	file.close();
}

void SearchCar(Car cars[], int count)
{
	int dcount = 0;
	double min_MPG;
	int min_horsepower;

	cout << "Required Min. MPG: ";
	cin >> min_MPG;
	cout << "Required Min. horsepower: ";
	cin >> min_horsepower;

	for (int i = 0; i < count; i++)
	{
		if (cars[i].Horsepower >= min_horsepower && cars[i].MPG >= min_MPG)
		{
			dcount++;
			cout << dcount << "- " << cars[i].Model << endl;
		}
	}

	cout << "found " << dcount << " cars matching the criteria." << endl;
	cout << endl;
}

void BWReport(Car cars[], int count)
{
	int tcount = 0;
	double sum_MPG = 0;
	int best_index = 0;
	int worst_index = 0;


	for (int i = 0; i < count; i++)
	{
		sum_MPG += cars[i].MPG;
		tcount++;

		if (cars[i].MPG > cars[best_index].MPG)
		{
			best_index = i;
		}

		if (cars[i].MPG < cars[worst_index].MPG)
		{
			worst_index = i;
		}
	}

	cout << "Avg MPG of all cars is: " << sum_MPG / tcount << endl;
	cout << "Greenest car of all: " << cars[best_index].Model << " with " << cars[best_index].MPG << endl;
	cout << "Worst car of all: " << cars[worst_index].Model << " with " << cars[worst_index].MPG << endl;
	cout << endl;
}

void OriginReport(Car cars[], int count)
{
	string myorigin;
	int dcount = 0;

	cout << "Enter Origin: ";
	cin >> myorigin;

	for (int i = 0; i < count; i++)
	{
		if (myorigin == cars[i].Origin)
		{
			dcount++;
		}
	}

	cout << "We have " << dcount << " " << myorigin << " cars in the inventory." << endl;
	cout << endl;
}

