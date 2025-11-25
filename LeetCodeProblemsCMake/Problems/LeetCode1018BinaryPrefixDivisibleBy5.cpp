//
// Created by saeed on 11/24/25.
//

#include "LeetCode1018BinaryPrefixDivisibleBy5.h"
using namespace std;

vector<bool> LeetCode1018BinaryPrefixDivisibleBy5::prefixesDivBy5(vector<int> &nums) {
    int mod{};
    int length = static_cast<int>(nums.size());
    vector<bool> result(length);
    for (int i = 0; i < length; i++) {
        mod = (mod * 2) % 5;
        mod += nums[i];
        mod %= 5;
        result[i] = mod==0;
    }
    return result;
}
