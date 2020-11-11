//Written By Eddy Zhou
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include "sort_ascending.h"

const int NUM_MONTHS = 12; 
const int MAX_DAYS = 31; 
void read_temps(std::ifstream& fin, double temp_data[NUM_MONTHS][MAX_DAYS]);
double median_temp(double temp_data[NUM_MONTHS][MAX_DAYS], int month_to_report);

int main()
{
    std::ifstream fin("temperature.txt"), rin("report_months.txt");
    if (!fin || !rin) {
        std::cout << "One of the Files is not Found.\n";
        return EXIT_FAILURE;
    }

    double temp_data[NUM_MONTHS][MAX_DAYS];
    int month_to_report = 0;

    for (int x = 0; x < 12; x++) {
        for (int y = 0; y < 31; y++) {
            temp_data[x][y] = 9999;
        }
    }
    read_temps(fin, temp_data);
    
    std::cout << "Median temperatures report:\n";
    while (rin >> month_to_report) {
        month_to_report--;
        std::cout << median_temp(temp_data, month_to_report) << std::endl;
    }
}

void read_temps(std::ifstream& fin, double temp_data[NUM_MONTHS][MAX_DAYS]) {
    int year = 0, month = 0, day = 0;
    double temperature = 0;
    std::string y, m, d, t;
    fin >> y >> m >> d >> t;
    while (fin >> year >> month >> day >> temperature) {
        month--;
        day--;
        temp_data[month][day] = temperature;
    }
}

double median_temp(double temp_data[NUM_MONTHS][MAX_DAYS], int month_to_report) {
    double month[MAX_DAYS] = { 0 }, median = 0;
    int counter = 0, medianAddress = 0;
    for (int x = 0; x < MAX_DAYS; x++) {
        if (temp_data[month_to_report][x] != 9999 && temp_data[month_to_report][x] != -9999.9) {
            month[counter] = temp_data[month_to_report][x];
            counter++;
        }
    }
    /*for (int x = 0; x < counter; x++) {
        std::cout << month[x] << " ";
    }
    std::cout << std::endl;
    std::cout << counter << std::endl;*/
    sort_ascending(month, counter);
    /*for (int x = 0; x < counter; x++) {
        std::cout << month[x] << " ";
    }
    std::cout << std::endl;
    std::cout << counter << std::endl;*/
    medianAddress = counter / 2;
    if (counter % 2 == 0) {
        median = (month[medianAddress] + month[medianAddress - 1]) / 2;
    }
    else {
        median = month[medianAddress];
    }
    return median;
}