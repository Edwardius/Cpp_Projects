//Written By Eddy Zhou
#include <iostream>
#include <cstdlib>

int main() 
{
	int milTime = 0, timeMinutes = 0;
	const int MINUTES_IN_HOUR = 60, HOUR_BOUNDARY = 100, TIME_BOUNDARY = 2359;

	std::cout << "Enter a time in military time format: ";
	std::cin >> milTime;

	//opt error checker
	while (milTime % HOUR_BOUNDARY > MINUTES_IN_HOUR || milTime > TIME_BOUNDARY) {
		std::cout << "Invalid military time format. Please try again: ";
		std::cin >> milTime;
	}

	timeMinutes = (milTime / HOUR_BOUNDARY) * MINUTES_IN_HOUR + milTime % HOUR_BOUNDARY;

	std::cout << timeMinutes << " minutes have elapsed since time 00:00.\n";
}
/*
Sample Output:

Enter a time in military time format: 230
150 minutes have elapsed since time 00:00.

Enter a time in military time format: 0000
0 minutes have elapsed since time 00:00.

Enter a time in military time format: 0059
59 minutes have elapsed since time 00:00.

Enter a time in military time format: 1350
830 minutes have elapsed since time 00:00.

Enter a time in military time format: 1270
Invalid military time format. Please try again: 1259
779 minutes have elapsed since time 00:00.

Enter a time in military time format: 2401
Invalid military time format. Please try again: 2359
1439 minutes have elapsed since time 00:00.

*/