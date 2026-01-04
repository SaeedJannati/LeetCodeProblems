//
// Created by saeed on 1/4/26.
//

#include "LeetCode1411NumberOfWaysToPaintNx3Grid.h"

#include <vector>
using namespace std;
int LeetCode1411NumberOfWaysToPaintNx3Grid::numOfWays(int n) {
    vector<vector<long long>> dp(n, vector<long long>(2, 0));
    dp[0][0]=6;
    dp[0][1]=6;
    long long mod=1e9+7;
    for (int i=1;i<n;i++) {
        dp[i][0]=(3*dp[i-1][0]+2*dp[i-1][1])%mod;
        dp[i][1]=(2*dp[i-1][0]+2*dp[i-1][1])%mod;
    }
    return (dp[n-1][0]+dp[n-1][1])%mod;
}
