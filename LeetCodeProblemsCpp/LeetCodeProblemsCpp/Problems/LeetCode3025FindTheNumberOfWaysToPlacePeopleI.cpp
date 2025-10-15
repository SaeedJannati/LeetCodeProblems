#include "LeetCode3025FindTheNumberOfWaysToPlacePeopleI.h"

#include <algorithm>
#include <iostream>
using namespace std;

int LeetCode3025FindTheNumberOfWaysToPlacePeopleI::numberOfPairs(vector<vector<int>>& points)
{
    int n = static_cast<int>(points.size());
    int result = 0;
    ranges::sort(points, [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    bool isValidPair{};
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (points[j][0]!=points[i][0] && points[j][1]!=points[i][1])
            {
                if (double(points[j][1]-points[i][1])/(points[j][0]-points[i][0])>0)
                    continue;
            }
            int minY = min(points[i][1], points[j][1]);
            int maxY = max(points[i][1], points[j][1]);
            isValidPair=true;
            for (int k = i + 1; k < j; ++k)
            {
                if (points[k][1] >= minY && points[k][1] <= maxY)
                {
                    isValidPair=false;
                    break;
                }
            }
            if (isValidPair)
                result++;
        }
    }
    return result;
}

void LeetCode3025FindTheNumberOfWaysToPlacePeopleI::Run()
{
    vector<vector<int>> points={{0,1},{5,2}};
    cout<<numberOfPairs(points)<<endl;
}
