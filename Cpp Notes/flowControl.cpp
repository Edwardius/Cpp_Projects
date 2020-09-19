#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    //if, else if, else statements
    int number;

    cout << "Enter an number: ";
    cin >> number;
    if (number > 0) { //can only use one if statement
        cout << "You entered a positive number: " << number << endl;
    }
    else if (number < 0) { //can use multiple else if statements
        cout << "You entered a negative number: " << number << endl;
    }
    else { //can only have one else statement
        cout << "You entered 0." << endl;
    }
 
    //loops
    for (int x = 0; x < 100; x++) { // for(initialization; condition; update)
        cout << x;
    }
    int manta[] = { 0, 1, 2, 3, 4, 5, 6, 10, 7, 8 }; // for(variable : collection), used for arrays and vectors
    for (int x: manta) {
        x = 1; //this changes the value of manta[x] too!
        cout << x << " ";
        cout << manta[x] << " ";
    }
    for (int x = 0; x > 0; x++) {
        //this will run forever
    }
    while (1 == 1) {
        //this will run forever, you can change the conditions of this to whatever you want
    }
    int x = 1;
    do {
        //this will last forever until x != 1, conditions can be changed
    } while (x == 1);

    //break
    for (int i = 1; i <= 5; i++) {
        // break condition     
        if (i == 3) {
            break; //breaks out of the loop
        }
        cout << i << endl;
    }
    //breaks in nested loops will only break the internal loop

    //continue
    for (int i = 1; i <= 5; i++) {
        // condition to continue
        if (i == 3) {
            continue; //skips the current iteration and goes to the next
        }
        //more code here will be ignored if the continue command is fulfilled
        cout << i << endl;
    }

    //switch case statements
    char oper;
    float num1, num2;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> oper;
    cout << "Enter two numbers: " << endl;
    cin >> num1 >> num2;

    switch (oper) { //switch (expression), this is the variable/expression in which the switch will analyze
    case '+': //the cases are the results of the switch's analyzing
        cout << num1 << " + " << num2 << " = " << num1 + num2;
        break;
    case '-':
        cout << num1 << " - " << num2 << " = " << num1 - num2;
        break;
    case '*':
        cout << num1 << " * " << num2 << " = " << num1 * num2;
        break;
    case '/':
        cout << num1 << " / " << num2 << " = " << num1 / num2;
        break;
    default: // operator is doesn't match any case constant (+, -, *, /)
        cout << "Error! The operator is not correct";
        break;
    }

    //goto statements
    int i = 0;
    for (int i = 1; i <= 5; i++) {
        if (i == 3) {
            goto jump;
        }
        cout << i << endl;
    }
jump: //this can get confusing really quick, avoid using
    cout << i;
}

