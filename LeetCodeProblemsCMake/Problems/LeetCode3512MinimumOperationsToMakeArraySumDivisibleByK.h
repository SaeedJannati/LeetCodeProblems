//
// Created by saeed on 11/29/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE3512MINIMUMOPERATIONSTOMAKEARRAYSUMDIVISIBLEBYK_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE3512MINIMUMOPERATIONSTOMAKEARRAYSUMDIVISIBLEBYK_H
#include <numeric>
#include <vector>


class LeetCode3512MinimumOperationsToMakeArraySumDivisibleByK {
    int minOperations(std::vector<int>& nums, int k) {
        int sum=std::accumulate(nums.begin(),nums.end(),0);
        return sum%k;
    }
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE3512MINIMUMOPERATIONSTOMAKEARRAYSUMDIVISIBLEBYK_H