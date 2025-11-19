//
// Created by saeed on 11/19/25.
//

#include "LeetCode2154KeepMultiplyingFoundValuesByTwo.h"


#include <unordered_set>
using namespace std;

int LeetCode2154KeepMultiplyingFoundValuesByTwo::findFinalValue(vector<int> &nums, int original) {
    unordered_set<int> numsSet{};
    for (auto num: nums) {
        numsSet.insert(num);
    }
    while (numsSet.contains(original)) {
         original<<=1;
    }
    return original;
}
