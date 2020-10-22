//Written by Eddy Zhou
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    double change = 0;
    const double SMALL_COFFEE = 0.95, REGULAR_COFFEE = 1.25, MINI_TART = 0.60, 
        CHOCOLATE = 0.75, DONUT = 1.10;

    //ask for change
    cout << "How much money does Mike have at the end of the week?\n";
    cin >> change;

    //deductions for coffee
    if (change >= REGULAR_COFFEE) {
        cout << "Mike can buy a regular coffee.\n";
        change = change - REGULAR_COFFEE;
    }
    else if (change >= SMALL_COFFEE) {
        cout << "Mike can buy a small coffee.\n";
        change = change - SMALL_COFFEE;
    }
    else {
        cout << "Mike cannot afford a coffee today. :(\n";
    }

    //deductions for candy
    if (change >= DONUT) {
        cout << "Mike can buy a donut.\n";
        change = change - DONUT;
    }
    else if (change >= CHOCOLATE) {
        cout << "Mike can buy a chocolate.\n";
        change = change - CHOCOLATE;
    }
    else if (change >= MINI_TART) {
        cout << "Mike can buy a mini tart.\n";
        change = change = MINI_TART;
    }
    else {
        cout << "Mike cannot afford a sweet today. :(\n";
    }

    return 0;
}

/*
Test Case 1:
How much money does Mike have at the end of the week?
3.35
Mike can buy a regular coffee.
Mike can buy a donut.

Test Case 2:
How much money does Mike have at the end of the week?
2.01
Mike can buy a regular coffee.
Mike can buy a chocolate.

Test Case 3:
How much money does Mike have at the end of the week?
1.88
Mike can buy a regular coffee.
Mike can buy a mini tart.

Test Case 4:
How much money does Mike have at the end of the week?
0.95
Mike can buy a small coffee.
Mike cannot afford a sweet today. :(

Test Case 5:
How much money does Mike have at the end of the week?
0.78
Mike cannot afford a coffee today. :(
Mike can buy a chocolate.

Test Case 6:
How much money does Mike have at the end of the week?
0.08
Mike cannot afford a coffee today. :(
Mike cannot afford a sweet today. :(


*/