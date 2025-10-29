//
// Created by saeed on 10/29/25.
//

#include "LeetCode3370SmallestNumberWithAllSetBits.h"

#include <iostream>
#include <ostream>

int LeetCode3370SmallestNumberWithAllSetBits::smallestNumber(int n) {

    int candidate = 1;
    while (candidate <= n) {
        candidate <<= 1;
    }
    return candidate - 1;
}

void LeetCode3370SmallestNumberWithAllSetBits::Run() {
    int n = 5;
    std::cout << smallestNumber(n) << std::endl;
}
