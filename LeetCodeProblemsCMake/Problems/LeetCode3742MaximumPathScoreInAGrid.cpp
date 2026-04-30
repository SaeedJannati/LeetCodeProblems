//
// Created by Saeed Jannati on 4/30/2026 A.
//

#include "LeetCode3742MaximumPathScoreInAGrid.h"

#include <iostream>
#include <ostream>

using namespace std;

int LeetCode3742MaximumPathScoreInAGrid::maxPathScore(vector<vector<int> > &grid, int k) {
    int height = static_cast<int>(grid.size());
    int width = static_cast<int>(grid[0].size());
    vector<vector<vector<int> > > dp(height, vector<vector<int> >(width, vector<int>(k+1, -1)));
    int cost = grid[0][0] == 0 ? 0 : 1;
    dp[0][0][cost] = grid[0][0];
    int left{};
    int top{};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            cost = grid[i][j] == 0 ? 0 : 1;
            for (int l = cost; l <= k; l++) {
                left = -1;
                top = -1;
                if (i - 1 >= 0) {
                    top = dp[i - 1][j][l - cost];
                }
                if (j - 1 >= 0) {
                    left = dp[i][j - 1][l - cost];
                }
                if (top == -1 && left == -1) {
                    continue;
                }
                dp[i][j][l] = grid[i][j] + max(left, top);
            }
        }
    }
    int maxScore{-1};
    for (int i = k ; i >= 0; i--) {
        maxScore = max(maxScore, dp[height - 1][width - 1][i]);
    }
    return maxScore;
}

void LeetCode3742MaximumPathScoreInAGrid::Run() {
    vector<vector<int> > grid{{0, 1}, {2, 0}};
    int k=1;
    cout << maxPathScore(grid, k) << endl;
}
