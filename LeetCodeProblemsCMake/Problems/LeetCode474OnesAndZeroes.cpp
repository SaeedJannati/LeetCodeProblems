//
// Created by saeed on 11/11/25.
//

#include "LeetCode474OnesAndZeroes.h"

#include <iostream>
using namespace std;

int getStringCount(vector<pair<int, int> > &zeroOneCounts, vector<vector<vector<int> > > &dp, int zeroCount, int oneCount, int index) {
    if (index == -1) {
        return 0;
    }
    if (dp[zeroCount][oneCount][index] != -1)
        return dp[zeroCount][oneCount][index];
    if (zeroOneCounts[index].first > zeroCount) {
        dp[zeroCount][oneCount][index] = getStringCount(zeroOneCounts, dp, zeroCount, oneCount, index - 1);
        return dp[zeroCount][oneCount][index];
    }

    if (zeroOneCounts[index].second > oneCount) {
         dp[zeroCount][oneCount][index] = getStringCount(zeroOneCounts,dp, zeroCount, oneCount, index - 1);
        return dp[zeroCount][oneCount][index];
    }


    dp[zeroCount][oneCount][index] = max(getStringCount(zeroOneCounts,dp, zeroCount, oneCount, index - 1),
               1 + getStringCount(zeroOneCounts,dp, zeroCount - zeroOneCounts[index].first,
                                  oneCount - zeroOneCounts[index].second, index - 1));
    return dp[zeroCount][oneCount][index];
}

int LeetCode474OnesAndZeroes::findMaxForm(vector<string> &strs, int m, int n) {
    int length = static_cast<int>(strs.size());
    vector<pair<int, int> > zeroOneCounts(length);
    int zeroCount{};
    int oneCount{};
    for (int i = 0; i < length; ++i) {
        zeroCount = 0;
        oneCount = 0;
        for (auto c: strs[i]) {
            switch (c) {
                case '0':
                    ++zeroCount;
                    break;
                case '1':
                    ++oneCount;
                    break;
            }
        }
        zeroOneCounts[i] = {zeroCount, oneCount};
    }
    int max{0};
    vector<vector<vector<int> > > dp(m+1, vector<vector<int> >(n+1, vector<int>(length, -1)));
    return getStringCount(zeroOneCounts,dp, m, n, length - 1);;
}

void LeetCode474OnesAndZeroes::Run() {
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;
    cout << findMaxForm(strs, m, n) << '\n';
}
