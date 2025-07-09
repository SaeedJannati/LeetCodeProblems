//
// Created by saeed on 4/25/25.
//

#include "LeetCode2845CountOfInterestingSubarrays.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
using namespace std;

long long LeetCode2845CountOfInterestingSubarrays::
countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
    int length = static_cast<int>(nums.size());
    if (length == 1)
        return (nums[0] % modulo == k && 1 % modulo == k) ? 1 : 0;
    long long result{};
    vector<int> prefixVector(length, 0);
    int previous{};
    for (int i = 0; i < length; i++) {
        prefixVector[i] = previous + (nums[i] % modulo == k ? 1 : 0);
        previous = prefixVector[i];
    }
    unordered_map<int, int> prefixModMap{};
    int numToAdd{};
    prefixModMap[0]=1;
    for (int i = 0; i < length; i++) {
        numToAdd =(prefixVector[i] + modulo - k) % modulo ;
        if (prefixModMap.contains(numToAdd)) {
            result += prefixModMap[numToAdd];
        }
        numToAdd =prefixVector[i] % modulo ;
        if (!prefixModMap.contains(numToAdd)) {
            prefixModMap[numToAdd] = 0;
        }
        prefixModMap[numToAdd]++;

    }
    return result;
}

void LeetCode2845CountOfInterestingSubarrays::Run() {

vector<int>nums{3,2,4};
    int modulo=2;
    int k=1;
    cout << countInterestingSubarrays(nums, modulo, k) << endl;
}
