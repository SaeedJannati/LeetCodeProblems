//
// Created by saeed on 1/17/25.
//

#include "LeetCode29DivideTwoIntegers.h"

#include <iostream>
#include <limits>
#include <ostream>
#include <type_traits>

int LeetCode29DivideTwoIntegers::divide(int dividend, int divisor) {
    if (dividend == 0)
        return 0;
    long counter{};
    int maxInt = std::numeric_limits<int>::max();
    int minInt = std::numeric_limits<int>::min();
    const bool isPositive = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
    if (divisor == 0) {
        return isPositive ? maxInt : minInt;
    }
    const int delta = isPositive ? 1 : -1;
    long longDividend = dividend;
    if (longDividend < 0)
        longDividend = -longDividend;
    long longDivisor = divisor;
    if (longDivisor < 0)
        longDivisor = -longDivisor;
    if (longDividend == longDivisor) {
        return isPositive ? 1 : -1;
    }
    long result{};
    if (longDivisor==1) {
        result= isPositive ? longDividend : -longDividend;
        if (result>maxInt)
            return maxInt;
        if (result<minInt)
            return minInt;
        return result;
    }

    while (longDividend >= 0) {
        longDividend -= longDivisor;
        counter += delta;
    }
    counter -= delta;
    result= counter;
    if (result>maxInt)
        return maxInt;
    if (result<minInt)
        return minInt;
    return result;
}

void LeetCode29DivideTwoIntegers::Run() {
    int dividend = 2147483647;
    int divisor = -1;
    std::cout << divide(dividend,divisor) << std::endl;
}
