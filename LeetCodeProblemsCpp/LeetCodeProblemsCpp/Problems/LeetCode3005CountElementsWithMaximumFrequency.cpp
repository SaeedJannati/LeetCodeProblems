#include "LeetCode3005CountElementsWithMaximumFrequency.h"

#include <unordered_map>
using namespace std;

int LeetCode3005CountElementsWithMaximumFrequency::maxFrequencyElements(vector<int>& nums)
{
    unordered_map<int, int> map{};
    int maxFrequency{};
    for (auto num : nums)
    {
        if (!map.contains(num))
        {
            map[num] = 0;
        }
        map[num]++;
        maxFrequency = max(maxFrequency, map[num]);
    }
    int result{};
    for (auto & pair : map)
    {
        if (pair.second != maxFrequency)
            continue;
        result+=pair.second;
    }
    return result;
}
