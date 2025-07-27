#include "LeetCode2210CountHillsAndValleysInAnArray.h"

#include <iostream>
using namespace std;

int LeetCode2210CountHillsAndValleysInAnArray::countHillValley(vector<int>& nums)
{
    long slope = 0;
    long newSlope = 0;
    int result{};
    int previousNum = nums[0];
    for (int i = 1, e = nums.size(); i < e; i++)
    {
        if (nums[i] == previousNum)
            continue;
        newSlope = nums[i] - previousNum;
        previousNum=nums[i];
        if (newSlope * slope < 0)
            result++;
        slope = newSlope;
    }
    return result;
}

void LeetCode2210CountHillsAndValleysInAnArray::Run()
{
    vector<int> nums= {2, 4, 1, 1, 6, 5};
    cout<<countHillValley(nums)<<endl;
}
