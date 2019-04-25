#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Donation
{
public:

	int Anders_donation;
	int Valerie_donation;
	string myName;

};

void ReadFile(Donation donation[], int &count);
void WriteFile(Donation donation[], int count);
int cal_total(Donation donation[], int count);
void AddNew(Donation donation[], int& Anders_total, int& Valerie_total, int &Anders_count, int &Valerie_count, int &count);

void ReadFile(Donation donation[], int &count)
{
	ifstream fileIn("donation.txt");

	if (!fileIn)
	{
		return;
	}

	while (!fileIn.eof())
	{
		fileIn >> donation[count].Anders_donation;
		fileIn >> donation[count].myName;

		fileIn >> donation[count].Valerie_donation;
		fileIn >> donation[count].myName;

		count++;
	}

	fileIn.close();
}

void WriteFile(Donation donation[], int count)
{
	ofstream fileOut("donation.txt");

	for (int i = 0; i < count; i++)
	{
		fileOut << donation[i].Anders_donation << " " << donation[i].myName << endl;
		fileOut << donation[i].Valerie_donation << " " << donation[i].myName;

		if (i < count - 1)
		{
			fileOut << endl;
		}
	}
	fileOut.close();
}

int cal_total(Donation donation[], int count)
{
	int Anders_total = 0;
	int Valerie_total = 0;
	int Anders_count = 0;
	int Valerie_count = 0;

	for (int i = 0; i < count; i++)
	{
		if (donation[i].Anders_donation != 0)
		{
			Anders_total += donation[i].Anders_donation;
			Anders_count++;
		}

		else if (donation[i].Valerie_donation != 0)
		{
			Valerie_total += donation[i].Valerie_donation;
			Valerie_count++;
		}
	}

	return Anders_total, Valerie_total, Anders_count, Valerie_count;
}

void AddNew(Donation donation[], int& Anders_total, int& Valerie_total, int &Anders_count, int &Valerie_count, int &count)
{
	string mystring;
	int donation_amount;
	int candidate_total;

	cout << "Candidate (Anders or Valerie): ";
	cin >> mystring;
	cout << "Donation Amount: ";
	cin >> donation_amount;
	cout << "Your name: ";
	cin >> donation[count].myName;

	donation[count].Anders_donation = 0;
	donation[count].Valerie_donation = 0;

	if (mystring == "Anders")
	{
		if (Anders_total + donation_amount <= 2700)
		{
			donation[count].Anders_donation = donation_amount;
			Anders_total += donation_amount;
			Anders_count++;

			count++;
		}

		else
		{
			cout << "You cannot exceed $2700 per election." << endl;
		}
	}

	else if (mystring == "Valerie")
	{
		if (Valerie_total + donation_amount <= 2700)
		{
			donation[count].Valerie_donation = donation_amount;
			Valerie_total += donation_amount;
			Valerie_count += 1;

			count++;
		}

		else
		{
			cout << "You cannot exceed $2700 per election." << endl;
		}
	}

	cout << endl;

}

void Report(Donation donation[], int Anders_total, int Valerie_total, int Anders_count, int Valerie_count, int count)
{
	int Anders_avg;
	int Valerie_avg;

	if (Anders_count == 0)
	{
		Anders_avg = 0;
	}

	else if (Anders_count != 0)
	{
		Anders_avg = Anders_total / Anders_count;
	}

	if (Valerie_count == 0)
	{
		Valerie_avg = 0;
	}

	else if (Valerie_count != 0)
	{
		Valerie_avg = Valerie_total / Valerie_count;
	}
	cout << "Anders:" << endl;
	cout << "             Total: $" << Anders_total << endl;
	cout << "    # of Donations:  " << Anders_count << endl;
	cout << "    Average Amount: $" << Anders_avg << endl;

	cout << "Valerie:" << endl;
	cout << "             Total: $" << Valerie_total << endl;
	cout << "    # of Donations:  " << Valerie_count << endl;
	cout << "    Average Amount: $" << Valerie_avg << endl;
	cout << endl;

}

int main()
{
	Donation donation[1000];
	int Anders_total = 0;
	int Valerie_total = 0;
	int Anders_count = 0;
	int Valerie_count = 0; 
	int count = 0;
	int choice;

	ReadFile(donation, count);


	while (true)
	{
		cout << "===========================" << endl;
		cout << "Election Contributions v1.0" << endl;
		cout << "     Anders vs. Valerie    " << endl;
		cout << "===========================" << endl;
		cout << "1- Contribute to a Compaign" << endl;
		cout << "2- Report per Candidate" << endl;
		cout << "0- Exit" << endl;

		cout << "Make a Choice: ";
		cin >> choice;


		//call the function to calculate the total amount of donation for each candidate
		Anders_total, Valerie_total, Anders_count, Valerie_count = cal_total(donation, count);

		if (choice == 1)
		{
			AddNew(donation, Anders_total, Valerie_total, Anders_count, Valerie_count, count);
		}

		else if (choice == 2)
		{
			Report(donation, Anders_total, Valerie_total, Anders_count, Valerie_count, count);
		}

		else if (choice == 0)
		{
			break;
		}
	}

	WriteFile(donation, count);


	system("PAUSE");
	return 0;
}