//
// Created by saeed on 8/17/25.
//

#include "LeetCode837New21Game.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;


double LeetCode837New21Game::new21Game(int n, int k, int maxPts) {
    vector<double> dp(n + 1, 0);
    double sumWindow = 0;
    for (int i = k; i <= n; i++) {
        dp[i] = 1.0;
    }
    for (int i = k; i <= min(n, k + maxPts - 1); i++) {
        sumWindow += dp[i];
    }
    for (int i = k - 1; i >= 0; i--) {
        dp[i] = sumWindow / maxPts;
        sumWindow += dp[i];
        if (i + maxPts <= n)
            sumWindow -=dp[i + maxPts];
    }
    return dp[0];
}

void LeetCode837New21Game::Run() {
    int n = 10;
    int k = 1;
    int maxPts = 10;
    cout << new21Game(n, k, maxPts) << endl;
}
