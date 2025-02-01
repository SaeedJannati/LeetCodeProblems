#include "LeetCode3151SpecialArrayI.h"

bool LeetCode3151SpecialArrayI::isArraySpecial(std::vector<int>& nums)
{
    int length = nums.size();
    if (length<2)
        return true;
    for (int i=1;i<length;i++)
    {
        if (nums[i]%2==nums[i-1]%2)
            return false;
    }
    return true;
}
