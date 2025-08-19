#include "LeetCode2348NumberOfZeroFilledSubarrays.h"
using  namespace  std;
long long LeetCode2348NumberOfZeroFilledSubarrays::zeroFilledSubarray( vector<int>& nums)
{
    long long result{};
    long long consecutiveZeroCount{};
    for (auto num:nums)
    {
        if (num==0)
        {
            consecutiveZeroCount++;
            continue;
        }
        if (consecutiveZeroCount>0)
        {
            result+= consecutiveZeroCount*(consecutiveZeroCount+1)/2;
        }
        consecutiveZeroCount=0;
    }
    if (consecutiveZeroCount>0)
    {
        result+= consecutiveZeroCount*(consecutiveZeroCount+1)/2;
    }
    return result;
}
