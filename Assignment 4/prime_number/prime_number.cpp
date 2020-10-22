#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int number = 0;
	bool prime = true;
	cout << "Enter the number to check if prime: ";
	cin >> number;

	for (int x = 2; x < number; x++) {
		if (number % x == 0) {
			prime = false;
			break;
		}
	}

	cout << "\nThe number is a ";
	if (prime) {
		cout << "prime ";
	} 
	else if (!prime) {
		cout << "composite ";
	}
	cout << "number.";
	return 0;
}