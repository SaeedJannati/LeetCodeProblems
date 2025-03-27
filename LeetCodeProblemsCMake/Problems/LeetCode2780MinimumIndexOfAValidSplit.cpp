//
// Created by saeed on 3/27/25.
//

#include "LeetCode2780MinimumIndexOfAValidSplit.h"

#include <unordered_map>
using namespace std;

int LeetCode2780MinimumIndexOfAValidSplit::minimumIndex(vector<int> &nums) {
    unordered_map<int, vector<int> > occurrences{};
    int length = static_cast<int>(nums.size());
    int dominantElement{};
    for (int i = 0; i < length; i++) {
        if (!occurrences.contains(nums[i])) {
            occurrences[nums[i]] = vector<int>{};
        }
        occurrences[nums[i]].push_back(i);
        if (occurrences[nums[i]].size() >= length / 2) {
            dominantElement = nums[i];
        }
    }
    int dominantCount = static_cast<int>(occurrences[dominantElement].size());
    int domCountBefore{};
    int elementsBefore{};
    int domCountAfter{};
    int elementsAfter{};

    for (int i = 0; i < dominantCount; i++) {
        domCountBefore = i + 1;
        elementsBefore = occurrences[dominantElement][i] + 1;
        domCountAfter = dominantCount - domCountBefore;
        elementsAfter = length - elementsBefore;
        if (domCountBefore <= elementsBefore / 2)
            continue;
        if (domCountAfter <= elementsAfter / 2)
            continue;
        return occurrences[dominantElement][i];
    }
    return -1;
}
