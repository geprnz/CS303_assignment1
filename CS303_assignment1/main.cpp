// GUNNER PACE - CS303
#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

int main() {
    std::string fname;
    while (true) {
        std::cout << "Enter file name: ";
        std::cin >> fname;
        std::ifstream file(fname);
        if (!file.is_open()) {
            std::cout << "Unable to open file: " << fname << std::endl;
        }
        else {
            break;
        }
    }

    // Assume int only
    customArr<int> arr = import<int>(fname);

    while (true) {
        std::cout << MENU << std::endl;
        int input = getInput(6); 

        switch (input) {
        case 1: { // Find value
            std::cout << "Enter value to find: ";
            int val;
            std::cin >> val;
            int idx = arr.search(val);
            if (idx != -1)
                std::cout << "Value found at index: " << idx << std::endl;
            else
                std::cout << "Value not found\n";
            break;
        }
        case 2: { // Modify value
            std::cout << "Enter index to replace: ";
            int idx;
            std::cin >> idx;
            std::cout << "Enter new value: ";
            int newVal;
            std::cin >> newVal;
            try {
                auto replaced = arr.replace(idx, newVal);
                std::cout << "Replaced " << replaced.first << " with " << replaced.second << std::endl;
            }
            catch (std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 3: { // Append value
            std::cout << "Enter value to append: ";
            int val;
            std::cin >> val;
            arr.append(val);
            std::cout << "Value appended.\n";
            break;
        }
        case 4: { // Remove value
            std::cout << "Enter index to remove: ";
            int idx;
            std::cin >> idx;
            try {
                int removed = arr.remove(idx);
                std::cout << "Removed value: " << removed << std::endl;
            }
            catch (std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        }
        case 5: { // Print array
            printArray(arr);
            break;
        }
        case 6:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}

