#include "LeetCode1578MinimumTimeToMakeRopeColorful.h"
using namespace std;

int LeetCode1578MinimumTimeToMakeRopeColorful::minCost(string colors, vector<int>& neededTime)
{
    int length = colors.length();
    char previousAmount{0};
    int batchTotalWaitTime{0};
    int maxWaitTime{0};
    int totalWaitTime{0};
    for (int i = 0; i < length; ++i)
    {
        if (colors[i] == previousAmount)
        {
            maxWaitTime = max(maxWaitTime, neededTime[i]);
            batchTotalWaitTime += neededTime[i];
            continue;
        }
        if (maxWaitTime < batchTotalWaitTime)
        {
            totalWaitTime += (batchTotalWaitTime - maxWaitTime);
        }
        previousAmount = colors[i];
        batchTotalWaitTime = neededTime[i];
        maxWaitTime = neededTime[i];
    }
    if (maxWaitTime < batchTotalWaitTime)
    {
        totalWaitTime += (batchTotalWaitTime - maxWaitTime);
    }
    return totalWaitTime;
}
