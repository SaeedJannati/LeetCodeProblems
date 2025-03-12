#include "LeetCode2529MaximumCountOfPositiveIntegerAndNegativeInteger.h"

int LeetCode2529MaximumCountOfPositiveIntegerAndNegativeInteger::maximumCount(std::vector<int>& nums)
{
    int negCount {};
    int posCount {};
    for (auto num : nums)
    {
        if (num > 0)
            posCount++;
        if (num < 0)
            negCount++;
    }
    return std::max(posCount, negCount);
}
