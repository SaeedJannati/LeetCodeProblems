//
// Created by saeed on 9/24/25.
//

#include "LeetCode166FractionToRecurringDecimal.h"

#include <iostream>
#include <unordered_map>
using namespace std;

string LeetCode166FractionToRecurringDecimal::fractionToDecimal(int numerator, int denominator) {
    string result = "";
    long long num = numerator;
    long long den = denominator;
    if (numerator == 0) {
        return "0";
    }
    if (num % den == 0) {
        return std::to_string(num / den);
    }
    if (num < 0 ^ den < 0) {
        result += '-';
    }

    if (num < 0) {
        num *= -1;
    }
    if (den < 0) {
        den *= -1;
    }
    unordered_map<long, int> numeratorSetStartIndex{};
    bool addedDot{};
    while (true) {
        int delta = num / den;
       auto newNum = num % den;
        if (newNum == 0) {
            result += std::to_string(delta);
            break;
        }
        if (!numeratorSetStartIndex.contains(num)) {
            if (addedDot) {
                numeratorSetStartIndex[num] = result.length() ;
            }
            result += std::to_string(delta);
            num = newNum*10;
            if (!addedDot) {
                addedDot = true;
                result += '.';
            }
            continue;
        }
        auto repeatingPart = result.substr(numeratorSetStartIndex[num]);
        result = result.substr(0, numeratorSetStartIndex[num]);
        result += "(";
        result.append(repeatingPart);
        result += ")";
        break;
    }
    return result;
}

void LeetCode166FractionToRecurringDecimal::Run() {
    int numerator = -1;
    int denominator = -6;
    cout << fractionToDecimal(numerator, denominator) << endl;
}
