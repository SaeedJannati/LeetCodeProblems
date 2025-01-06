//
// Created by saeed on 1/6/25.
//

#include "LeetCode65ValidNumber.h"

#include <iostream>

bool LeetCode65ValidNumber::isNumber(std::string s) {
    bool hadE = false;
    bool hadDot = false;
    bool hadNumber = false;
    char lastChar='1';
    int length = static_cast<int>(s.length());
    for (int i = 0; i < length; i++) {
        if (s[i] == '+' || s[i] == '-') {
            if (lastChar == 'e' || lastChar == 'E') {
                lastChar = s[i];
                continue;
            }
            if (i > 0)
                return false;
            lastChar = s[i];
            continue;
        }
        if (s[i] == '.') {
            if (hadDot) {
                return false;
            }
            if (lastChar == 'e' || lastChar == 'E') {
                return false;
            }
            if (hadE)
                return false;
            lastChar = s[i];
            hadDot = true;
            continue;
        }
        if (s[i] < '0' || s[i] > '9') {
            if (s[i] != 'e' && s[i] != 'E') {
                return false;
            }
            if (hadE)
                return false;
            if (!hadNumber)
                return false;
            hadE = true;
            hadNumber = false;
            lastChar = s[i];
            continue;
        }
        hadNumber = true;
        lastChar = s[i];
    }
    return hadNumber;
}

void LeetCode65ValidNumber::Run() {
    std::string s = "6e6.5";
    auto isNum = isNumber(s) ? "true" : "false";
    std::cout << isNum << '\n';
}
