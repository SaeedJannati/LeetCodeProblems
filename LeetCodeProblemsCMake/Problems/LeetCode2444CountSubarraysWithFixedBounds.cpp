//
// Created by saeed on 4/27/25.
//

#include "LeetCode2444CountSubarraysWithFixedBounds.h"

#include <iostream>
#include <limits>
#include <ostream>
using namespace std;

long long LeetCode2444CountSubarraysWithFixedBounds::countSubarrays(vector<int> &nums, int minK, int maxK) {
    vector<int> ranges{};
    int length = static_cast<int>(nums.size());
    ranges.push_back(-1);
    int max = numeric_limits<int>::min();
    int min = numeric_limits<int>::max();
    for (int i = 0; i < length; i++) {
        if (nums[i] < minK || nums[i] > maxK) {
            ranges.push_back(i);
        }
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    if (min > minK)
        return 0;
    if (max < maxK)
        return 0;
    ranges.push_back(length);
    vector<pair<int, int> > leftClosestMinMax(length+1);
    long long result {};
    int largerLimit{};
    for (int i = 0, e = static_cast<int>(ranges.size()) - 1; i < e; i++) {
        leftClosestMinMax[ranges[i + 1]].first = -1;
        leftClosestMinMax[ranges[i + 1]].second = -1;
        for (int j = ranges[i + 1] - 1; j >= ranges[i] + 1; j--) {
            leftClosestMinMax[j].first = nums[j]==minK?j:leftClosestMinMax[j+1].first;
            leftClosestMinMax[j].second=nums[j]==maxK?j:leftClosestMinMax[j+1].second;
        }
        for (int j =ranges[i] + 1 ; j < ranges[i + 1]; j++) {
            if (leftClosestMinMax[j].first == -1)
                continue;
            if (leftClosestMinMax[j].second == -1)
                continue;
            largerLimit =std::max(leftClosestMinMax[j].first, leftClosestMinMax[j].second);
            result+= ranges[i+1]-largerLimit;
        }
    }
    return result;
}

void LeetCode2444CountSubarraysWithFixedBounds::Run() {
    vector<int> nums{1,3,5,2,7,5};
    int minK{1};
    int maxK{5};
    cout << countSubarrays(nums, minK, maxK) << endl;
}
