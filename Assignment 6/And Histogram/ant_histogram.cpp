#include <iostream>
#include <cstdlib>
#include <fstream>

int main()
{
    std::ifstream fin("ant_observations.txt");
    if (!fin) {
        std::cout << "File not found.\n";
        return EXIT_FAILURE;
    }

    int sizeCount[7] = { 0,0,0,0,0,0,0 }, size = 0;

    while (fin >> size) {
        if (size < 3) {
            sizeCount[0] += 1;
        }
        else if (size == 3) {
            sizeCount[1] += 1;
        }
        else if (size == 4) {
            sizeCount[2] += 1;
        }
        else if (size == 5) {
            sizeCount[3] += 1;
        }
        else if (size == 6) {
            sizeCount[4] += 1;
        }
        else if (size == 7) {
            sizeCount[5] += 1;
        }
        else {
            sizeCount[6] += 1;
        }
    }

    std::cout << "AA:";
    for (int x = 0; x < sizeCount[0]; x++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    std::cout << " A:";
    for (int x = 0; x < sizeCount[1]; x++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    std::cout << " B:";
    for (int x = 0; x < sizeCount[2]; x++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    std::cout << " C:";
    for (int x = 0; x < sizeCount[3]; x++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    std::cout << " D:";
    for (int x = 0; x < sizeCount[4]; x++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    std::cout << " E:";
    for (int x = 0; x < sizeCount[5]; x++) {
        std::cout << "*";
    }
    std::cout << std::endl;
    std::cout << " G:";
    for (int x = 0; x < sizeCount[6]; x++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}
