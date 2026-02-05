//
// Created by saeed on 2/5/26.
//

#include "LeetCode3379TransformedArray.h"
using namespace std;

vector<int> LeetCode3379TransformedArray::constructTransformedArray(vector<int> &nums) {
    int length = static_cast<int>(nums.size());
    vector<int> result(length, 0);
    int newIndex{0};
    for (int i = 0; i < length; i++) {
        newIndex = i + nums[i];
        newIndex %= length;
        if (newIndex < 0) {
            newIndex += length;
        }
        result[i] = nums[newIndex];
    }
    return result;
}
