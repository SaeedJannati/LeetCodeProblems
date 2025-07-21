#include "LeetCode1957DeleteCharactersToMakeFancyString.h"
using namespace std;

string LeetCode1957DeleteCharactersToMakeFancyString::makeFancyString(string s)
{
    string result{};
    int consecutiveCounter{};
    char currentChar = 0;
    for (auto c : s)
    {
        if (c != currentChar)
        {
            consecutiveCounter = 1;
            currentChar = c;
        }
        else
        {
            consecutiveCounter++;
        }
        if (consecutiveCounter < 3)
        {
            result += c;
        }
    }
    return result;
}
