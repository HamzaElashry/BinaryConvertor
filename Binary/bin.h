#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <cctype>
#include <bitset>

int binaryToDecimal(int bin) {
    int decimal = 0;
    int base = 1;

    while (bin) {
        int lastDigit = bin % 10;
        bin = bin / 10;
        decimal += lastDigit * base;
        base = base * 2;
    }

    return decimal;
}

char binaryToChar(int bin) {
    std::map<int, char> map = {
        {1, 'A'},
        {10, 'B'},
        {11, 'C'},
        {100, 'D'},
        {101, 'E'},
        {110, 'F'},
        {111, 'G'},
        {1000, 'H'},
        {1001, 'I'},
        {1010, 'J'},
        {1011, 'K'},
        {1100, 'L'},
        {1101, 'M'},
        {1110, 'N'},
        {1111, 'O'},
        {10000, 'P'},
        {10001, 'Q'},
        {10010, 'R'},
        {10011, 'S'},
        {10100, 'T'},
        {10101, 'U'},
        {10110, 'V'},
        {10111, 'W'},
        {11000, 'X'},
        {11001, 'Y'},
        {11010, 'Z'},
    };

    if (map.find(bin) != map.end()) {
        return + map[bin];
    }
    else {
        return '?';
    }
}

std::map<char, int> reverseMap = {
    {'A', 1},
    {'B', 10},
    {'C', 11},
    {'D', 100},
    {'E', 101},
    {'F', 110},
    {'G', 111},
    {'H', 1000},
    {'I', 1001},
    {'J', 1010},
    {'K', 1011},
    {'L', 1100},
    {'M', 1101},
    {'N', 1110},
    {'O', 1111},
    {'P', 10000},
    {'Q', 10001},
    {'R', 10010},
    {'S', 10011},
    {'T', 10100},
    {'U', 10101},
    {'V', 10110},
    {'W', 10111},
    {'X', 11000},
    {'Y', 11001},
    {'Z', 11010}
};

std::string letterToBinary(char letter) {
    auto it = reverseMap.find(letter);
    if (it != reverseMap.end()) {
        return std::bitset<8>(it->second).to_string();
    }
    else {
        return "ERROR: Letter not found in map";
    }
}

bool isValidMode(const std::string& mode) {
    return mode == "NUM" || mode == "num" || mode == "Num" || mode == "CHAR" || mode == "char" || mode == "Char" || mode == "CLEAR" || mode == "clear" || mode == "cmd" || mode == "CMD" || mode == "Clear" || mode == "EXIT" || mode == "exit" || mode == "Exit" || mode == "letter" || mode == "Letter" || mode == "LETTER" || mode == "character" || mode == "Character" || mode == "CHARACTER" || mode == "NUMBER" || mode == "Number" || mode == "number" || mode == "help" || mode == "Help" || mode == "decimal" || mode == "Decimal" || mode == "BIN" || mode == "bin" || mode == "Bin" || mode == "BINARY" || mode == "Binary" || mode == "binary";
}

bool isBinary(const std::string& bin) {
    for (char digit : bin) {
        if (digit != '0' && digit != '1') {
            return false;
        }
    }
    return true;
}

std::string removeLeadingZeros(std::string bin) {
    bin.erase(0, bin.find_first_not_of('0'));
    return bin.empty() ? "0" : bin;
}

std::string removeLeadingSpaces(std::string bin) {
    bin.erase(0, bin.find_first_not_of(' '));
    return bin.empty() ? " " : bin;
}