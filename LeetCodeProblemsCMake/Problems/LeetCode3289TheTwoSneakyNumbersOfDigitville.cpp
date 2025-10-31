//
// Created by saeed on 10/31/25.
//

#include "LeetCode3289TheTwoSneakyNumbersOfDigitville.h"

#include <algorithm>
using namespace std;

vector<int> LeetCode3289TheTwoSneakyNumbersOfDigitville::getSneakyNumbers(vector<int> &nums) {
    int length = static_cast<int>(nums.size());
    ranges::sort(nums);
    vector<int> ans{};
    int delta{};
    for (int i = 0; i < length; i++) {
        if (i-nums[i]  > delta) {
            delta++;
            ans.push_back(nums[i]);
        }
    }
    return ans;
}
