//Written by Eddy Zhou

#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    ifstream covid("covid.txt");

    if (!covid) {
        cout << "File not found\n";
        return EXIT_FAILURE;
    }

    const int SIZE = 36;
    const int NUMBER_OF_PEOPLE = 6;

    string namesAndItems[SIZE]; //stores the names of the people and the names of the items they use
    double numbersAndCost[SIZE] = { 0 }; //stores the number of items they use and the expenses of each item
    double expenses = 0, highestExpenses = 0;
    int nameAddress = 0, topSpenderAddress = 0;

    for (int x = 0; x < SIZE; x++) { //copies file into parallel arrays
        covid >> namesAndItems[x] >> numbersAndCost[x];
    }

    int counter = 0; //used to traverse the numbersAndCost array

    do {
        expenses = 0;
        nameAddress = counter;
        counter++;
        int numberOfExpenses = numbersAndCost[nameAddress];
        for (int y = 0; y < numberOfExpenses; y++) {
            expenses = expenses + numbersAndCost[counter];
            counter++;
        }
        if (highestExpenses < expenses) {
            highestExpenses = expenses;
            topSpenderAddress = nameAddress;
        }
    } while (counter < SIZE);

    cout << namesAndItems[topSpenderAddress] << " spent the most covid money at $" << highestExpenses << ".\n";
}

/*
Output:
Daniel spent the most covid money at $2131.7.
*/