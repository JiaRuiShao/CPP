#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//INPUT
	int choice;
	int rating;
	int highest_rating = 0;
	int lowest_rating = 5;
	double total = 0;
	int count = 0;

	do // make sure the main menu at least operates once
	{
		cout << "Welcome to China Border Protection" << endl;
		cout << "====== Satisfaction Survey =======" << endl;
		cout << "1- Submit Rating" << endl;
		cout << "2- View Rating" << endl;
		cout << "3- Reset Rating" << endl;
		cout << "0- Exit" << endl;

		cout << "Your choice? ";
		cin >> choice;

		//choice 1 to submit rating
		if (choice == 1)
		{
			cout << "Your rating (1-4)? "; 
			cin >> rating;
			if (rating < 1 || rating > 4)
				cout << "Invalid. You must enter a number from 1 to 4." << endl;
			else
			{
				cout << "Your rating is recorded." << endl;
				total += rating;
				count++;

				if (rating >= highest_rating)
					highest_rating = rating;

				if (rating <= lowest_rating)
					lowest_rating = rating;
			}
		}
		
		//choice 2 to view rating
		if (choice == 2)
		{
			if (total == 0)//Or "count == 0" (there's no rating in record)
				cout << "There are no rating for this officer yet." << endl;
			else
			{
				cout << "Highest Rating: " << highest_rating << endl;
				cout << "Lowest Rating: " << lowest_rating << endl;
				cout << "Average Rating: " << total / count << endl;
			}
		}

		//choice 3 to reset rating
		if (choice == 3)
		{
			total = 0;
			count = 0;
			highest_rating = 0;
			lowest_rating = 5;
			cout << "The ratings for this officer is reset." << endl;
		}

		// If the user put the number other than 1,2,3
		/*
		if (choice != 1 || choice != 2 || choice != 3)
			cout << "Error." << endl;
		NOT WORKING!!!	
		*/

	} while (choice != 0);

	system ("pause");
	return 0;
}