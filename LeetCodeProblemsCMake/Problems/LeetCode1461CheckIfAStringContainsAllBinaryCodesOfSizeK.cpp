//
// Created by Saeed Jannati on 2/23/2026 A.
//

#include "LeetCode1461CheckIfAStringContainsAllBinaryCodesOfSizeK.h"

#include <unordered_map>
#include <unordered_set>
using namespace std;

bool LeetCode1461CheckIfAStringContainsAllBinaryCodesOfSizeK::hasAllCodes(string s, int k) {
    int length = static_cast<int>(s.length());
    if (length - k + 1 < 1 << k) {
        return false;
    }
    unordered_set<int> nums{};
    int candidate = 0;
    int target = 1 << k;
    for (int i = 0; i < k; i++) {
        candidate = (candidate << 1) + (s[i] == '1' ? 1 : 0);
    }
    nums.insert(candidate);
    int mask = ~target;
    for (int i = k; i < length; i++) {
        candidate = ((candidate << 1) + (s[i] == '1' ? 1 : 0)) & mask;
        nums.insert(candidate);
    }
    return nums.size() == target;
}
