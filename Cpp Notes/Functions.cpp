#include <iostream>
//C++ library functions, these are functions that are built into C++
#include <cstdlib>
#include <cmath> //this includes new functions like abs(), sqrt(), isdigit(), etc.

using namespace std;

//strorage class
/*
THERE ARE FIVE MAJOR STORAGE CLASS TYPES:
- Local variable: a variable defined in a function
- Global variable: a variable defined outside all functions
- Static local variable: a variable within a function that persists in value until the end of the program
- Register Variable: removed, no use
- Thread Local Storage: when you want a globally visible object while having its data only accesible to its calling thread
*/

int global_integer;

int& test();

//a function is a block of code that performs a specific task, dividing a complex 
    //problem into smaller chunks makes it easier to understand and reusable

//User-defined Function
/*
returnType functionName (parameter1, parameter2, ...) {
    function body
}
*/
void greet(int num1) {
    cout << "Hello World!\n";
    cout << num1 << endl;
}

double average(int num1, int num2, int num3) {
    double average = ((double)num1 + num2 + num3) / 3;
    return(average);
}

//function prototype
int prototype(int, int); //this is if a function is defined AFTER the main

//overloaded functions, these are functions of the same name but different type or parameters
int absolute(int a) {
    if (a < 0) {
        a = -a;
    }
    return(a);
}
double absolute(double a) {
    if (a < 0.0) {
        a = -a;
    }
    return(a);
}
//many standard library functions are overloaded to account for all parameters

//default arguments are default values for function parameters
void temp(int = 10, int = 3); //all subsequent parameters must also have default values

int main() {
    int x = 0, a = 1, b = 2, c = 4, d = -9;
    double e = -0.9;
    greet(x);
    cout << average(a, b, c) << endl;
    cout << prototype(x, a) << endl;
    cout << "absolute value of " << d << " is " << absolute(d) << endl;
    cout << "absolute value of " << e << " is " << absolute(e) << endl;
    cout << "inside the temp the values are...\n";
    temp(b);
    global_integer = 11;
    test() = 10; //assigns the global integer the value 10
    cout << global_integer;
    return 0;
}

int prototype(int a, int b) {
    return(a + b);
}

void temp(int a, int b) {
    cout << a << endl << b << endl;
}

int& test() {
    return global_integer;
}

//Note on recursion; its a function that calls on itself, has its downsides and upsides but its very useful :)