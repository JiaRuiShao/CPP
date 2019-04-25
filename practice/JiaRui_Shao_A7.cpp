#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// PROTOTYPES
void population_report(string counties[], string state[], int population[], int count);
void population_range(string counties[], string state[], int population[], int count);
void similar_state(string counties[], string state[], int population[], int count);
void state_population(string counties[], string state[], int population[], int count);

//MAIN FUNCTION
int main()
{
	string counties[5000];
	string state[5000];
	int population[5000];
	int count = 0;
	int choice;

	//check the file
	fstream check_file;
	check_file.open("counties.txt");
	if (check_file.fail())
	{
		cout << "The file does not exist" << endl;
	}
	else
	{
		//read from file
		ifstream file("counties.txt");

		while (!file.eof())
		{
			file >> counties[count];
			file >> state[count];
			file >> population[count];
			count++;
		}

		file.close();

		//main menu
		do
		{
			cout << "Census Analysis 2010" << endl;
			cout << "====================" << endl;
			cout << "1- Population Report" << endl;
			cout << "2- counties By Range" << endl;
			cout << "3- Similarity counties" << endl;
			cout << "4- Populous State" << endl;
			cout << "0- Exit" << endl;
			
			cout << "What do you want to do? ";
			cin >> choice;

			if (choice == 1)
			{
				population_report(counties, state, population, count);
			}

			else if (choice == 2)
			{
				population_range(counties, state, population, count);
			}

			else if (choice == 3)
			{
				similar_state(counties, state, population, count);
			}
			
			else if (choice == 4)
			{
				state_population(counties, state, population, count);
			}

		} while (choice != 0);
	}
	

	system("pause");
	return 0;
}

//FUNCTION FOR CHOICE 1
void population_report(string counties[], string state[], int population[], int count)
{
	int most_pop = -1;
	string most_country;
	string most_state;
	int least_pop = 100000000000;
	string least_country;
	string least_state;
	int total = 0;
	
	for (int i = 0; i < count; i++)
	{
		total += population[i];
		
		if (population[i] > most_pop)
		{
			most_pop = population[i];
			most_country = counties[i];
			most_state = state[i];
		}

		else if (population[i] < least_pop)
		{
			least_pop = population[i];
			least_country = counties[i];
			least_state = state[i];
		}
	}

	cout << "The most populous country is: " << most_country << "(" << most_state << ")" << endl;
	cout << "The least populous country is: " << least_country << "(" << least_state << ")" << endl;
	cout << "The average population is: " << total/count << endl;
}

//FUNCTION FOR CHOICE 2
void population_range(string counties[], string state[], int population[], int count)
{
	int max = -1;
	int min = 1000000000000000;

	cout << "Enter Max. Population: ";
	cin >> max;
	cout << "Enter Min. Population: ";
	cin >> min;

	for (int i = 0; i < count; i++)
	{
		if (population[i] <= max && population[i] >= min)
		{
			cout << counties[i] << "(" << state[i] << "): " << population[i] << endl;
		}
	}
}

//FUNCTION FOR CHOICE 3
void similar_state(string counties[], string state[], int population[], int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (i != j && population[i] == population[j] && state[i] == state[j])
			{
				cout << "Here are similar counties:"<< endl;
				cout << counties[i] << "(" << state[i] << ") " << "and " << counties[j] << "(" << state[j] << ")" << endl;
			}
		}
	}
}

//FUNCTION FOR CHOICE 4
void state_population(string counties[], string state[], int population[], int count)
{
	string currState;
	string maxState;
	int currStatePop = 0;
	int maxStatePop = -1;
	
	for (int i = 0; i < count; i++)
	{
		currState = state[i];

		for (int j = 0; j < count; j++)
		{
			if (currState == state[j])
			{
				currStatePop += population[j];
			}
		}

		if (currStatePop > maxStatePop)
		{
			maxState = currState;
			maxStatePop = currStatePop;
		}
	}

	cout << "Most populous state is " << maxState << " with " << maxStatePop << " population." << endl;
}