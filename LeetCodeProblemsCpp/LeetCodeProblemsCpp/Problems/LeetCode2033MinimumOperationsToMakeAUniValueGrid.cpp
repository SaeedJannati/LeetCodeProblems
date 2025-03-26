#include "LeetCode2033MinimumOperationsToMakeAUniValueGrid.h"

#include <algorithm>
#include <iostream>
using namespace std;

int LeetCode2033MinimumOperationsToMakeAUniValueGrid::minOperations(vector<vector<int>>& grid, int x)
{
    x = abs(x);
    int height = static_cast<int>(grid.size());
    int width = static_cast<int>(grid[0].size());
    vector<int> nums{};
    nums.reserve(height * width);
    int moduloX = grid[0][0] % x;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            nums.push_back(grid[i][j]);
            if (grid[i][j] % x != moduloX)
            {
                return -1;
            }
        }
    }
    ranges::sort(nums);
    int median = nums[nums.size() / 2];
    int operations{};
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            operations += abs(grid[i][j] - median) / x;
        }
    }
    return operations;
}

void LeetCode2033MinimumOperationsToMakeAUniValueGrid::Run()
{
    vector<vector<int>> grid{{529, 529, 989}, {989, 529, 345}, {989, 805, 69}};
    int x = 92;
    cout << minOperations(grid, x) << '\n';
}
