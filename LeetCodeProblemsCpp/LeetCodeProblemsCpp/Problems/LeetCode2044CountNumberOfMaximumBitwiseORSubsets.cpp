#include "LeetCode2044CountNumberOfMaximumBitwiseORSubsets.h"
using namespace std;

void Backtrack(vector<int>& nums,int targetOrProduct,int length,int startIndex,int orAggregate,int & result)
{
    if (orAggregate==targetOrProduct)
    {
        result++;
    }
    for (int i = startIndex+1; i < length; i++)
    {
        Backtrack(nums,targetOrProduct,length,i,orAggregate|nums[i],result);
    }
        
}
int LeetCode2044CountNumberOfMaximumBitwiseORSubsets::countMaxOrSubsets(vector<int>& nums)
{
    int orAggregate{};
    for (const auto& num : nums)
    {
        orAggregate |= num;
    }
    int result{};
    Backtrack(nums,orAggregate,nums.size(),-1,0,result);
    return  result;
}
