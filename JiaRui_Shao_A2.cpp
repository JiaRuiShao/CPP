#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
/*
- Monthly Income (income)

- Total Debt (debt)

- Monthly minimum payments for the debt (minPay)

If total debt is more than 6 months monthly income of the applicant (income*6), we cannot grant any loan. Inform user that no loan can be granted.

Otherwise, you subtract the minimum monthly debt payment from monthly income. We can allow up to 30% of that amount as loan.

credit = (income - minPay) * 0.3

Let user know that the applicant can be approved for upto this (credit) amount.
*/

	//input
	int income;
	cout << "Enter monthly income: ";
	cin >> income;

	int debt;
	cout << "Enter total debt: ";
	cin >> debt;

	int minPay;
	cout << "Enter Monthly minimum payments for the debt: ";
	cin >> minPay;

	//calculation
	int credit;
	credit = (income - minPay) * 0.3;

	//output
	if (debt > income * 6)
		cout << "We cannot grant any loan." << endl;
	else if (debt <= income * 6)
		cout << "We can grant "  << credit << " loan." << endl;

	system("pause");
	return 0;

}