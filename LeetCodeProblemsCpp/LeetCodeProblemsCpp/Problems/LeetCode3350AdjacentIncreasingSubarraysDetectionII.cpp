#include "LeetCode3350AdjacentIncreasingSubarraysDetectionII.h"
using namespace std;
int LeetCode3350AdjacentIncreasingSubarraysDetectionII::maxIncreasingSubarrays( vector<int>& nums)
{
    int length = static_cast<int>(nums.size());
    int previousStreak{};
    int currentStreak{1};
    int maxK{0};
    for(int i = 1; i < length; i++)
    {
        if (nums[i]<=nums[i - 1])
        {
            maxK = max(maxK, currentStreak/2);
            maxK = max(maxK, min(currentStreak,previousStreak));
            previousStreak = currentStreak;
            currentStreak=1;
            continue;
        }
        currentStreak++;
    }
    maxK = max(maxK, currentStreak/2);
    maxK = max(maxK, min(currentStreak,previousStreak));
    return maxK;
}
