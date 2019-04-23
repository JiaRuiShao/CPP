#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Donation
{
    public:

		string Candidate;
		string Donor;
		double Amount;

};


int main()
{
	Donation donations[1000];
	int dcount = 0;
	int choice;

	while (true)
	{
		cout << "====================" << endl;
		cout << "Contribution Manager" << endl;
		cout << " Anders vs. Valerie " << endl;
		cout << "====================" << endl;
		cout << "1- Contribute to a Compaign" << endl;
		cout << "2- Report per Candidate" << endl;
		cout << "0- Exit" << endl;

		cout << "Make a Choice: ";
		cin >> choice;


		if (choice == 1)
		{
			Donate(donations, dcount);
		}

		else if (choice == 2)
		{
			double Anders_total = 0;
			double Anders_count = 0;
			double Valerie_total = 0;
			double Valerie_count = 0;
			double Anders_avg;
			double Valerie_avg;

			for (int i = 0; i < dcount; i++)
			{
				if (donations[i].Donor == "Anders")
				{
					Anders_total += donations[i].Amount;
				}
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

		else if (choice == 0)
		{
			break;
		}
	}

	system("PAUSE");
	return 0;
}

void Donate(Donation donations[], int &dcount)
{
	string cand;
	cout << "Candidate: ";
	cin >> cand;

	double amount;
	cout << "Amount: ";
	cin >> amount;

	string donor;
	cout << "Donor: ";
	cin >> donor;

	//check whether this candidate has more than $2700 donation or not
	double contrSoFar = 0;
	for (int i = 0; i < dcount; i++)
	{
		if (donations[i].Donor == donor)
		{
			contrSoFar += donations[i].Amount;
		}
	}

	if (contrSoFar + amount > 2700)
	{
		cout << "U cannot accept this donation since it's ober 2700." << endl;
	}

	else
	{
		donations[dcount].Donor = donor;
		donations[dcount].Amount = amount;
		donations[dcount].Candidate = cand;
	}
}