//
// Created by saeed on 12/22/25.
//

#include "LeetCode960DeleteColumnsToMakeSortedIII.h"
using namespace std;

int getLis(vector<string> &strs, vector<int> &dp, int height, int index) {
    if (dp[index] != -1)
        return dp[index];
    dp[index] = 1;
    bool isCandidate = false;
    for (int i = 0; i < index; i++) {
        isCandidate = true;
        for (int row = 0; row < height; row++) {
            if (strs[row][i] > strs[row][index]) {
                isCandidate = false;
                break;
            }
        }
        if (isCandidate) {
            dp[index] = max(dp[index], getLis(strs, dp, height, i) + 1);
        }
    }
    return dp[index];
}

int LeetCode960DeleteColumnsToMakeSortedIII::minDeletionSize(vector<string> &strs) {
    int height = static_cast<int>(strs.size());
    int width = static_cast<int>(strs[0].size());
    vector<int> dp(width, -1);
    int maxLis{0};
    for (int i = 0; i < width; i++) {
        maxLis = max(getLis(strs, dp, height, i), maxLis);
    }
    return width - maxLis;
}
