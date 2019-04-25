#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Detective
{
    public:
		string Name;
		string Specialty;
		int Experience;

};

void ReadFile(Detective detectives[], int &count);
void WriteFile(Detective detectives[], int count);
void AddDetective(Detective detectives[], int &count);
void Search(Detective detectives[], int count);
void Report(Detective detectives[], int count);

int main()
{
	Detective detectives[100];
	int count = 0;
	int choice;

	ReadFile(detectives, count);

	do
	{
		cout << "Welcome to detective" << endl;
		cout << "====================" << endl;
		cout << "1- Add a detective" << endl;
		cout << "2- Search a detective" << endl;
		cout << "3- Report" << endl;
		cout << "0- Exit" << endl;

		cout << "Make a Choice: ";
		cin >> choice;


		if (choice == 1)
		{
			AddDetective(detectives, count);
		}

		else if (choice == 2)
		{
			Search(detectives, count);
		}

		else if (choice == 3)
		{
			Report(detectives, count);
		}

	} while (choice != 0);
	
	WriteFile(detectives, count);

	system("pause");
	return 0;
}

void ReadFile(Detective detectives[], int &count)
{
	ifstream fileIn("detectives.txt");

	if (!fileIn)
	{
		return;
	}

	while (!fileIn.eof())
	{
		fileIn >> detectives[count].Name;
		fileIn >> detectives[count].Specialty;
		fileIn >> detectives[count].Experience;

		count++;
	}

	fileIn.close();
}


void WriteFile(Detective detectives[], int count)
{
	ofstream fileOut("detectives.txt");

	for (int i = 0; i < count; i++)
	{
		fileOut << detectives[i].Name << " " << detectives[i].Specialty << " " << detectives[i].Experience;

		if (i < count - 1)
		{
			fileOut << endl;
		}
	}
	fileOut.close();
}

void AddDetective(Detective detectives[], int &count)
{
	string name;
	string specialty;
	int experience;
	bool detective = true;

	cout << "Enter the name of the detective that u want to add: ";
	cin >> name;

	cout << "Enter the specialty of that detective: ";
	cin >> specialty;

	cout << "Enter the experience of that detective: ";
	cin >> experience;

	//check that whether that detective is alright exist or not
	for(int i = 0; i < count; i++)
	{
		if (name == detectives[i].Name)
		{
			detective = false;
		}
	}

	if (detective) //there's no repetitive detective in the department
	{
		detectives[count].Name = name;
		detectives[count].Specialty = specialty;
		detectives[count].Experience = experience;
		count++;

	}

	else // The detective is repetitive in the department
	{
		cout << "The department already has a detective with this name." << endl;
	}
}

void Search(Detective detectives[], int count)
{
	string myspecialty;
	int minexperience;
	string most_experience;
	int maxexperience = -1;

	cout << "What specialty do u need? [Homicide, Fraud, Theft, Traffic or Gangs] ";
	cin >> myspecialty;

	cout << "What's the minimum years of experience required? ";
	cin >> minexperience;

	for (int i = 0; i < count; i++)
	{
		if (detectives[i].Specialty == myspecialty)
		{
			if (detectives[i].Experience >= minexperience) //fit the minimum years criteria
			{
				if (detectives[i].Experience > maxexperience)
				{
					maxexperience = detectives[i].Experience;
					most_experience = detectives[i].Name;
				}
			}
		}
	}

	cout << "Detective " << most_experience << " is the perfect fit for the job." << endl;

}

void Report(Detective detectives[], int count)
{
	string myDepartment;

	cout << "What is the department u want to see? [Homicide, Fraud, Theft, Traffic or Gangs] ";
	cin >> myDepartment;
	cout << myDepartment << endl;
	cout << "===============================" << endl;


	for (int i = 0; i < count; i++)
	{
		if (detectives[i].Specialty == myDepartment)
		{
			cout << "Detective " << detectives[i].Name << " with " << detectives[i].Experience << " years of experience." << endl;
		}
	}
}