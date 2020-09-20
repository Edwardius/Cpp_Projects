#include <iostream>

using namespace std;

int main()
{
    int* pointerVar;
    pointerVar = new int; //this dynamically allocates memory for an int
    *pointerVar = 88;
    delete pointerVar; //this deallocates the memory and frees up space
    //these two commands will get in handy when dealing with larger programs,
    //we dont't want C++ to create too much useless space in the computer
}

