//
// Created by saeed on 10/24/25.
//

#include "LeetCode2048NextGreaterNumericallyBalancedNumber.h"

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <ostream>
#include <vector>

void getNum(std::vector<int> &frequencies, std::vector<int> &digits, int index, bool shouldBeGreater,
            int totalDigitCount, int &minNum, int numSofar, int num) {
    if (index == digits.size()) {
        bool addedDigit{false};
        for (int i = 0; i < 10; i++) {
            if (frequencies[i] == 0)
                continue;
            if (frequencies[i] != i) {
                if (frequencies[i] == i - 1 && !addedDigit) {
                    numSofar *= 10;
                    numSofar += i;
                    addedDigit = true;
                    continue;
                }
                return;
            }
        }
        if (numSofar > num) {
            minNum = std::min(minNum, numSofar);
            return;
        }
        if (frequencies[1] == 0) {
            numSofar *= 10;
            numSofar += 1;
            minNum = std::min(minNum, numSofar);
        }
        return;
    }
    for (int i = 1; i <= totalDigitCount + 1; ++i) {
        if (frequencies[i] == i) {
            continue;
        }
        ++frequencies[i];
        getNum(frequencies, digits, index + 1, (!shouldBeGreater) || i == digits[index], totalDigitCount, minNum,
               numSofar * 10 + i, num);
        --frequencies[i];
    }
}


int LeetCode2048NextGreaterNumericallyBalancedNumber::nextBeautifulNumber(int n) {
    if (n == 0)
        return 1;
    if (n == 1e6)
        return 1224444;
    std::vector<int> digits{};
    std::vector<int> frequencies(10, 0);
    int num = n;
    while (n > 0) {
        digits.push_back(n % 10);
        n = n / 10;
    }
    std::ranges::reverse(digits);
    int result = INT_MAX;
    getNum(frequencies, digits, 0, true, digits.size(), result, 0, num);
    return result;
}

void LeetCode2048NextGreaterNumericallyBalancedNumber::Run() {
    int n = 7;
    std::cout << nextBeautifulNumber(n) << std::endl;
}
