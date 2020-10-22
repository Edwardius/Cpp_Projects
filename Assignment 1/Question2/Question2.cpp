//Eddy Zhou

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "What is the distance in nautical miles?" << endl;
    double naut = 0.0;
    cin >> naut;
    double km = naut * 1.852;
    double cable_lengths = naut / 10;
    cout << naut << " nauts is " << km << " kilometers or " << cable_lengths << " cable lengths." << endl;
    return 0;
}

/*
Outputs: 

What is the distance in nautical miles?
5
5 nauts is 9.26 kilometers or 0.5 cable lengths.
*/