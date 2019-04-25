#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Disease
{
public:
	string Name;
	string Symptom;

};

//Prototype
void ReadFile(Disease disease[], int &count);
void DiseaseCount(Disease disease[], string diseases[], int &disease_count, int count);
void SymptomCount(Disease disease[], string diseases[], int disease_count, int count);
void Diagnose(Disease disease[], string diseases[], int disease_count, int count);

//Main function
int main()
{
	Disease disease[100];
	int choice;
	int count = 0;
	int disease_count = 0;
	string diseases[50];

	//Read The File
	ReadFile(disease, count);

	do
	{
		cout << "Welcome to diagnostic Assist" << endl;
		cout << "============================" << endl;
		cout << "1- Display Disease Count" << endl;
		cout << "2- Symptom Count by Disease" << endl;
		cout << "3- Diagnose" << endl;
		cout << "0- Exit" << endl;

		cout << "What do u want to do: ";
		cin >> choice;


		if (choice == 1)
		{
			DiseaseCount(disease, diseases, disease_count, count);
		}

		else if (choice == 2)
		{
			SymptomCount(disease, diseases, disease_count, count);
		}

		else if (choice == 3)
		{
			Diagnose(disease, diseases, disease_count, count);
		}

	} while (choice != 0);

	system("pause");
	return 0;
}

//Functions
void ReadFile(Disease disease[], int &count)
{
	ifstream file("diagnostic.txt");

	if (!file)
	{
		cout << "There's no file exist." << endl;
	}

	while (!file.eof())
	{
		file >> disease[count].Name;
		file >> disease[count].Symptom;

		count++;
	}
}

void DiseaseCount(Disease disease[], string diseases[], int &disease_count, int count)
{

	for (int i = 0; i < count; i++)
	{
		bool disease_exist = false;

		for (int j = 0; j < count; j++)
		{
			if (disease[i].Name == diseases[j])
			{
				disease_exist = true;
			}
		}

		if (!disease_exist)
		{
			diseases[disease_count] = disease[i].Name;
			disease_count++;
		}
	}

	cout << "There are " << disease_count << " diseases in the database." << endl;
	cout << endl;
}

void SymptomCount(Disease disease[], string diseases[], int disease_count, int count)
{
	string symptoms[50];

	for (int i = 0; i < disease_count; i++)
	{
		int symptom_count = 0;
		
		for (int j = 0; j < count; j++)
		{
			if (diseases[i] == disease[j].Name)
			{
				symptom_count++;
			}
		}

		cout << "There are " << symptom_count << " symptoms for " << diseases[i] << endl;
	}
	
	cout << endl;
}

void Diagnose(Disease disease[], string diseases[], int disease_count, int count)
{
	string mysymptom;

	cout << "What is your symptom? ";
	cin >> mysymptom;

	for (int i = 0; i < count; i++)
	{
		if (mysymptom == disease[i].Symptom)
		{
			cout << "You may have " << disease[i].Name << endl;
		}
	}
	
	cout << endl;
}