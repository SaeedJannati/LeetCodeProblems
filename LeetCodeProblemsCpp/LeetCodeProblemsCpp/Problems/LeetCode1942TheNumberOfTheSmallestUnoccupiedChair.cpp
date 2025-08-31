#include "LeetCode1942TheNumberOfTheSmallestUnoccupiedChair.h"

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int LeetCode1942TheNumberOfTheSmallestUnoccupiedChair::smallestChair(vector<vector<int>>& times, int targetFriend)
{
    int length = static_cast<int>(times.size());
    for (int i = 0; i < length; ++i)
    {
        times[i].push_back(i);
    }
    ranges::sort(times, [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
    priority_queue<int, vector<int>, greater<>> emptiedChairs{};
    int maxToOccupy = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> nextReleaseTime{};
    for (int i = 0; i < length; ++i)
    {
        while ((!nextReleaseTime.empty()) && nextReleaseTime.top().first <= times[i][0])
        {
            auto [_, chairNumber] = nextReleaseTime.top();
            nextReleaseTime.pop();
            emptiedChairs.push(chairNumber);
        }

        int chairNumber = 0;
        if (!emptiedChairs.empty())
        {
            chairNumber = emptiedChairs.top();
            emptiedChairs.pop();
        }
        else
        {
            chairNumber = maxToOccupy;
            maxToOccupy++;
        }
        if (times[i][2] == targetFriend)
            return chairNumber;
        nextReleaseTime.emplace(times[i][1], chairNumber);
    }
    return 0;
}

void LeetCode1942TheNumberOfTheSmallestUnoccupiedChair::Run()
{
    vector<vector<int>> times = {{99999, 100000}, {1, 2}};
    int targetFriend = 0;
    cout << smallestChair(times, targetFriend) << endl;
}
