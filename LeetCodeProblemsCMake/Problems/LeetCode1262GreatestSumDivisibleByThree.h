//
// Created by saeed on 11/23/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE1262GREATESTSUMDIVISIBLEBYTHREE_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE1262GREATESTSUMDIVISIBLEBYTHREE_H
#include <algorithm>
#include <iostream>
#include <ostream>
#include <stdint.h>
#include <vector>

#include "BaseProblem.h"

using namespace std;

class LeetCode1262GreatestSumDivisibleByThree : BaseProblem{
    int maxSumDivThree(vector<int> &nums) {
        int length = nums.size();
        vector<vector<int> > dp(length+1, vector<int>(3, INT32_MIN ));
        dp[0][0] = 0;
        int newMod{};
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < 3; ++j) {
                newMod=j-(nums[i]%3);
                if (newMod < 0) {
                    newMod+=3;
                }

                dp[i+1][j] =max( dp[i][j],dp[i][newMod]+nums[i]);
            }
        }
        return dp[length][0]> INT32_MIN? dp[length][0]:0;
    }
public:
    void Run() override {
        vector<int> nums{2,19,6,16,5,10,7,4,11,6};
        cout << maxSumDivThree(nums) << endl;
    }
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE1262GREATESTSUMDIVISIBLEBYTHREE_H
