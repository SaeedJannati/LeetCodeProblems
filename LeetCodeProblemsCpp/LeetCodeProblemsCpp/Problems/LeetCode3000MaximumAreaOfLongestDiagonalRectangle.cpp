#include "LeetCode3000MaximumAreaOfLongestDiagonalRectangle.h"

#include <algorithm>
using namespace std;

int LeetCode3000MaximumAreaOfLongestDiagonalRectangle::areaOfMaxDiagonal(vector<vector<int>>& dimensions)
{
    int maxArea{};
    int maxDiagonal{};
    int diagonal{};
    int area{};
    for (const auto& dimension : dimensions)
    {
        diagonal = dimension[0] * dimension[0] + dimension[1] * dimension[1];
        if (diagonal == maxDiagonal)
        {
            area = dimension[0] * dimension[1];
            maxArea = max(maxArea, area);
            continue;
        }

        if (diagonal > maxDiagonal)
        {
            maxDiagonal = diagonal;
            maxArea = dimension[0] * dimension[1];;
        }
    }
    return maxArea;
}
