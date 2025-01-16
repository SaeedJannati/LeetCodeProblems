#include "LeetCode87ScrambleString.h"

#include <iostream>
#include <unordered_map>

bool CheckScramble(std::string s1, std::string s2, int firstIndex, int secondIndex, int length,
                   std::vector<std::vector<std::vector<int>>>& dp)
{
    if (dp[firstIndex][secondIndex][length] != -1)
        return dp[firstIndex][secondIndex][length] == 1;
    if (length == 1)
    {
        dp[firstIndex][secondIndex][length] = s1[firstIndex] == s2[secondIndex] ? 1 : 0;
        return dp[firstIndex][secondIndex][length];
    }
    for (int i = 1; i < length; i++)
    {
        if (CheckScramble(s1, s2, firstIndex, secondIndex, i, dp))
        {
            dp[firstIndex][secondIndex][i] = 1;
            if (CheckScramble(s1, s2, firstIndex+i, secondIndex+i, length - i, dp))
            {
                dp[firstIndex+i][secondIndex+i][length - i] = 1;
                return true;
            }
            dp[firstIndex+i][i][secondIndex+i] = 0;
        }
        else
        {
            dp[firstIndex][secondIndex][i] = 0;
        }
        if (CheckScramble(s1, s2, firstIndex, secondIndex+ length - i, i, dp))
        {
            dp[firstIndex][secondIndex+length - i][i] = 1;
            if (CheckScramble(s1, s2, firstIndex+i, secondIndex, length - i, dp))
            {
                dp[firstIndex+i][secondIndex][length - i] = 1;
                return true;
            }
            dp[firstIndex+i][secondIndex][length - i] = 0;
        }
        else
        {
            dp[firstIndex][secondIndex+length - i][i] = 0;
        }
    }
    dp[firstIndex][secondIndex][length] = 0;
    return false;
}

bool LeetCode87ScrambleString::isScramble(std::string s1, std::string s2)
{
    int size = s1.size();
    std::vector dp(size, std::vector(size, std::vector(size + 1, -1)));
    return CheckScramble(s1, s2, 0, 0, size, dp);
}

void LeetCode87ScrambleString::Run()
{
    std::string s1{"abcdbdacbdac"};

    std::string s2{"bdacabcdbdac"};
    std::cout << isScramble(s1, s2);
}
