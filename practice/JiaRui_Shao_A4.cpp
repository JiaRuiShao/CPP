/*
Good news!! You won the grant price just for being awesome!! However, as in many things in life, there is a catch. 
Your prize will be paid to you in monthly installments.

The payments will start in the amount of 1 dollar. Obviously that is not too much of a price at the beginning. 
But here are two rules we can apply every month to increase the installments.

Rule A - Double the installment amount.
Rule B - Triple the installment amount.
You are free to apply Rule A every month, but Rule B can be applied only every other month.

To maximize payments.
1st month's payment 1   dollar.
2nd month's payment 2   dollars. (doubled the amount)
3rd month's payment 6   dollars. (triple it every other months)
4th month's payment 12  dollars. (double the amount)
5th month's payment 36  dollars. (triple it every other month)
6th month's payment 72  dollars. (double the amount)
7th month's payment 216 dollars. (triple it every other month)
and so on ...

Write a program that will compute the monthly payment amounts you will get over a given number of months.
Your program should take the number of months from user and create a loop to compute the payments for each month and output on screen.
*/

#include <iostream> // 
#include <fstream>  // 
#include <string>	// 

using namespace std;

int main()
{
	//INPUT
	int month_num;
	int payment = 0;

	cout << "How many months: ";
	cin >> month_num;

	//CACULATION
	for (int i = 1; i <= month_num; i++)
	{
		if (i < 2)
		{
			payment = 1;
			cout << "Month 1 : " << payment << endl;
		}
			
		else
		{
			if (i % 2 == 0)
			{
				payment *= 2;
				cout << "Month" << i << " : " << payment << endl;
			}
				
			else
			{
				payment *= 3;
				cout << "Month" << i << " : " << payment << endl;
			}
		}
	}

	system("PAUSE");
	return 0;
}