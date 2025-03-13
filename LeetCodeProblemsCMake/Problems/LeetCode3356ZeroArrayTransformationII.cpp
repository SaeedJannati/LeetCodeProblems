//
// Created by saeed on 3/13/25.
//

#include "LeetCode3356ZeroArrayTransformationII.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
using namespace std;

vector<int> GetDifferenceVector(int index, std::vector<std::vector<int> > &queries,
                                unordered_map<int, vector<int> > &differenceHistory, int length) {
    vector<int> difference(length, 0);
    for (int i = 0; i <= index; i++) {
        difference[queries[i][0]] += queries[i][2];
        if (queries[i][1] + 1 < length) {
            difference[queries[i][1] + 1] -= queries[i][2];
        }
    }
    return difference;
}

int LeetCode3356ZeroArrayTransformationII::
minZeroArray(std::vector<int> &nums, std::vector<std::vector<int> > &queries) {
    bool isAlreadyAllZero = true;
    for (auto num : nums) {
        if (num != 0) {
            isAlreadyAllZero = false;
            break;
        }

    }
    if (isAlreadyAllZero) {
        return 0;
    }
    int queriesLength = static_cast<int>(queries.size());
    int length = static_cast<int>(nums.size());
    unordered_map<int, vector<int> > differenceHistory{};
    int begin = 0;
    int end = queriesLength - 1;
    int mid{};
    vector willMakeZero(queriesLength, false);
    while (begin <= end) {
        mid = (end + begin) / 2;
        auto difference = GetDifferenceVector(mid, queries, differenceHistory, length);
        bool isEnough = true;
        for (int i = 0; i < length; i++) {
            if (i > 0)
                difference[i] += difference[i - 1];
            if (difference[i] < nums[i]) {
                isEnough = false;
                break;
            }
        }
        if (isEnough) {
            willMakeZero[mid] = true;
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    if (mid == queriesLength - 1) {
        if (queriesLength > 1)
            if (willMakeZero[mid - 1])
                return mid;
        if (willMakeZero[mid])
            return mid + 1;
        return -1;
    }
    if (mid == 0) {
        if (willMakeZero[0]) {
            return 1;
        }
        return 2;
    }
    if (willMakeZero[mid]) {
        if (willMakeZero[mid - 1])
            return mid;
        return mid + 1;
    }
    if (willMakeZero[mid + 1])
        return mid + 2;
    return -1;
}

void LeetCode3356ZeroArrayTransformationII::Run() {
    vector<int> nums{5};
    vector<vector<int> > queries{{0,0,3},{0,0,2},{0,0,2},{0,0,5},{0,0,3},{0,0,4},{0,0,4},{0,0,3},{0,0,5},{0,0,4},{0,0,5},{0,0,3},{0,0,4},{0,0,1},{0,0,1}};
    cout << minZeroArray(nums, queries) << endl;
}
