#include "LeetCode1863SumOfAllSubsetXORTotals.h"
using  namespace std;
void Backtrack(int index,vector<int>& nums,int currentXor,int& sum,int length)
{
    int temp{};
    for (int i=index; i < length; i++)
    {
        temp = currentXor^ nums[i];
        sum += temp;
        Backtrack(i + 1, nums, temp, sum, length);
    }
}
int LeetCode1863SumOfAllSubsetXORTotals::subsetXORSum(vector<int>& nums)
{
    int sum{};
    Backtrack(0, nums, 0, sum, nums.size());
    return sum;
}

