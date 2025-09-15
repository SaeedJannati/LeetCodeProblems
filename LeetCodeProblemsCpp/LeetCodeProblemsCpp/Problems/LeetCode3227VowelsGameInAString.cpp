#include "LeetCode3227VowelsGameInAString.h"

bool LeetCode3227VowelsGameInAString::doesAliceWin(std::string s)
{
    for (auto c:s)
    {
        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        {
            return true;
        }
    }
    return false;
}
