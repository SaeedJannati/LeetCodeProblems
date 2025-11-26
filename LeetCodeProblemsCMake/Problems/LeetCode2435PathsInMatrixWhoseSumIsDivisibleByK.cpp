//
// Created by saeed on 11/26/25.
//

#include "LeetCode2435PathsInMatrixWhoseSumIsDivisibleByK.h"
using namespace std;

int LeetCode2435PathsInMatrixWhoseSumIsDivisibleByK::numberOfPaths(vector<vector<int> > &grid, int k) {
    int height = grid.size();
    int width = grid[0].size();
    const int MOD = 1e9 + 7;
    vector<vector<vector<long> > > dp(height, vector<vector<long> >(width, vector<long>(k, 0)));
    dp[0][0][grid[0][0] % k] = 1;
    int newMod{};
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int r = 0; r < k; ++r) {
                if (i==0 && j==0 && r==grid[0][0]%k) {
                    continue;
                }
                newMod = r - grid[i][j] % k;
                if (newMod < 0) {
                    newMod += k;
                }
                dp[i][j][r] = (i > 0 ? dp[i - 1][j][newMod] : 0) + (j > 0 ? dp[i][j - 1][newMod] : 0);
                dp[i][j][r] %= MOD;
            }
        }
    }
    return dp[height - 1][width - 1][0];
}
