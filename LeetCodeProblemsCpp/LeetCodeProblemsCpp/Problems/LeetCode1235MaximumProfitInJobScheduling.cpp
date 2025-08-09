#include "LeetCode1235MaximumProfitInJobScheduling.h"

#include <algorithm>
using namespace std;

int maxProfit(vector<vector<int>>& jobs, vector<int>& dp, int length, int index)
{
    if (dp[index] != -1)
        return dp[index];
    int nextIndex{length};
    int start{index + 1};
    int end{length - 1};
    int mid{};
    while (start <= end)
    {
        mid = (start + end) >> 1;
        if (jobs[mid][0] >= jobs[index][1])
        {
            end = mid - 1;
            nextIndex = min(nextIndex, mid);
            continue;
        }
        start = mid + 1;
    }
    if (nextIndex == length)
    {
        if (index < length - 1)
            dp[index] = max(jobs[index][2], maxProfit(jobs, dp, length, index + 1));
        else
            dp[index] = jobs[index][2];
        return dp[index];
    }
    dp[index] = max(maxProfit(jobs, dp, length, index + 1), jobs[index][2] + maxProfit(jobs, dp, length, nextIndex));
    return dp[index];
}

int LeetCode1235MaximumProfitInJobScheduling::jobScheduling(vector<int>& startTime, vector<int>& endTime,
                                                            vector<int>& profit)
{
    int length = static_cast<int>(startTime.size());
    vector<vector<int>> jobs(length, vector<int>(3, 0));
    for (int i = 0; i < length; i++)
    {
        jobs[i][0] = startTime[i];
        jobs[i][1] = endTime[i];
        jobs[i][2] = profit[i];
    }
    ranges::sort(jobs, [](const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    });
    vector<int> dp(length, -1);
    return maxProfit(jobs, dp, length, 0);
}
