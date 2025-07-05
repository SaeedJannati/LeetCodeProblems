//
// Created by saeed on 7/5/25.
//

#include "LeetCode1394FindLuckyIntegerInAnArray.h"

#include <unordered_map>
#include <unordered_set>
using namespace std;
int LeetCode1394FindLuckyIntegerInAnArray::findLucky( vector<int> &arr) {
    unordered_map<int, int> frequencies{};
    for (auto num : arr) {
        if (!frequencies.contains(num))
            frequencies[num] = 0;
        frequencies[num]++;
    }
    int max{-1};
    for (auto & pair : frequencies) {
        if (pair.second != pair.first)
            continue;
        if (pair.second > max)
            max = pair.second;
    }
    return max;
}
