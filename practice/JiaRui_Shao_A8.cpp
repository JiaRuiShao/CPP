# include <iostream>
# include <fstream>

using namespace std;

// PROTOTYPE
void performance_rating(int cgmA[], int cgmB[], int count);
void similarity_rating(int cgmA[], int cgmB[], int count);
void summary_report(int cgmA[], int cgmB[], int count);

// MAIN FUNCTION
int main()
{
	int choice;
	int count = 0;
	int issue[100];
	int cgmA[100];
	int cgmB[100];

	//check the file
	fstream check_file;
	check_file.open("votes.txt");
	if (check_file.fail())
	{
		cout << "The file does not exist." << endl;
	}
	else
	{
		//read from file
		ifstream file("votes.txt");

		while (!file.eof())
		{
			file >> issue[count];
			file >> cgmA[count];
			file >> cgmB[count];
			count++;
		}

		file.close();
	}

	// MAIN LOOP
	do
	{
		cout << "Voting Record Analysis" << endl;
		cout << "=====================" << endl;
		cout << "1: Performance Rating" << endl;
		cout << "2: Similarity Rating" << endl;
		cout << "3: Summary Report" << endl;
		cout << "0: Exit" << endl;

		cout << "What do you want to choice: ";
		cin >> choice;

		// CHOICE 1: Performance Rating
		if (choice == 1)
		{
			performance_rating(cgmA, cgmB, count);
		}

		// CHOICE 2: Similarity Rating
		if (choice == 2)
		{
			similarity_rating(cgmA, cgmB, count);
		}

		// CHOICE 3: Summary Report
		if (choice == 3)
		{
			summary_report(cgmA, cgmB, count);
		}

	} while (choice != 0);

	system("pause");
	return 0;
}

// FUNCTIONS
void performance_rating(int cgmA[], int cgmB[], int count)
{
	double misscountA = 0;
	double misscountB = 0;

	for (int i = 0; i < count; i++)
	{
		if (cgmA[i] == 0)
		{
			misscountA++;
		}

		if (cgmB[i] == 0)
		{
			misscountB++;
		}
	}

	cout << "Congressman A Performance Score: " << misscountA / count << endl;
	cout << "Congressman B Performance Score: " << misscountB / count << endl;

	if (misscountA / count > misscountB / count)
	{
		cout << "Congressman A missed more voting than Congressman B." << endl;
	}
	else if (misscountA / count < misscountB / count)
	{
		cout << "Congressman B missed more voting than Congressman A." << endl;
	}
}

void similarity_rating(int cgmA[], int cgmB[], int count)
{
	double similarity_total = 0;
	double valid_count = count;

	for (int i = 0; i < count; i++)
	{
		if (cgmA[i] == 0 && cgmB[i] == 0)
			valid_count -= 1;
		else if (cgmA[i] == cgmB[i])
			similarity_total++;
	}

	cout << "Similarity Rate is: " << similarity_total / valid_count << endl;
}

void summary_report(int cgmA[], int cgmB[], int count)
{
	int YeaA = 0;
	int YeaB = 0;
	int NayA = 0;
	int NayB = 0;
	int MissA = 0;
	int MissB = 0;

	for (int i = 0; i < count; i++)
	{
		if (cgmA[i] == 1)
			YeaA++;
		if (cgmA[i] == 0)
			MissA++;
		if (cgmA[i] == -1)
			NayA++;
		if (cgmB[i] == 1)
			YeaB++;
		if (cgmB[i] == 0)
			MissB++;
		if (cgmB[i] == -1)
			NayB++;
	}

	cout << "Congressman A:" << endl;
	cout << "  Yea: " << YeaA << endl;
	cout << "  Nay: " << NayA << endl;
	cout << "  Miss: " << MissA << endl;
	cout << "Congressman B:" << endl;
	cout << "  Yea: " << YeaB << endl;
	cout << "  Nay: " << NayB << endl;
	cout << "  Miss: " << MissB << endl;
}