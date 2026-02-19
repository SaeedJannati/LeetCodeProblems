#include "LeetCode696CountBinarySubstrings.h"

#include <vector>
using namespace std;

int LeetCode696CountBinarySubstrings::countBinarySubstrings(string s)
{
    int lastSection{};
    int currentSection{};
    char previous{};
    int result{0};
    for (auto c : s)
    {
        if (c == previous)
        {
            ++currentSection;
        }
        else
        {
            result += min(lastSection, currentSection);
            lastSection = currentSection;
            currentSection = 1;
        }
        previous = c;
    }
    result += min(lastSection, currentSection);

    return result;
}

// int LeetCode696CountBinarySubstrings::countBinarySubstrings(string s)
// {
//     vector<int> sections = vector<int>{};
//     char previous{};
//     for (auto c : s)
//     {
//         if (c == previous)
//         {
//             ++sections[sections.size() - 1];
//         }
//         else
//         {
//             sections.push_back(1);
//         }
//         previous = c;
//     }
//     int sectionsCount = static_cast<int>(sections.size());
//     int result{0};
//     for (int i = 0; i < sectionsCount - 1; ++i)
//     {
//         result += min(sections[i], sections[i + 1]);
//     }
//     return result;
// }
