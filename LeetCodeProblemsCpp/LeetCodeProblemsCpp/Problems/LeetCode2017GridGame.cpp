#include "LeetCode2017GridGame.h"

#include <algorithm>
#include <iostream>
#include <ostream>

long long LeetCode2017GridGame::gridGame(std::vector<std::vector<int>>& grid)
{
    int length = static_cast<int>(grid[0].size());
    std::vector<long long> bottomRowPrefixSum(length, 0);
    std::vector<long long> topRowSuffixSum(length, 0);
    bottomRowPrefixSum[0] = grid[1][0];
    for (int i = 1; i < length; i++)
    {
        bottomRowPrefixSum[i] = bottomRowPrefixSum[i - 1] + grid[1][i];
    }
    topRowSuffixSum[length - 1] = grid[0][length - 1];
    for (int i = length - 2; i >= 0; i--)
    {
        topRowSuffixSum[i] = topRowSuffixSum[i + 1] + grid[0][i];
    }
    long long maxPathSum = std::numeric_limits<long long>::max();
    long long currentPathSum = 0;
    for(int i=0;i<length;i++)
    {
        currentPathSum= std::max((i-1>=0?bottomRowPrefixSum[i-1]:0),(i+1<length?topRowSuffixSum[i+1]:0));
        maxPathSum = std::min(maxPathSum,currentPathSum);
    }
    return maxPathSum;
}

void LeetCode2017GridGame::Run()
{
    std::vector<std::vector<int>> grid={    {20,3,20,17,2,12,15,17,4,15},
                                                              {20,10,13,14,15,5,2,3,14,3}};
    std::cout << LeetCode2017GridGame::gridGame(grid) << std::endl;
}
