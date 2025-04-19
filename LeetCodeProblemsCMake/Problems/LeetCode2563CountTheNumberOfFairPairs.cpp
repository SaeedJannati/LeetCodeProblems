//
// Created by saeed on 4/19/25.
//

#include "LeetCode2563CountTheNumberOfFairPairs.h"

#include <algorithm>
#include <iostream>
#include <ostream>

using namespace std;

int getMinIndex(vector<int> &nums, int index, int length, int lower) {
    int begin = index + 1;
    int end = length - 1;
    int mid = (begin + end) / 2;
    int result = length;
    while (begin <= end) {
        mid = (begin + end) / 2;
        if (nums[mid] + nums[index] < lower) {
            begin = mid + 1;
            continue;
        }

        result = min(result, mid);
        end = mid - 1;
    }
    return result;
}

int getMaxIndex(vector<int> &nums, int index, int length, int upper) {
    int begin = index + 1;
    int end = length - 1;
    int mid = (begin + end) / 2;
    int result = 0;
    while (begin <= end) {
        mid = (begin + end) / 2;
        if (nums[mid] + nums[index] > upper) {
            end = mid - 1;
            continue;
        }
        result = max(result, mid);
        begin = mid + 1;
    }
    return result;
}

long long LeetCode2563CountTheNumberOfFairPairs::countFairPairs(vector<int> &nums, int lower, int upper) {
    long long output = 0;
    ranges::sort(nums);
    int length = static_cast<int>( nums.size());
    int min{};
    int max{};
    for (int i = 0; i < length-1; i++) {
        min=getMinIndex(nums, i, length, lower);
        if (min==length)
            continue;
        max=getMaxIndex(nums, i, length, upper);
        if (max==0)
            continue;
        output += max-min+1;
    }
    return output;
}

void LeetCode2563CountTheNumberOfFairPairs::Run() {
    vector<int> nums{-5,-7,-5,-7,-5};
    int lower=-12;
    int upper=-12;
    cout<<countFairPairs(nums, lower, upper)<<endl;
}
