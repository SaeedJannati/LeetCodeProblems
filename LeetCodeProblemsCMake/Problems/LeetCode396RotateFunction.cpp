//
// Created by Saeed Jannati on 5/1/2026 A.
//

#include "LeetCode396RotateFunction.h"

#include <iostream>

using namespace std;


int LeetCode396RotateFunction::maxRotateFunction(vector<int> &nums) {
    int n=static_cast<int>(nums.size());
    int currentSum{};
    int indicesSum{nums[0]};
    for (int i=1;i<n;i++) {
        currentSum+=i*nums[i];
        indicesSum+=nums[i];
    }
    int maxSum{currentSum};
    for (int i=1;i<n;i++) {
        currentSum+=indicesSum- n*nums[n-i];
        maxSum=max(maxSum,currentSum);
    }
    return maxSum;
}

void LeetCode396RotateFunction::Run() {
    vector<int> nums{4,3,2,6};
    cout << maxRotateFunction(nums)<<'\n';
}
