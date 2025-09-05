//
// Created by saeed on 9/5/25.
//

#include "LeetCode2749MinimumOperationsToMakeTheIntegerZero.h"

#include <iostream>

int getDigitCount(long num) {
    int count = 0;
    for (int i = 0; i < 64; i++) {
        if (num & (1)) { count++; }
        num >>= 1;
        if (num == 0)
            break;
    }
    return count;
}

int LeetCode2749MinimumOperationsToMakeTheIntegerZero::makeTheIntegerZero(int num1, int num2) {
    for (int i = 1; i <= 60; i++) {
        long x = num1 - long(num2) * i;
        if (x < i)
            continue;
        if (getDigitCount(x) <= i)
            return i;
    }
    return -1;
}

void LeetCode2749MinimumOperationsToMakeTheIntegerZero::Run() {
    int num1 = 3;
    int num2 = -2;
    std::cout << makeTheIntegerZero(num1, num2) << '\n';
}
