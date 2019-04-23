#include <iostream>
#include <fstream>

using namespace std;

//Prototype
void read_from_file(int age[], int loan_amount[], int credit_score[], int &count);
void print_average(int age[], int loan_amount[], int credit_score[], int count);
void high_risk(int age[], int loan_amount[], int credit_score[], int count);
void simulate_loan(int age[], int loan_amount[], int credit_score[], int count);

//Main function
int main()
{
	int choice;
	int age[1000];
	int loan_amount[1000];
	int credit_score[1000];
	int count = 0;

	//feature 0 | Read from file
	read_from_file(age, loan_amount, credit_score, count);

	//Main Menu
	do
	{
		cout << "Mortgage Aduit v.2.0" << endl;
		cout << "====================" << endl;
		cout << "1- Summary Report" << endl;
		cout << "2- High Risk Loans" << endl;
		cout << "3- Simulate Loan" << endl;
		cout << "0- Exit" << endl;

		cout << "What is your choice? ";
		cin >> choice;

		//chooose 1 | Summary Report
		if (choice == 1)
		{
			print_average(age, loan_amount, credit_score, count);
		}

		//chooose 2 | High Risk Loans
		if (choice == 2)
		{
			high_risk(age, loan_amount, credit_score, count);
		}

		//chooose 3 | Simulate Loan
		if (choice == 3)
		{
			simulate_loan(age, loan_amount, credit_score, count);
		}


	} while (choice != 0);


	system("pause");
	return 0;
}

//feature #0
void read_from_file(int age[], int loan_amount[], int credit_score[], int &count)
{
	//check whether the file exist or not
	fstream check_file;
	check_file.open("mortgage.txt");

	if (check_file.fail())
	{
		cout << "There's no file exist." << endl;
	}

	else
	{
		//read from file
		ifstream file("mortgage.txt");
		
		while (!file.eof())
		{
			file >> age[count];
			file >> loan_amount[count];
			file >> credit_score[count];
			count++;
		}

		file.close();
	}
}

//Feature #1
void print_average(int age[], int loan_amount[], int credit_score[], int count)
{
	int total_age = 0;
	int total_loan = 0;
	int total_credit = 0;

	for (int i = 0; i < count; i++)
	{
		total_age += age[i];
		total_loan += loan_amount[i];
		total_credit += credit_score[i];
	}

	cout << "Average age: " << total_age/count << endl;
	cout << "Average loan: " << total_loan / count << endl;
	cout << "Average credit: " << total_credit / count << endl;

}

// Feature #2
void high_risk(int age[], int loan_amount[], int credit_score[], int count)
{
	int sum_loan = 0;
	int high_risk_total = 0;

	for (int i = 0; i < count; i++)
	{
		int risk_factor = loan_amount[i] / credit_score[i];

		if (age[i] < 30)
		{
			risk_factor *= 1.4;
		}

		else if (age[i] < 50)
		{
			risk_factor *= 1.2;
		}
		/* don't need this cause multiply by 1 does not change the final value
		
		else if (age[i] < 50)
		{
			age_factor = 1.0;
		}
		*/

		//The loan is high risk
		if (risk_factor > 100000)
		{
			high_risk_total++;
			sum_loan += loan_amount[i];
		}
	}

	cout << "Found " << high_risk_total << " high risk loans." << endl;
	cout << "Total amount of high risk loan is $" << sum_loan << "." << endl;
}

// Feature #3
void simulate_loan(int age[], int loan_amount[], int credit_score[], int count)
{
	int myage;
	int mycredit;
	int total_loan = 0;
	int loan_count = 0;

	cout << "What is your age: ";
	cin >> myage;
	cout << "What is your credit (1-8): ";
	cin >> mycredit;

	for (int i = 0; i < count; i++)
	{
		if (age[i] >= myage - 5 && age[i] <= myage + 5 && mycredit == credit_score[i])
		{
			loan_count++;
			total_loan += loan_amount[i];
		}
	}

	if (loan_count != 0)
	{
		cout << "The likely loan amount the user could qualify is $" << total_loan / loan_count << "." << endl;
	}

	else
	{
		cout << "Sorry we cannot estimate a loan amount for you." << endl;
	}
}