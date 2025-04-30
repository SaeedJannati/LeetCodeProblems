//
// Created by saeed on 4/30/25.
//

#include "LeetCode1295FindNumbersWithEvenNumberOfDigits.h"

#include <cmath>
#include <iostream>

int LeetCode1295FindNumbersWithEvenNumberOfDigits::findNumbers(std::vector<int> &nums) {
    int oddCount{};
    int digitCount{};
    for (auto num : nums) {
        digitCount= std::ceil(std::log10(num+1));
        if (digitCount % 2 == 0) {
            oddCount++;
        }
    }
    return oddCount;
}

void LeetCode1295FindNumbersWithEvenNumberOfDigits::Run() {
    std::vector<int> nums{12,345,2,6,7896};
    std::cout << findNumbers(nums) << '\n';
}
