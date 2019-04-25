#include <iostream>

using namespace std;

int main()
{
	cout << "Enter Length: ";
	int length; 
	cin >> length;
	
	cout << "Enter Width: ";
	int width; 
	cin >> width; 
	
	int area; 
	area = length * width;

	cout << "The area is " << area << endl;

	system("PAUSE");
	return 0;
}