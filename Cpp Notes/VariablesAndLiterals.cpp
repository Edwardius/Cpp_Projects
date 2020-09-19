// most of this is review, the concepts are similar to that of java and python

#include <iostream>
#include<cstdlib>

using namespace std;

int main()
{
	//C++ Data types include...
	int integer = 0; //limits are from -2147483648 to 2147483647
	float floating_point = 0.0; //min: 1.17549e-038 max: 3.40282e+038
	double double_floating_point = 0.0; //min: 2.22507e-308 max: 1.79769e+308
	char character; //this is one byte in size
	wchar_t wide_character; //this is two bytes in size to store more complicated characters such as arabic letters
	bool boolean = false; //one byte, true or false, true can be any value except 0, false is 0
	void; //which cannot declare variables or assign to other variables

	//C++ Type Modifiers, can modify the data types int, double , and char
	/*
	signed, by default all int are assigned a signed modifier meaning that it'll accept negative numbers
	unsigned, excludes negative numbers
	short, used for small integers range -32768 to 32767
	long, used for larger values (limits vary by computer)
	*/

	//C++ inputs and outputs
	int input_values = 0;
	cout << "this outputs strings and/or values\n";
	cin >> input_values; //can input multiple values at once, white space lets the cin input the next value into the next varaible

	//C++ type conversion

	//implicit type conversion, the computer does it for you
	/*
	High Data Types
	long double
	double
	float
	long
	int
	short
	char
	Low Data Types

	data loss from high to low
	no data loss from low to high
	*/

	//explicit type conversion, also known as casting
	double decimal = (double)input_values;

	//C++ operators
	int a = 0, b = 0;
	//ARITHMETIC OPERATORS
	a + b;
	a - b;
	a * b;
	a / b;
	a % b;
	a++;
	a--;
	++a;
	--a;
	//ASSIGNMENT OPERATORS
	a = 5;
	a += 2;
	a -= 1;
	a *= 3;
	a /= 2;
	a %= 1;
	//RELATIONAL OPERATORS
	if (a == b) {};
	if (a != b) {};
	if (a > b) {};
	if (a < b) {};
	if (a >= b) {};
	if (a <= b) {};
	//LOGICAL OPERATORS
	//&&, ||, !
	//BITWISE OPERATORS
	/*
	Bitwise & operator:
		compares integers or chars bit by bit, and returns 1 if both bits are 1 or 0 if they are not
		eg. 12 = 00001100 and 25 = 00011001, 12 & 25 = 00001000 = 8
	Bitwise | operator:
		compares int or chars bit by bit, and returns 1 if at least one of the operands contains a 1
		eg. 12 = 00001100 and 25 = 00011001, 12 & 25 = 00011101 = 29
	Bitwise ^ operator:
		compares int or chars bit by bit, and returns 1 if at least one operand is 1, but if both are 0 or both are 1, it returns a 0
		eg. 12 = 00001100 and 25 = 00011001, 12 ^ 25 = 00010101 = 21
	Bitwise ~ operator:
		changes the binary digits to the opposite value
		eg. 12 = 00001100, ~12 = 11110011
	Bitwise >> and << operators:
		shifts the binary digits one to the right or one to the left, destroying the end and adding a 0 to the start
		eg. 12 = 00001100, 12 >> 1 = 00000110 = 6
	*/
}
