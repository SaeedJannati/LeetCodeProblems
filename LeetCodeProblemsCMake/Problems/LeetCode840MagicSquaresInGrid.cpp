//
// Created by saeed on 12/30/25.
//

#include "LeetCode840MagicSquaresInGrid.h"

#include <unordered_map>
#include <unordered_set>

using namespace std;

int LeetCode840MagicSquaresInGrid::numMagicSquaresInside(vector<vector<int> > &grid) {
    unordered_set<int> nums{};
    int height = static_cast<int>(grid.size());
    int width = static_cast<int>(grid[0].size());
    int result = 0;
    bool isMagic = false;
    for (int i = 1; i < height-1; i++) {
        for (int j = 1; j < width-1; j++) {
            if (grid[i][j] != 5) {
                continue;
            }
            nums = {};
            isMagic = true;
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    if (grid[i -1 + k][j - 1 + l] > 9) {
                        isMagic = false;
                        break;
                    }
                    nums.insert(grid[i - 1 + k][j - 1 + l]);
                }
                if (!isMagic) {
                    break;
                }
            }
            if (!isMagic) {
                continue;
            }
            if (nums.size() != 9)
                continue;
            if (grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] != 15) {
                continue;
            }
            if (grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1] != 15) {
                continue;
            }
            if (grid[i - 1][j - 1] + grid[i][j - 1] + grid[i + 1][j - 1] != 15) {
                continue;
            }
            if (grid[i - 1][j + 1] + grid[i][j + 1] + grid[i + 1][j + 1] != 15) {
                continue;
            }
            if (grid[i - 1][j - 1] + grid[i][j] + grid[i + 1][j + 1] != 15) {
                continue;
            }
            if (grid[i - 1][j + 1] + grid[i][j] + grid[i + 1][j - 1] != 15) {
                continue;
            }
            result++;
        }
    }
    return result;
}
