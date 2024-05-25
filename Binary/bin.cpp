#include "bin.h"
#include <iostream>
#include <string>
#include <cctype>
#include <bitset>


void BINARYSTART() {
    std::string mode, bin;
    std::cout << "COMMAND >>> ";
    std::cin >> mode;
    mode = removeLeadingSpaces(mode);
    if (!isValidMode(mode)) {
        std::cout << "?\n";
        BINARYSTART();
        return;
    }
    if (mode == "NUM" || mode == "num" || mode == "Num" || mode == "NUMBER" || mode == "Number" || mode == "number" || mode == "decimal" || mode == "Decimal") {
        std::cout << "\nBIN >>> ";
        std::cin >> bin;
        bin = removeLeadingSpaces(bin);
        bin = removeLeadingZeros(bin);
        if (!isBinary(bin)) {
            std::cout << "?\n";
            BINARYSTART();
            return;
        }
        else
        {
            int num = std::stoi(bin);
            std::cout << binaryToDecimal(num) << "\n";
            BINARYSTART();
        }
    }
    else if (mode == "CHAR" || mode == "char" || mode == "Char" || mode == "letter" || mode == "Letter" || mode == "LETTER" || mode == "character" || mode == "Character" || mode == "CHARACTER") {
        std::cout << "\nBIN >>> ";
        std::cin >> bin;
        bin = removeLeadingSpaces(bin);
        bin = removeLeadingZeros(bin);
        if (!isBinary(bin)) {
            std::cout << "?\n";
            BINARYSTART();
            return;
        }
        else
        {
            int num = std::stoi(bin);
            std::cout << binaryToChar(num);
            std::cout << "\n";
            BINARYSTART();
        }
    }
    else if (mode == "CLEAR" || mode == "clear" || mode == "Clear")
    {
        system("""cls""");
        BINARYSTART();
    }
    else if (mode == "EXIT" || mode == "exit" || mode == "Exit")
    {
        std::string confirm;
        std::cout << "Write \"CONFIRM\" to confirm and exit:\n>>>  ";
        std::cin >> confirm;
        confirm = removeLeadingSpaces(confirm);
        if (confirm == "CONFIRM")
        {
            std::exit(0);
        }
        else { BINARYSTART(); }
    }
    else if (mode == "help" || mode == "Help")
    {
        std::cout << "Number : Binary to decimal.\nChar : Binary to letter.\nExit : End the program.\nClear : Clear the output.\ncmd : Return to cmd.\nHelp : Show help.\n";
        BINARYSTART();
    }
    else if (mode == "BIN" || mode == "bin" || mode == "Bin" ||
        mode == "BINARY" || mode == "Binary" || mode == "binary") {
        std::cout << "\nINPUT >>> ";
        std::cin >> bin;
        bin = removeLeadingSpaces(bin);
        if (bin.size() == 1 && isalpha(bin[0])) {
            std::cout << letterToBinary(toupper(bin[0])) << "\n";
        }
        else if (isdigit(bin[0])) {
            unsigned int num = std::stoi(removeLeadingZeros(removeLeadingSpaces(bin)));
            std::cout << removeLeadingZeros(std::bitset<32>(num).to_string()) << "\n";
        }
        else {
            std::cout << "?\n";
        }
        std::cout << "\n";
        BINARYSTART();
    }
    else if (mode == "cmd" || mode == "CMD")
    {
        system("""cmd""");
    }
}

int main() {
    system("""title Binary Convertor""");
    system("""color 3""");
    BINARYSTART();
    return 0;
}
