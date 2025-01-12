#include "LeetCode1400ConstructKPalindromeStrings.h"

#include <unordered_map>

bool LeetCode1400ConstructKPalindromeStrings::canConstruct(std::string s, int k)
{
    int size=static_cast<int>( s.size());
    if(k>size) return false;
    std::unordered_map<char, int> map;
    for (auto & c : s)
    {
        if (!map.contains(c))
        {
            map[c]=1;
            continue;
        }
        map[c]++;
    }
    int oddCount{0};
    int evenCount{0};
    for (auto & pair: map)
    {
        if (pair.second % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }
    if (oddCount>k)
        return false;
    return true;
}
