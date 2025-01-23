//
// Created by saeed on 1/23/25.
//

#include "LeetCode174DungeonGame.h"

#include <iostream>
#include <limits>
#include <ostream>
using namespace std;
#pragma  region tabulation
int LeetCode174DungeonGame::calculateMinimumHP(std::vector<std::vector<int> > &dungeon) {
    int height = dungeon.size();
    int width = dungeon[0].size();
    int maxValue = std::numeric_limits<int>::max();
    std::vector<std::vector<int> > dp(height+1, std::vector<int>(width+1, maxValue));
    dp[height][width-1] = 1;
    dp[height-1][width] = 1;
    for (int i = height-1; i >= 0; i--) {
        for (int j = width-1; j >= 0; j--) {
            int required=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
            if (required<1)
                required = 1;
            dp[i][j] = required;
        }
    }
    return dp[0][0];
}
#pragma endregion
#pragma region memoisation
// int MinPath(std::vector<std::vector<int> > &dungeon, int height, int width, std::vector<std::vector<int> > &dp, int row,
//             int column, int maxValue) {
//     if (row < 0 || row >= height || column < 0 || column >= width) {
//         return maxValue;
//     }
//     if (dp[row][column] < maxValue) {
//         return dp[row][column];
//     }
//     int rightValue = MinPath(dungeon, height, width, dp, row+1, column , maxValue);
//     int bottomValue = MinPath(dungeon, height, width, dp, row, column + 1, maxValue);
//     int requiredHealth = std::min(rightValue, bottomValue) - dungeon[row][column];
//     if (requiredHealth < 1)
//         requiredHealth = 1;
//     dp[row][column] = requiredHealth;
//     return requiredHealth;
// }
//
// int LeetCode174DungeonGame::calculateMinimumHP(std::vector<std::vector<int> > &dungeon) {
//     int height = dungeon.size();
//     int width = dungeon[0].size();
//     int maxValue = std::numeric_limits<int>::max();
//     std::vector<std::vector<int> > dp(height, std::vector<int>(width, maxValue));
//     int initPoint =1 -(dungeon[height - 1][width - 1]);
//     if (initPoint < 1)
//         initPoint = 1;
//     dp[height - 1][width - 1] = initPoint;
//     return MinPath(dungeon, height, width, dp, 0, 0, maxValue);
// }
#pragma endrecartesPerforeesgion
void LeetCode174DungeonGame::Run() {
    std::vector<std::vector<int> > dungeon ={{-1,1}};
        // {{-200}};
        // {{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
    // {{0,-5},{0,0}};
    // {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    std::cout << calculateMinimumHP(dungeon) << std::endl;
}
