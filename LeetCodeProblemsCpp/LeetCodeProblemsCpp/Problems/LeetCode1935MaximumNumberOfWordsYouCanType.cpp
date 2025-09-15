#include "LeetCode1935MaximumNumberOfWordsYouCanType.h"

#include <unordered_set>

int LeetCode1935MaximumNumberOfWordsYouCanType::canBeTypedWords(std::string text, std::string brokenLetters)
{
    std::unordered_set<char> letters{};
    letters.reserve(brokenLetters.size());
    for (auto c : brokenLetters)
    {
        letters.insert(c);
    }
    int count = 0;
    bool hasBrokenLetter{};
    std::string current{};
    for (auto c : text)
    {
        if (c == ' ')
        {
            if (hasBrokenLetter)
            {
                hasBrokenLetter = false;
                current={};
                continue;
            }

            if (current.empty())
            {
                continue;
            }
            count++;
            current={};
            continue;
        }
        if (letters.contains(c))
        {
            hasBrokenLetter = true;
        }
        current+=c;
    }
    if (!hasBrokenLetter && !current.empty())
    {
        count++;
    }
    return count;   
}
