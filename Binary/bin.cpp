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
    bin = removeLeadingZeros(bin);
    if (!isBinary(bin)) {
        std::cout << "Invalid binary number.\n";
        BINARYSTART();
        return;
    }
    if (mode == "NUM") {
        std::cout << "\nBIN >>> ";
        std::cin >> bin;
        int num = std::stoi(bin);
        std::cout << binaryToDecimal(num);
    }
    else if (mode == "CHAR") {
        std::cout << "\nBIN >>> ";
        std::cin >> bin;
        int num = std::stoi(bin);
        std::cout << binaryToChar(num);
    }
    else if (mode == "CLEAR")
    {
        system("""cls""");
        BINARYSTART();
    }
    std::cout << "\n";
    BINARYSTART();
}

int main() {
    BINARYSTART();
    return 0;
}
