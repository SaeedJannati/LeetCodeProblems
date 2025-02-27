//
// Created by saeed on 2/27/25.
//

#include "LeetCode873LengthOfLongestFibonacciSubsequence.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <unordered_set>



int LeetCode873LengthOfLongestFibonacciSubsequence::lenLongestFibSubseq(std::vector<int> &arr) {
    int n = arr.size();
    std::unordered_map<int, int> index;
    std::vector dp(n, std::vector(n, 2));

    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        index[arr[i]] = i;
        for (int j = 0; j < i; j++) {
            int prev = arr[i] - arr[j];
            if (index.count(prev) && index[prev] < j) {
                int k = index[prev];
                dp[j][i] = dp[k][j] + 1;
                maxLen = std::max(maxLen, dp[j][i]);
            }
        }
    }

    return maxLen >= 3 ? maxLen : 0;
}


void LeetCode873LengthOfLongestFibonacciSubsequence::Run() {
    std::vector array =
            {2, 4, 5, 6, 7, 8, 11, 13, 14, 15, 21, 22, 34};
    // {1,3,7,11,12,14,18};
    // {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << lenLongestFibSubseq(array) << std::endl;
}
