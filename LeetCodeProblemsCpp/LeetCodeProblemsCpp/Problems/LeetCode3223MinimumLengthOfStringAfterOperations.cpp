#include "LeetCode3223MinimumLengthOfStringAfterOperations.h"

#include <unordered_map>

int LeetCode3223MinimumLengthOfStringAfterOperations::minimumLength(std::string s)
{
    std::unordered_map<char, int> map;
    for (auto& c : s)
    {
        if (!map.contains(c))
            map[c]=1;
        else
            map[c]++;
    }
    int length=0;
    for (auto& pair : map)
    {
        if (pair.second<3)
        {
            length+=pair.second;
            continue;
        }
        if (pair.second%2==0)
        {
            length+=2;
            continue;
        }
        length+=1;
          
    }
    return length;
}
