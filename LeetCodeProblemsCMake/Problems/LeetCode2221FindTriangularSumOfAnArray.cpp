//
// Created by saeed on 9/30/25.
//

#include "LeetCode2221FindTriangularSumOfAnArray.h"

#include <iostream>
#include <math.h>
using namespace std;

int LeetCode2221FindTriangularSumOfAnArray::triangularSum(vector<int> &nums) {
    int length = static_cast<int>(nums.size());
    if (length == 1) {
        return nums[0];
    }
    int temp{};
    while (nums[1] != -1) {
        temp = nums[0];
        int i{};
        for (i = 1; i < length; i++) {
            if (nums[i] == -1)
                break;
            nums[i - 1] = (temp + nums[i]) % 10;
            temp = nums[i];
        }
        nums[i-1] = -1;
    }
    return nums[0];
}

void LeetCode2221FindTriangularSumOfAnArray::Run() {
    vector<int> nums{1, 2, 3, 4, 5};
    cout << triangularSum(nums) << '\n';
}
