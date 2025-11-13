//
// Created by saeed on 11/13/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODESHUFFLETHEARRAY_H
#define LEETCODEPROBLEMSCMAKE_LEETCODESHUFFLETHEARRAY_H
#include <iostream>
#include <ostream>
#include <vector>

#include "BaseProblem.h"
#include "../Auxilary/Auxilaries.h"

using namespace std;

class LeetCodeShuffleTheArray : BaseProblem {
    vector<int> shuffle(vector<int> &nums, int n) {
        for (int i = 0; i < n; i++) {
            nums[2 * i] += 10000 * (nums[i] % 10000);

            nums[2 * i + 1] += 10000 * (nums[n + i] % 10000);
        }
        for (int i = 0, e = 2 * n; i < e; i++) {
            nums[i] /= 10000;
        }
        return nums;
    }

public:
    void Run() override {
        vector<int> nums = {2, 5, 1, 3, 4, 7};
        Auxilaries::PrintVector(shuffle(nums, 3));
    }
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODESHUFFLETHEARRAY_H
