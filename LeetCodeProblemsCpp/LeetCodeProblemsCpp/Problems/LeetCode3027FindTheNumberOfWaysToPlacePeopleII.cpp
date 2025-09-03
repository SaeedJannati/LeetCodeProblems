#include "LeetCode3027FindTheNumberOfWaysToPlacePeopleII.h"

#include <algorithm>
using namespace std;

int LeetCode3027FindTheNumberOfWaysToPlacePeopleII::numberOfPairs(vector<vector<int>>& points)
{
    ranges::sort(points,[](const vector<int>& p1, const vector<int>& p2)
    {
        if (p1[0]==p2[0]) return p1[1]>p2[1];
        return p1[0]<p2[0];
    });
    int length= static_cast<int>(points.size());
    int result{};
    for(int i=0;i<length;i++)
    {
        int lastMatchedY{INT_MIN};
        for(int j=i+1;j<length;j++)
        {
            if (points[j][1]<=points[i][1]&&points[j][1]>lastMatchedY)
            {
                result++;
                lastMatchedY=points[j][1];
            }
        }
    }
    return result;
}
