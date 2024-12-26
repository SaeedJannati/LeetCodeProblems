#include "LeetCode38CountandSay.h"

#include <iostream>

std::string LeetCode38CountandSay::countAndSay(int n)
{
    std::string s = "1";
    std::string temp = "";
    int counter = 0;
    char lastChar;
    for (int i = 1; i < n; i++)
    {
        counter = 0;
        lastChar = s[0];
        for (const char j : s)
        {
            if (j == lastChar)
            {
                counter++;
                continue;
            }
            temp += std::to_string(counter);
            temp += lastChar;
            lastChar = j;
            counter = 1;
        }
        temp += std::to_string(counter);
        temp += lastChar;
        s = temp;
        temp = "";
    }
    return s;
}

void LeetCode38CountandSay::Run()
{
    int n = 7;
    std::cout << countAndSay(n);
}
