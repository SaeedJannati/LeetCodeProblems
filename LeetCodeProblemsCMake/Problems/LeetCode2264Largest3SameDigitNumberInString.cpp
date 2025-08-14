//
// Created by saeed on 8/14/25.
//

#include "LeetCode2264Largest3SameDigitNumberInString.h"
using namespace std;

string LeetCode2264Largest3SameDigitNumberInString::largestGoodInteger(string num) {
    string result{""};
    char largestDigitFound = '0' - 1;
    int occurance{0};
    int lastDigit{-1};
    for (int i = 0, e = static_cast<int>(num.length()); i < e; i++) {
        if (num[i] < largestDigitFound) {
            occurance = 1;
            lastDigit = num[i];
            continue;
        }
        if (num[i] != lastDigit) {
            occurance = 1;
            lastDigit = num[i];
            continue;
        }
        occurance++;
        if (occurance == 3) {
            if (num[i] > largestDigitFound) {
                largestDigitFound = num[i];
            }

            if (num[i] == '9') {
                break;
            }
        }
    }
    if (largestDigitFound >= '0') {
        result = largestDigitFound;
        result += largestDigitFound;
        result += largestDigitFound;
    }
    return result;
}
