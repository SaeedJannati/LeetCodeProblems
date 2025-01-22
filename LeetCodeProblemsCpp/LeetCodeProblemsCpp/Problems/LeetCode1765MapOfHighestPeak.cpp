#include "LeetCode1765MapOfHighestPeak.h"

#include <iostream>
#include <queue>

#include "Auxilaries.h"


std::vector<std::vector<int>> LeetCode1765MapOfHighestPeak::highestPeak
(std::vector<std::vector<int>>& isWater)
{
    int height = static_cast<int>(isWater.size());
    int width = static_cast<int>(isWater[0].size());
    std::vector<std::vector<bool>> visited = std::vector(height, std::vector(width, false));
    int current = 0;
    std::queue<std::pair<int, int>> currentLayer{};
    std::queue<std::pair<int, int>> nextLayer{};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (isWater[i][j] == 1)
            {
                isWater[i][j] = 0;
                currentLayer.emplace(i, j);
                visited[i][j] = true;
            }
        }
    }
    std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    while (!currentLayer.empty())
    {
        current++;
        while (!currentLayer.empty())
        {
            auto coords = currentLayer.front();
            currentLayer.pop();
            for (auto& direction : directions)
            {
                int row = coords.first + direction.first;
                if (row < 0 || row >= height)
                {
                    continue;
                }
                int col = coords.second + direction.second;
                if (col < 0 || col >= width)
                {
                    continue;
                }
                if (visited[row][col])
                    continue;
                isWater[row][col] = current;
                visited[row][col] = true;
                nextLayer.emplace(row, col);
            }
        }
        while (!nextLayer.empty())
        {
            currentLayer.emplace(nextLayer.front());
            nextLayer.pop();
        }
    }
    return isWater;
}

void LeetCode1765MapOfHighestPeak::Run()
{
    std::vector<std::vector<int>> isWater = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    auto result = highestPeak(isWater);
    std::cout << "";
}
