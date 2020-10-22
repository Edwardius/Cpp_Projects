//Eddy Zhou

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	double number1 = 0, number2 = 0, number3 = 0, number4 = 0;
	cout << "enter four numbers one by one" << endl;
	cin >> number1 >> number2 >> number3 >> number4;
	double sum = number1 + number2 + number3 + number4;
	double mean = (sum) / 4;
	cout << "The sum of the four numbers is " << sum <<
		" and the mean of the four is " << mean << "." << endl;
	return 0;
}

/*
Test 1:

enter four numbers one by one
1
2
3
4
The sum of the four numbers is 10 and the mean of the four is 2.5.

Test 2:

enter four numbers one by one
-12 2
-999
234
The sum of the four numbers is -775 and the mean of the four is -193.75.

Test 3:

enter four numbers one by one
5342 336452199946294
2956348920 1
The sum of the four numbers is 3.36455e+14 and the mean of the four is 8.41138e+13.

Test 4:

enter four numbers one by one
-99999
99999
-12
12
The sum of the four numbers is 0 and the mean of the four is 0.

enter four numbers one by one

*/