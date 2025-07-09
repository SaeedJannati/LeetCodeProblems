//
// Created by saeed on 5/6/25.
//

#include "LeetCode1920BuildArrayFromPermutation.h"
using namespace std;

vector<int> LeetCode1920BuildArrayFromPermutation::buildArray(vector<int> &nums) {
    int length = nums.size();
    for (int i = 0; i < length; i++) {
        nums[i] += length * (nums[nums[i] % length] % length);
    }
    for (int i = 0; i < length; i++) {
        nums[i]=nums[i]/length;
    }
    return nums;
}
