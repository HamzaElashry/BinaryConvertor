#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <cctype>

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
        {11010, 'Z'} };

    if (map.find(bin) != map.end()) {
        return + map[bin];
    }
    else {
        return '?';
    }
}

bool isValidMode(const std::string& mode) {
    return mode == "NUM" || mode == "CHAR";
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