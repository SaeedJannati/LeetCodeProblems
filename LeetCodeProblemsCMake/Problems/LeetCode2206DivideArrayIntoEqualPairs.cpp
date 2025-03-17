//
// Created by saeed on 3/17/25.
//

#include "LeetCode2206DivideArrayIntoEqualPairs.h"
using namespace std;

bool LeetCode2206DivideArrayIntoEqualPairs::divideArray(vector<int> &nums) {
    int count[501]{};
    for (auto num: nums) {
        count[num] ^= 1;
    }
    for (int i = 0; i < 501; i++) {
        if (count[i]==1)
            return false;
    }
    return true;
}
