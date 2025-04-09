#include "LeetCode3375MinimumOperationsToMakeArrayValuesEqualToK.h"

#include <algorithm>
#include <unordered_set>
using namespace std;
int LeetCode3375MinimumOperationsToMakeArrayValuesEqualToK::minOperations(vector<int>& nums, int k)
{
    unordered_set<int> set{};
    int min=numeric_limits<int>::max();
    for (auto num:nums)
    {
        set.insert(num);
        min = std::min(num, min);
    }
    if (min<k)
        return -1;
    const int count=static_cast<int>( set.size());
    return min==k?count-1:count;
}
