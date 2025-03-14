//
// Created by saeed on 3/14/25.
//

#include "LeetCode2226MaximumCandiesAllocatedToKChildren.h"

#include <iostream>
#include <numeric>
#include <ostream>

int LeetCode2226MaximumCandiesAllocatedToKChildren::maximumCandies(std::vector<int> &candies, long long k) {
    long long maxPossibleCandies{};
    long long sum = 0;

    for (auto i: candies) {
        sum += i;
    }
    maxPossibleCandies = sum / k;
    if (maxPossibleCandies == 0)
        return 0;
    if (maxPossibleCandies == 1)
        return 1;
    long long begin = 1;
    long long end = maxPossibleCandies;
    long long mid{};
    long long candyCount{};

    while (begin <= end) {
        mid = (begin + end) / 2;
        candyCount = 0;
        for (auto candy: candies) {
            candyCount += candy / mid;
        }
        if (candyCount < k) {
            end = mid - 1;
            continue;
        }
        begin = mid + 1;
    }
    if (candyCount < k)
        return mid - 1;
    if (candyCount > k) {
        candyCount = 0;
        for (auto candy: candies) {
            candyCount += candy / (mid+1);
        }
        if (candyCount >= k)
            return mid+1;
    }
    return mid;
}

void LeetCode2226MaximumCandiesAllocatedToKChildren::Run() {
    std::vector<int> candies{
        12,15,19,15,15,19,14,14,15,12,11,19,13,15,14,12,16,14,14,19
    };
    long long k = 12;
    std::cout << maximumCandies(candies, k) << std::endl;
}
