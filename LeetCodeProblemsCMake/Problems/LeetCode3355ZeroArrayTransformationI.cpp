//
// Created by saeed on 5/20/25.
//

#include "LeetCode3355ZeroArrayTransformationI.h"

#include <iostream>
#include <ostream>
using namespace std;

bool LeetCode3355ZeroArrayTransformationI::isZeroArray(vector<int> &nums, vector<vector<int> > &queries) {
    int length = static_cast<int>(nums.size());
    vector<int> prefixSum(length, 0);
    int queriesLength = static_cast<int>(queries.size());
    int next{};
    for (int i = 0; i < queriesLength; i++) {
        prefixSum[queries[i][0]]++;
        next = queries[i][1] + 1;
        if (next >= length)
            continue;
        prefixSum[next]--;
    }
    for (int i = 0; i < length; i++) {
        if (i > 0)
            prefixSum[i] += prefixSum[i - 1];
        nums[i] = std::max(0, nums[i] - prefixSum[i]);
        if (nums[i] > 0)
            return false;
    }
    return true;
}

void LeetCode3355ZeroArrayTransformationI::Run() {
    vector<int> nums{2};
    vector<vector<int> > queries{{0, 0},{0, 0}};
    cout << isZeroArray(nums, queries) << endl;
}
