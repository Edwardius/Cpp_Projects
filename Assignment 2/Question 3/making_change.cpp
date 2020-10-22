//Written by Eddy Zhou
#include <iostream>

using namespace std;

int main()
{
    int dollars = 0, cents = 0, minCoins = 0;
    const int TOONIE = 2, LOONIE = 1, QUARTER = 25, DIME = 10, NICKEL = 5; 
    //Quarters, Dimes, and Nickels are whole numbers for ease of calculations

    cout << "Enter the number of dollars:\n";
    cin >> dollars;
    cout << "Enter the amount of cents:\n";
    cin >> cents;

    const int MULTIPLE = 5;
    if (cents % 5 < 3 && cents != 5) {
        cents = (cents / MULTIPLE) * MULTIPLE;
    }
    else {
        cents = ((cents + MULTIPLE) / MULTIPLE) * MULTIPLE;
    }
    if (cents == 100) {
        cents -= 100;
        dollars++;
    }

    //to deal with dollars
    minCoins += dollars / TOONIE;
    minCoins += dollars % TOONIE;

    //to deal with cents
    minCoins += cents / QUARTER;
    cents = cents % QUARTER;
    minCoins += cents / DIME;
    cents = cents % DIME;
    minCoins += cents / NICKEL;

    cout << "The minimum number of coins is:\n";
    cout << minCoins;
}

