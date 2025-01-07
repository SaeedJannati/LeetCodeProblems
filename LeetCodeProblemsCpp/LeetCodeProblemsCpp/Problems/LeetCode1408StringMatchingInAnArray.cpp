#include "LeetCode1408StringMatchingInAnArray.h"

#include <algorithm>
#include <unordered_map>
#include <unordered_set>

std::vector<std::string> LeetCode1408StringMatchingInAnArray::stringMatching(std::vector<std::string>& words)
{
    int size = static_cast<int>(words.size());
    std::vector<std::unordered_map<char, std::unordered_set<int>>> wordsMap;
    wordsMap.resize(size);
    std::ranges::sort(words, [](const std::string& first, const std::string& second)
    {
        return first.size() < second.size();
    });
    std::vector<std::string> result;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (words[j].find(words[i]) != std::string::npos)
            {
                result.push_back(words[i]);
                break;
            }
        }
    }
    return result;
}


