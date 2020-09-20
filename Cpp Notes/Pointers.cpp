#include <iostream>
#include <cstdlib>

using namespace std;

//pointers are variable that store the memory addresses of other variables

int main()
{
    int* pointerA, A;
    int* pointerB, B;
    int* pointerC, C;

    A = 8, B = 76, C = -9;
    pointerA = &A; //pointer variables are stored as addresses
    pointerB = &B;
    pointerC = &C;

    cout << "Address of A: " << pointerA << endl;
    cout << "Address of B: " << pointerB << endl;
    cout << "Address of C: " << pointerC << endl;

    cout << "Specifically to A...\n";
    cout << "A = " << A << endl;
    cout << "Address of A: " << &A << endl;
    cout << "pointerA = " << pointerA << endl;
    cout << "Content of the address pointed by pointerA (*pointerA): " << *pointerA << endl << endl; //* is called the dereference operator, 
                                                                                             //it operates on the pointer amd give the value pointed by the pointer

    *pointerA = 188; //you can change the value of A using the pointer

    //Pointers and Arrays
    int* pointer;
    int manta[5];

    for (int x = 0; x < 5; x++) {
        manta[x] = rand() % 100;
    }

    pointer = manta; //this assigns every address in the array to a pointer

    /*
    pointer + 1 is the same as &manta[1];
    pointer + 2 is the same as &manta[2];
    .
    .
    .
    */

    // we can also access the elements using a single pointer
    //*pointer is the same as manta[0]
    //*(pointer + 1) is same as manta[1]

    //is you initialized the pointer = &manta[2], then
    /*
    pointer - 2 is the same as &manta[0]
    pointer -1 is the same as &manta[1]
    .
    .
    .
    */

    cout << "This is the manta array\n";
    for (int x = 0; x < 5; x++) {
        cout << manta[x] << " ";
    }
    cout << "\nThese are the addresses of its elements\n";
    for (int x = 0; x < 5; x++) {
        cout << pointer + x << " ";
    }
    cout << "\nThese are the values of its elements using *pointer\n";
    for (int x = 0; x < 5; x++) {
        cout << *(pointer + x) << " ";
    }

    return 0;
    //you can also use pointers in functions as function parameters
}

