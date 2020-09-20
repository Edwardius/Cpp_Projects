#include <iostream>
#include <cstdlib>

using namespace std;

//A structure is a collection of varaibles of different types all under one name
//similar to a class

struct Person {
    char name[50];
    int age;
    float salary;
};

void displayData(Person);
Person getData(Person);

enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday}; //enumerations is a user defined data type, its mainly used to assign names to integral constants for sake of neatness

int main()
{
    /*Person p1;
    strcpy_s(p1.name, "Bill"); //Arrays in C++ are not assignable, you have to use strcpy_s(destination, source)
    // or for inputs
    cout << "Enter name of Person\n";
    cin.get(p1.name, 50); //is used for accessing character arrays, It includes white spacve characters.
    //formatted cin.get(destination, how many characters to accept - 1)
    cout << p1.name;
    p1.age = 23;
    p1.salary = 42000;
    cout << p1.age << p1.salary;*/

    enum week day; //day can equal any of the 7 days of the week as stated in the enum
    day = Monday;
    cout << day; //both output the exact same value
    cout << Monday;

    Person p2{}; //the structure must be initialized first before it runs through various functions
    p2 = getData(p2);
    displayData(p2);

    //pointers can also be created for structures
    Person *pointer, p3;
    pointer = &p3;
    cout << "What is the person's name?\n";
    cin.get((*pointer).name, 50);
    cout << "How old is this person?\n";
    cin >> (*pointer).age;
    cout << "How much does this person make annually?\n";
    cin >> (*pointer).salary;

    return 0;
}

Person getData(Person p) {
    cout << "What is the person's name?\n";
    cin.get(p.name, 50);
    cout << "How old is this person?\n";
    cin >> p.age;
    cout << "How much does this person make annually?\n";
    cin >> p.salary;
    return (p);
}

void displayData(Person p) {
    cout << "This is " << p.name << ".\n";
    cout << "He is " << p.age << " years old.\n";
    cout << "He makes " << p.salary << " dollars a year.\n";
}