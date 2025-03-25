#include "LeetCode3394CheckIfGridCanBeCutIntoSections.h"

#include <algorithm>
#include <iostream>
using namespace std;

bool LeetCode3394CheckIfGridCanBeCutIntoSections::checkValidCuts(int n, vector<vector<int>>& rectangles)
{
    ranges::sort(rectangles, [](const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    });
    int length = static_cast<int>(rectangles.size());
    int begin{};
    int end{};
    int mergedCounts{};
    for (int i = 0; i < length; i++)
    {
        begin=rectangles[i][0];
        end=rectangles[i][2];
        while (i<length-1&& end>rectangles[i+1][0])
        {
            end=max(end,rectangles[i+1][2]);
            i++;
        }
        mergedCounts++;
    }
    if (mergedCounts>2)
        return true;
    
    ranges::sort(rectangles,[](const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    });
    mergedCounts=0;
    for (int i=0;i<length;i++)
    {
        begin=rectangles[i][1];
        end=rectangles[i][3];
        while (i<length-1&&end>rectangles[i+1][1])
        {
            end=max(end,rectangles[i+1][3]);
            i++;
        }
        mergedCounts++;
    }
    if (mergedCounts>2)
        return true;
    return false;
}

void LeetCode3394CheckIfGridCanBeCutIntoSections::Run()
{
    int n=5;
    vector<vector<int>> rectangles{{0,2,2,4},{1,0,3,2},{2,2,3,4},{3,0,4,2},{3,2,4,4}};
    cout<<checkValidCuts(n,rectangles)<<'\n';
}
