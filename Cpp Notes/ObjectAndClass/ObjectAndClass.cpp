#include <iostream>
#include <cstdlib>
#include "Source.h" //THIS INCLUDES CLASSES AND FUNCTIONS FROM OTHER SOURCE FILES

using namespace std;

//Sometimes its desirable to put related functions and data in one place so that it's logical and easier to work with
//We can do this by placing these functions and data in a single place known as objects
//hence the term object-oriented programming!

//C++ Class: a blueprint for the object
class Room {
public:
    double length; //these are called DATA MEMBERS
    double breadth;
    double height; 

    double calculateArea() { //these are called MEMBER FUNCTIONS
        return length * breadth;
    }
    double calculateVolume() {
        return length * breadth * height;
    }
};

class Wall { //Constructors are a special type of member function that runs whenever the class is called
private:
    double length;
    double width;
public: //these are examples of operator overloading
    Wall() { //this is just a constructor, no parameters whatsoever
        length = 5.5;
        width = 6.5;

        cout << "Created a wall.\n Area is: " << length * width;
    }
    Wall(double len, double wid) { //this is a parameterized constructor, this creates a wall following the parameters
        length = len;
        width = wid;

        cout << "Created a wall.\n Area is: " << length * width;
    }
    Wall(Wall &obj) { //this is a copy constructor, self explanatory
        length = obj.length; //no getter needed, guess classes have access to one another
        width = obj.width;

        cout << "Created a wall.\n Area is: " << length * width;
    }
};

void sampleFunction() { //you can make classes in any function
    Room room3, room4;
}

int main()
{
    Room room1, room2;

    room1.length = 88.6;
    room1.breadth = 12.3;
    room1.height = 19.3;

    cout << room1.calculateArea(); //we can access data members and data functions using dot operator
    cout<< room1.length;

    privateRoom proom1;

    proom1.setData(12.3, 34.8, 88.9);

    Wall wall1;
    Wall wall2(12.3, 88.8);

    //you can place objects into functions and stuff :))
}

