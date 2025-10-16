//
// Created by saeed on 10/16/25.
//

#include "LeetCode2598SmallestMissingNonnegativeIntegerAfterOperations.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
using namespace std;
int LeetCode2598SmallestMissingNonnegativeIntegerAfterOperations::
findSmallestInteger( vector<int> &nums, int value) {
    int length = static_cast<int>(nums.size());
    if (value==1)
        return length;
    unordered_map<int, int> modMap{};
    for (int i=0; i<value; i++) {
        modMap[i]=0;
    }
    int mod{};
    for (auto num : nums) {
        mod = num%value;
        if (mod<0) {
            mod += value;
        }
        modMap[mod]++;
    }
    int minMod{0};
    int minOccurrence{modMap[0]};
    for (auto & pair:modMap) {
        if (pair.second<minOccurrence) {
            minOccurrence = pair.second;
            minMod = pair.first;
        }
        if (pair.second==minOccurrence) {
            minMod=min(minMod,pair.first);
        }
    }
    return minOccurrence*value+minMod;

}

void LeetCode2598SmallestMissingNonnegativeIntegerAfterOperations::Run() {
    vector<int> nums{1,-10,7,13,6,8};
    int value = 7;
    cout<<findSmallestInteger(nums, value)<<endl;
}
