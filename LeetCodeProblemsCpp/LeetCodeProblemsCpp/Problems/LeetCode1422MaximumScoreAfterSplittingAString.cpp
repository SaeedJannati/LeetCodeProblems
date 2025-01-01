#include "LeetCode1422MaximumScoreAfterSplittingAString.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

int LeetCode1422MaximumScoreAfterSplittingAString::maxScore(std::string s)
{
    int length = static_cast<int>(s.length());
    if (length < 2)
        return 0;
    if (length==2)
    {
        int result=0;
        result+=s[0] == '0'?1:0;
        result+=s[1] == '1'?1:0;
        return  result;
    }
    std::vector<int> prefixZeroes(length, 0);
    std::vector<int> suffixOnes(length, 0);
    int zeroNum = 0;
    int oneNum = 0;
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '0')
        {
            zeroNum++;
        }
        if (s[length - 1 - i] == '1')
        {
            oneNum++;
        }
     

        prefixZeroes[i] = zeroNum;
        suffixOnes[length - i - 1] = oneNum;
    }
    int max = std::numeric_limits<int>::min();
    int current=0;
    for (int i = 1; i < length-1; i++)
    {
        current = prefixZeroes[i] + suffixOnes[i];
        max = std::max(current, max);
    }
    return max;
}

void LeetCode1422MaximumScoreAfterSplittingAString::Run()
{
    std::string s = "00";
    std::cout << maxScore(s) << '\n';
}
