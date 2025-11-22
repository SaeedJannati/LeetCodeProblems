//
// Created by saeed on 11/22/25.
//

#include "LeetCode3190FindMinimumOperationsToMakeAllElementsDivisibleByThree.h"
using namespace std;
int LeetCode3190FindMinimumOperationsToMakeAllElementsDivisibleByThree::minimumOperations(vector<int> &nums) {
    int operationsCount{};
    for (auto num : nums) {
        if (num%3 != 0) {
            operationsCount++;
        }
    }
    return operationsCount;
}
