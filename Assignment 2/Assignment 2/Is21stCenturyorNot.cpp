// Written by EDDY ZHOU

#include <iostream>

using namespace std;

int main()
{
	int year = 0;
	const int CENTURY_LOWER_BOUNDRY = 2000; 
	const int CENTURY_UPPER_BOUNDRY = 2100;

	cout << "Enter a year.\n";
	cin >> year;

	if (year < CENTURY_LOWER_BOUNDRY) {
		cout << year << " is old, before the 21st century.\n";
	}
	else if (year >= CENTURY_LOWER_BOUNDRY && year < CENTURY_UPPER_BOUNDRY) {
		cout << year << " is in the 21st century.\n";
	}
	else {
		cout << year << " is beyond the 21st century.\n";
	}

	return 0;
}

/*
Sample 1:
Enter a year.
1980
1980 is old, before the 21st century.

Sample 2:
Enter a year.
2102
2102 is beyond the 21st century.
*/