#include "LeetCode983MinimumCostForTickets.h"

#include <iostream>
#include <unordered_set>

int LeetCode983MinimumCostForTickets::mincostTickets(std::vector<int>& days, std::vector<int>& costs)
{
    int size = static_cast<int>(days.size());
    std::unordered_set<int> hashset(days.begin(), days.end());
    int minDay = days[0];
    int maxDay = days[size - 1];
    int deltaDay = maxDay - minDay + 1;
    std::vector<int> dp(deltaDay+1, 0);
    for (int i = 0; i < deltaDay; i++)
    {
        if (hashset.find(i + minDay) == hashset.end())
        {
            dp[i+1] = dp[i];
            continue;
        }
        dp[i+1] = dp[i] + costs[0];
        dp[i+1] = std::min(dp[i+1], dp[std::max(0, i - 6)] + costs[1]);
        dp[i+1] = std::min(dp[i+1], dp[std::max(0,i - 29) ] + costs[2]);
    }
    return dp[deltaDay ];
}

void LeetCode983MinimumCostForTickets::Run()
{
    std::vector<int> days = {1, 5, 8, 9, 10, 12, 13, 16, 17, 18, 19, 20, 23, 24, 29};
    std::vector<int> costs = {3, 12, 54};
    std::cout << mincostTickets(days, costs);
}
