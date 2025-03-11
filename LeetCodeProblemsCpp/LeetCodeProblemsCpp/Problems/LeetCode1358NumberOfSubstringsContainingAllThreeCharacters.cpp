#include "LeetCode1358NumberOfSubstringsContainingAllThreeCharacters.h"

#include <iostream>
#include <ostream>
#include <unordered_map>
#include <unordered_set>

int LeetCode1358NumberOfSubstringsContainingAllThreeCharacters::numberOfSubstrings(std::string s)
{
    std::vector<std::unordered_map<char, int>> suffixIndices(s.size(), std::unordered_map<char, int>{});
    int length = static_cast<int>(s.length());
    std::vector<char> chars{'a', 'b', 'c'};
    int resultCount = 0;
    for (auto c : chars)
    {
        suffixIndices[length - 1][c] = s[length - 1] == c ? length - 1 : -1;
    }
    for (int i = length - 2; i >= 0; i--)
    {
        for (auto c : chars)
        {
            suffixIndices[i][c] = s[i] == c ? i : suffixIndices[i + 1][c];
        }
    }
    for (int i = 0; i < length; i++)
    {
        int completenessIndex = 0;
        bool canFind = true;
        for (auto c : chars)
        {
            if (suffixIndices[i][c] == -1)
                canFind = false;
        }
        if (!canFind)
            continue;
        switch (s[i])
        {
        case 'a':
            completenessIndex = std::ranges::max(suffixIndices[i]['b'], suffixIndices[i]['c']);
            break;
        case 'b':
            completenessIndex = std::ranges::max(suffixIndices[i]['a'], suffixIndices[i]['c']);
            break;
        case 'c':
            completenessIndex = std::ranges::max(suffixIndices[i]['b'], suffixIndices[i]['a']);
            break;
        }
        resultCount += length - completenessIndex;
    }
    return resultCount;
}

void LeetCode1358NumberOfSubstringsContainingAllThreeCharacters::Run()
{
    std::string s = "ababbbc";
    std::cout << numberOfSubstrings(s) << std::endl;
}
