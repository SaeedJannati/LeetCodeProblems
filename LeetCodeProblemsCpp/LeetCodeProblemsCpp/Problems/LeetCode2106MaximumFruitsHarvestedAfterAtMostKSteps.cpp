#include "LeetCode2106MaximumFruitsHarvestedAfterAtMostKSteps.h"

#include <iostream>
using namespace std;

int GetLeftIndex(vector<vector<int>>& fruits, int startPos, int length, int maxIndex, int distanceAfter)
{
    int begin = maxIndex + 1;
    int end = length - 1;
    int mid{};
    int leftIndex = {maxIndex};
    while (begin <= end)
    {
        mid = (begin + end) >> 1;
        if (fruits[mid][0] - startPos <= distanceAfter)
        {
            leftIndex = max(mid, leftIndex);
            begin = mid + 1;
            continue;
        }
        end = mid - 1;
    }
    return leftIndex;
}

int LeetCode2106MaximumFruitsHarvestedAfterAtMostKSteps::maxTotalFruits(vector<vector<int>>& fruits,
                                                                        int startPos, int k)
{
    if (startPos <= fruits[0][0])
    {
        int result{};
        for (auto& coord : fruits)
        {
            if (coord[0] > k + startPos)
                break;
            result += coord[1];
        }
        return result;
    }
    int length = static_cast<int>(fruits.size());
    vector<long> prefixSums(fruits.size(), 0);
    prefixSums[0] = fruits[0][1];
    for (int i = 1; i < length; i++)
    {
        prefixSums[i] = prefixSums[i - 1] + fruits[i][1];
    }
    int maxFruits = 0;
    int minPotentialPos = max(startPos - k, fruits[0][0]);
    int minIndex{length};
    if (minPotentialPos > fruits[0][0])
    {
        int begin = 0;
        int end = length - 1;
        int mid{};
        while (begin <= end)
        {
            mid = (begin + end) >> 1;
            if (fruits[mid][0] >= startPos - k)
            {
                minIndex = min(mid, minIndex);
                end = mid - 1;
                continue;
            }
            begin = mid + 1;
        }
    }
    else
    {
        minIndex = 0;
    }

    int maxPotentialPos = min(startPos, fruits[length - 1][0]);
    int maxIndex{0};
    if (maxPotentialPos < fruits[length - 1][0])
    {
        int begin = 0;
        int end = length - 1;
        int mid{};
        while (begin <= end)
        {
            mid = (begin + end) >> 1;
            if (fruits[mid][0] <= startPos)
            {
                maxIndex = max(mid, maxIndex);
                begin = mid + 1;
                continue;
            }
            end = mid - 1;
        }
    }
    else
    {
        maxIndex = length - 1;
    }
    int distanceBefore{};
    int distanceAfter{};
    for (int i = minIndex; i <= maxIndex; i++)
    {
        distanceBefore = startPos - fruits[i][0];
        if (distanceBefore < k / 2)
        {
            distanceAfter = k - (2 * distanceBefore);
            int leftIndex = GetLeftIndex(fruits, startPos, length, maxIndex, distanceAfter);
            int currentFruit = prefixSums[leftIndex] - prefixSums[i] + fruits[i][1];
            maxFruits = max(maxFruits, currentFruit);
            distanceAfter = (k - distanceBefore) / 2;
            leftIndex = GetLeftIndex(fruits, startPos, length, maxIndex, distanceAfter);
            currentFruit = prefixSums[leftIndex] - prefixSums[i] + fruits[i][1];
            maxFruits = max(maxFruits, currentFruit);
        }
        else
        {
            distanceAfter = (k - distanceBefore) / 2;
            int leftIndex = GetLeftIndex(fruits, startPos, length, maxIndex, distanceAfter);
            int currentFruit = prefixSums[leftIndex] - prefixSums[i] + fruits[i][1];
            maxFruits = max(maxFruits, currentFruit);
        }
    }
    distanceAfter = k;
    int leftIndex = GetLeftIndex(fruits, startPos, length, maxIndex, distanceAfter);
    int currentFruit = prefixSums[leftIndex] - prefixSums[maxIndex];
    maxFruits = max(maxFruits, currentFruit);
    return maxFruits;
}

void LeetCode2106MaximumFruitsHarvestedAfterAtMostKSteps::Run()
{
    vector<vector<int>> fruits = {
        {0, 7}, {7, 4}, {9, 10}, {12, 6}, {14, 8}, {16, 5}, {17, 8}, {19, 4}, {20, 1}, {21, 3}, {24, 3}, {25, 3},
        {26, 1}, {28, 10}, {30, 9}, {31, 6}, {32, 1}, {37, 5}, {40, 9}
    };
    int startPos = 21;
    int k = 30;
    int result = maxTotalFruits(fruits, startPos, k);
    cout << "Maximum fruits harvested: " << result << endl;
}
