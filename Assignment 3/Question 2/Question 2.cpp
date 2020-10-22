//written by Eddy Zhou
#include <iostream>
#include <cstdlib>
#include <fstream> 

using namespace std;

int main()
{
    double temperature = 0, highestTemperature = 0;
    ifstream august("August_2020.txt");

    //no file found
    if (!august) {
        cout << "File not found\n";
        return EXIT_FAILURE;
    }

    //check if file pointer has a value, if true then compares value to current record temp
    while (august) {
        august >> temperature;
        if (highestTemperature < temperature) {
            highestTemperature = temperature;
        }
    }

    cout << "The highest daily temperature in August was " << highestTemperature << ".\n";
}

