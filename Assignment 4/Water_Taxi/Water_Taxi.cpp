#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ifstream taxi("taxi1_V2.txt");

    if (!taxi) {
        cout << "File not found\n";
        return EXIT_FAILURE;
    }

    const int TOTAL_TRIPS = 78;
    double longestTrip = 0, lowestCost = 999999, cumulativeDistance = 0, cumulativeCost = 0;
    cout << setw(12) << "Trip" << setw(12) << "Return" << setw(12) << "Stops" << setw(12) << "Distance" 
        << setw(12) << "Cost" << setw(12) << "Cumulative" << setw(13) << "Cumulative\n";
    cout << setw(72) << "Distance" << setw(13) <<" Cost\n";

    for (int x = 1; x <= TOTAL_TRIPS; x++) {
        //return
        int Return = 0;
        taxi >> Return;

        //stops
        int Stops = 0;
        taxi >> Stops;

        //distance
        double distance = 0, distanceBetweenStops = 0;
        double twoCoordinates[4] = {0,0,0,0};
        for (int y = 0; y < Stops; y++) {
            taxi >> twoCoordinates[2] >> twoCoordinates[3];
            distanceBetweenStops = sqrt(pow(twoCoordinates[2] - twoCoordinates[0], 2) +
                pow(twoCoordinates[3] - twoCoordinates[1], 2));
            distance = distance + distanceBetweenStops;
            twoCoordinates[0] = twoCoordinates[2];
            twoCoordinates[1] = twoCoordinates[3];
            distanceBetweenStops = 0;
        }
        if (Return == 1) {
            twoCoordinates[2] = 0;
            twoCoordinates[3] = 0;
            distanceBetweenStops = sqrt(pow(twoCoordinates[2] - twoCoordinates[0], 2) +
                pow(twoCoordinates[3] - twoCoordinates[1], 2));
            distance = distance + distanceBetweenStops;
        }

        //longest distance travelled
        if (longestTrip < distance) {
            longestTrip = distance;
        }

        //cost
        double cost = 0;
        cost = Stops * 12.00 + distance * 2.30;

        //lowest cost
        if (lowestCost > cost) {
            lowestCost = cost;
        }

        //cumulative distance
        cumulativeDistance = cumulativeDistance + distance;

        //cumulative cost
        cumulativeCost = cumulativeCost + cost;

        //output
        if (x <= 5 || (x - 5) % 10 == 0) {
            cout << setw(12) << x << setw(12) << Return << setw(12) << Stops << setw(12) << fixed
                << setprecision(2) << distance << setw(12) << fixed << setprecision(2)
                << cost << fixed << setw(12) << setprecision(2) << cumulativeDistance << setw(12) << fixed
                << setprecision(2) << cumulativeCost << "\n";
        }
    }

    cout << "Cumulative distance travelled for all August: " << fixed << setprecision(2) << cumulativeDistance << "km\n";
    cout << "Cumulative cost collected from all customers for all of August: $" << fixed << setprecision(2) << cumulativeCost << endl;
    cout << "Length of the Longest Trip: " << longestTrip << "km\n";
    cout << "Least Expensive Trip: $" << lowestCost << endl;
    return 0;
}

/*
Output:
        Trip      Return       Stops    Distance        Cost  Cumulative  Cumulative
                                                                Distance        Cost
           1           0           1       10.20       35.46       10.20       35.46
           2           1           2       12.00       51.60       22.20       87.06
           3           0           4       32.84      123.54       55.04      210.60
           4           0           3       21.03       84.37       76.07      294.97
           5           0           5       29.52      127.90      105.60      422.87
          15           0           3       25.47       94.58      367.51     1457.27
          25           1           3       23.86       90.87      666.70     2553.42
          35           0           1       10.08       35.18      903.61     3458.30
          45           0           4       32.49      122.73     1132.05     4307.72
          55           0           4       32.04      121.69     1381.13     5240.60
          65           0           2       10.03       47.07     1583.23     6017.42
          75           1           3       27.04       98.18     1817.06     6855.24
Cumulative distance travelled for all August: 1871.38km
Cumulative cost collected from all customers for all of August: $7052.17
Length of the Longest Trip: 51.39km
Least Expensive Trip: $22.59
*/
