#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    double budget = 0, duration = 0;

    cout << "Enter the daily budget ($): ";
    cin >> budget;
    cout << "Enter the vacation duration (days): ";
    cin >> duration;
    cout << "David's Travel Destination is: ";

    if (budget < 100) {
        cout << "staycation\n";
    }
    else if (budget <= 250 && duration <= 7) {
        cout << "Toronto\n";
    }
    else if (budget <= 250 && duration > 7) {
        cout << "Vancouver\n";
    }
    else if (duration <= 7) {
        cout << "New York City\n";
    }
    else {
        cout << "Hong Kong\n";
    }

    return 0;
}
