/*
 Eddy Zhou
 
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    int side_length = 0;
    cout << "What is the side length?" << endl;
    cin >> side_length;

    cout << "The square of " << side_length << " is " << side_length*side_length << endl;
    cout << "& the cube of " << side_length << " is " << side_length*side_length*side_length << endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

/*
Paste output here:

What is the side length?
2
The square of 2 is 4
& the cube of 2 is 8
*/
