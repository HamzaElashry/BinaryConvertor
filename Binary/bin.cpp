#include "bin.h"
#include <iostream>
#include <string>
#include <cctype>



void BINARYSTART() {
    std::string mode, bin;
    std::cout << "MODE >>> ";
    std::cin >> mode;
    if (!isValidMode(mode)) {
        std::cout << "Invalid mode. Please enter 'CHAR' or 'NUM'.\n";
        BINARYSTART();
        return;
    }
    std::cout << "\nBIN >>> ";
    std::cin >> bin;
    bin = removeLeadingZeros(bin);
    if (!isBinary(bin)) {
        std::cout << "Invalid binary number.\n";
        BINARYSTART();
        return;
    }
    int num = std::stoi(bin);
    if (mode == "NUM") {
        std::cout << binaryToDecimal(num);
    }
    else if (mode == "CHAR") {
        std::cout << binaryToChar(num);
    }
    std::cout << "\n";
    BINARYSTART();
}

int main() {
    BINARYSTART();
    return 0;
}
