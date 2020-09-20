#include <iostream>
#include <cstdlib>

#define source.h; //THIS IS REQUIRED TO INCLUDE THE CLASS IN THE MAIN SOURCE FILE

using namespace std;

class privateRoom {
private:
    double length;
    double width;
    double height;

public:
    void setData(double len, double wdt, double hgt) { //getters and setters, similar to java... ish
        length = len;
        width = wdt;
        height = hgt;
    }
    double getLength() {
        return length;
    }
    double getWidth() {
        return width;
    }
    double getHeight() {
        return height;
    }
    double calculateArea() { //these are called MEMBER FUNCTIONS
        return length * width;
    }
    double calculateVolume() {
        return length * width * height;
    }

};