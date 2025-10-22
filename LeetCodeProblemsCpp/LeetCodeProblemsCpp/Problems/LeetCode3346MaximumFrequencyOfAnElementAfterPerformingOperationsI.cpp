#include "LeetCode3346MaximumFrequencyOfAnElementAfterPerformingOperationsI.h"

#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int LeetCode3346MaximumFrequencyOfAnElementAfterPerformingOperationsI::maxFrequency(vector<int>& nums, int k, int numOperations)
{
    ranges::sort(nums);
    unordered_map<int, int> frequencies{};
    int uniqueIndex{};
    int length = static_cast<int>(nums.size());
    for (int i = 0; i < length; ++i)
    {
        if (frequencies.contains(nums[i]))
        {
            ++frequencies[nums[i]];
            continue;
        }
        frequencies[nums[i]] = 1;
        swap(nums[i], nums[uniqueIndex]);
        uniqueIndex++;
    }
    vector<long> prefixSums(uniqueIndex, 0);
    for (int i = 0; i < uniqueIndex; ++i)
    {
        prefixSums[i] = i > 0 ? prefixSums[i - 1] + frequencies[nums[i - 1]] : 0;
    }
    int maxFrequency{};
    int currentFrequency{};
    int maxValue = nums[uniqueIndex - 1];
    for (long i = nums[0]; i <= maxValue; ++i)
    {
        int startTarget{uniqueIndex};
        int end{uniqueIndex-1};
        int start{0};
        int mid{};
        if (i-k<=nums[0])
        {
            startTarget=0;
        }
        else
        {
            while (start <= end)
            {
                mid = (start + end) >> 1;
                if (nums[mid] >= i - k)
                {
                    startTarget = mid;
                    end = mid - 1;
                }
                else
                    start = mid + 1;
            }
            if (startTarget==uniqueIndex)
                startTarget=0;
        }
        int endTarget{-1};
        end = uniqueIndex - 1;
        start = 0;
        if (i+static_cast<long>(k)>=nums[uniqueIndex-1])
        {
            endTarget=uniqueIndex-1;
        }
        else
        {
            while (start <= end)
            {
                mid = (start + end) >> 1;
                if (nums[mid] <= i + k)
                {
                    endTarget = mid;
                    start = mid + 1;
                }
                else
                    end = mid - 1;
            }
            if (endTarget==-1)
                endTarget=0;
        }
      
        if (frequencies.contains(i))
        {
            currentFrequency = frequencies[i] + min(prefixSums[endTarget] - prefixSums[startTarget] + frequencies[nums[endTarget]] - frequencies[i], static_cast<long>(numOperations));    
        }
        else
        {
            currentFrequency =min(prefixSums[endTarget] - prefixSums[startTarget]+ frequencies[nums[endTarget]], static_cast<long>(numOperations));
        }
        
        maxFrequency = max(maxFrequency, currentFrequency);
    }
    return maxFrequency;
}

void LeetCode3346MaximumFrequencyOfAnElementAfterPerformingOperationsI::Run()
{
    vector<int> nums{31,71,14};
    int k{28};
    int numOperations{1};
    cout << maxFrequency(nums, k, numOperations) << '\n';
}
