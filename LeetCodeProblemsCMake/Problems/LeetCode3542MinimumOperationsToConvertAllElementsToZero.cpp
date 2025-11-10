//
// Created by saeed on 11/10/25.
//

#include "LeetCode3542MinimumOperationsToConvertAllElementsToZero.h"

#include <iostream>
#include <ostream>
#include <stack>
#include <unordered_map>
using namespace std;

int LeetCode3542MinimumOperationsToConvertAllElementsToZero::minOperations(vector<int> &nums) {
    int length = static_cast<int>(nums.size());
    int operations{};
    vector<int> rightRange(length, length - 1);
    stack<pair<int, int> > monotoniqueStack{};
    for (int i = length - 1; i >= 0; --i) {
        while ((!monotoniqueStack.empty()) && monotoniqueStack.top().first >= nums[i]) {
            monotoniqueStack.pop();
        }
        if (!monotoniqueStack.empty()) {
            rightRange[i] = monotoniqueStack.top().second - 1;
        }
        monotoniqueStack.emplace(nums[i], i);
    }
    unordered_map<int, int> operationDetails{};
    for (int i = 0; i < length; i++) {
        if (nums[i] == 0)
            continue;
        if (operationDetails.contains(nums[i])) {
            if (operationDetails[nums[i]] >= i)
                continue;
        }
        operations++;
        operationDetails[nums[i]] = rightRange[i];
    }
    return operations;
}

void LeetCode3542MinimumOperationsToConvertAllElementsToZero::Run() {
    vector<int> nums = {1, 2, 1, 2, 1, 2};
    cout << minOperations(nums) << endl;
}
