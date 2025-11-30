#include "LeetCode1590MakeSumDivisibleByP.h"

#include <unordered_map>
using namespace std;

int LeetCode1590MakeSumDivisibleByP::minSubarray(vector<int>& nums, int p)
{
    int length = static_cast<int>(nums.size());
    vector<long long> prefixSums(length + 1, 0);
    for (int i = 0; i < length; i++)
    {
        prefixSums[i + 1] = prefixSums[i] + nums[i];
    }

    int totalMod = prefixSums[length] % p;
    if (totalMod == 0)
        return 0;

    unordered_map<int, int> lastModIndex{};
    lastModIndex[0] = 0;

    int minLengthToRemove = length;
    long long modToFind;
    long long currentMod{};
    for (int i = 1; i <= length; i++)
    {
        currentMod = prefixSums[i] % p;

        modToFind = (currentMod - totalMod) % p;
        modToFind = (modToFind + p) % p;

        if (lastModIndex.contains(modToFind))
        {
            int currentLengthToRemove = i - lastModIndex[modToFind];
            minLengthToRemove = min(minLengthToRemove, currentLengthToRemove);
        }

        lastModIndex[currentMod] = i;
    }

    return (minLengthToRemove < length ? minLengthToRemove : -1);
}
