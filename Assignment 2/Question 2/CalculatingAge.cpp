// Written by Eddy Zhou
#include <iostream>

using namespace std;

int main()
{
    int b_year = 0, b_month = 0, b_day = 0;
    int c_year = 0, c_month = 0, c_day = 0;
    int age = 0;

    cout << "Birthday: ";
    cin >> b_year >> b_month >> b_day;
    cout << "Current Date: ";
    cin >> c_year >> c_month >> c_day;

    int b_totalDays = b_year * 365 + b_month * 30 + b_day;
    int c_totalDays = c_year * 365 + c_month * 30 + c_day; 
    //note: the total number of days since the year 0
    // will have an error margin of max 5 days but this doesn't matter

    if (b_totalDays >= c_totalDays) {
        cout << "You are not born yet!\n";
    }
    else {
        age = (c_totalDays - b_totalDays) / 365;
        cout << "Age: " << age;
    }
}
 
/*
Sample 1:
Birthday: 2002 07 08
Current Date: 2020 09 15
Age: 18

Sample 2:
Birthday: 2050 06 23
Current Date: 2020 12 15
You are not born yet!

Sample 3:
Birthday: 1999 09 17
Current Date: 1999 09 18
Age: 0

Sample 4:
Birthday: 2050 09 23
Current Date: 2050 09 22
You are not born yet!

NOTE: for sample 3, the program will not output your age in days, but the fact
that there is an age output means that the user was for sure born before the current date given
*/

