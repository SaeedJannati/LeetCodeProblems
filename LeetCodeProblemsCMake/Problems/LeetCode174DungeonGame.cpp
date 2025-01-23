//
// Created by saeed on 1/23/25.
//

#include "LeetCode174DungeonGame.h"

#include <iostream>
#include <limits>
#include <ostream>
using namespace std;

int MinPath(std::vector<std::vector<int> > &dungeon, int height, int width, std::vector<std::vector<int> > &dp, int row,
            int column, int maxValue) {
    if (row < 0 || row >= height || column < 0 || column >= width) {
        return maxValue;
    }
    if (dp[row][column] < maxValue) {
        return dp[row][column];
    }
    int rightValue = MinPath(dungeon, height, width, dp, row+1, column , maxValue);
    int bottomValue = MinPath(dungeon, height, width, dp, row, column + 1, maxValue);
    int requiredHealth = std::min(rightValue, bottomValue) - dungeon[row][column];
    if (requiredHealth < 1)
        requiredHealth = 1;
    dp[row][column] = requiredHealth;
    return requiredHealth;
}

int LeetCode174DungeonGame::calculateMinimumHP(std::vector<std::vector<int> > &dungeon) {
    int height = dungeon.size();
    int width = dungeon[0].size();
    int maxValue = std::numeric_limits<int>::max();
    std::vector<std::vector<int> > dp(height, std::vector<int>(width, maxValue));
    int initPoint =1 -(dungeon[height - 1][width - 1]);
    if (initPoint < 1)
        initPoint = 1;
    dp[height - 1][width - 1] = initPoint;
    return MinPath(dungeon, height, width, dp, 0, 0, maxValue);
}

void LeetCode174DungeonGame::Run() {
    std::vector<std::vector<int> > dungeon ={{-200}};
        // {{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
    // {{0,-5},{0,0}};
    // {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    std::cout << calculateMinimumHP(dungeon) << std::endl;
}
