#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>


bool is_leap_year(int year) {
	if (year % 4 == 0 && year % 100 != 0) {
		return true;
	}
	else if (year % 400 == 0) {
		return true;
	}
	else {
		return false;
	}
}

/*int main()
{
	std::cout << is_leap_year(2000) << std::endl;
	std::cout << is_leap_year(1700) << std::endl;
	std::cout << is_leap_year(1800) << std::endl;
	std::cout << is_leap_year(1900) << std::endl;
	std::cout << is_leap_year(1600) << std::endl;
}*/
