#include <iostream>
#include <string>
#include "customArr.h"   
#include "functions.h"   

using namespace std;

// Function to get an integer input within a valid range (1 to range)
int getInput(int range) {
    int input;
    while (true) {
        cout << "Enter an integer (1 to " << range << "): ";
        cin >> input;

        if (cin.fail() || input > range || input <= 0) {
            cout << "Invalid input. Please enter an integer between 1 and " << range << "." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else {
            return input;
        }
    }
}

void printArray(const customArr<int>& arr) {
    std::cout << "Array contents:\n";
    for (size_t i = 0; i < arr.getSize(); ++i) {
        std::cout << arr.get(static_cast<int>(i)) << " ";
        if ((i + 1) % 10 == 0) {
            std::cout << std::endl;
        }
    }

    if (arr.getSize() % 10 != 0) {
        std::cout << std::endl;
    }
}
