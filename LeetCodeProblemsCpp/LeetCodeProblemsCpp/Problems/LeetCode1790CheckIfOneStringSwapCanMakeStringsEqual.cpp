#include "LeetCode1790CheckIfOneStringSwapCanMakeStringsEqual.h"

#include <unordered_map>

std::unordered_map<char, int> GetWordMap(std::string& word)
{
    std::unordered_map<char, int> map{};
    for (auto& c : word)
    {
        if (!map.contains(c))
            map[c] = 0;
        map[c]++;
    }
    return map;
}

bool HasSameMap(std::string& first, std::string& second)
{
    auto firstMap = GetWordMap(first);
    auto secondMap = GetWordMap(second);
    if (firstMap.size() != secondMap.size())
        return false;
    for (auto& pair : firstMap)
    {
        if (!secondMap.contains(pair.first))
            return false;
        if (secondMap[pair.first] != pair.second)
            return false;
    }
    return true;
}

bool LeetCode1790CheckIfOneStringSwapCanMakeStringsEqual::areAlmostEqual(std::string s1, std::string s2)
{
    int firstLength = static_cast<int>(s1.length());
    int secondLength = static_cast<int>(s2.length());
    if (firstLength != secondLength)
        return false;
    if (!HasSameMap(s1, s2))
        return false;
    int changeCount = 0;
    for (int i=0;i<firstLength;i++)
    {
        if (s1[i] != s2[i])
        {
            changeCount++;
            if (changeCount > 2)
                return false;
        }
    }
    if (changeCount ==1)
        return false;
    return true;
}
