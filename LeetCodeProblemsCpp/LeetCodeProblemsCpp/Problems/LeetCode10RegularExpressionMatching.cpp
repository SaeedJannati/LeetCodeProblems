#include "LeetCode10RegularExpressionMatching.h"

#include <iostream>
#include <vector>

void LeetCode10RegularExpressionMatching::Run()
{
    const auto input = "ab";
    const auto pattern = "abc*";
    bool outPut = isMatch(input, pattern);
    std::cout << (outPut ? "true" : "false");
}

bool LeetCode10RegularExpressionMatching::isMatch(std::string s, std::string p)
{
    int sizeS = static_cast<int>(s.size()) + 1;
    int sizeP = static_cast<int>(p.size() + 1);
    std::vector<std::vector<bool>> dpMatrix(sizeS, std::vector<bool>(sizeP, false));
    dpMatrix[0][0] = true;
    dpMatrix[0][1] = false;
    for (int i = 1; i < sizeS; i++)
    {
        dpMatrix[i][0] = false;
    }
    for (int i = 2; i < sizeP; i++)
    {
        if (p[i - 1] != '*')
        {
            dpMatrix[0][i] = false;
            continue;
        }
        if (dpMatrix[0][i - 2])
        {
            dpMatrix[0][i] = true;
            continue;
        }
        dpMatrix[0][i] = false;
    }
    for (int i = 1; i < sizeS; i++)
    {
        for (int j = 1; j < sizeP; j++)
        {
            if (p[j - 1] == '*')
            {
               if(dpMatrix[i-1][j-2])
               {
                   if(p[j-2]=='.')
                   {
                       dpMatrix[i][j] = true;
                       continue;
                   }
                   if(p[j-2]==s[i-1])
                   {
                       dpMatrix[i][j] = true;
                       continue;
                   }
               }
                if(dpMatrix[i][j-2])
                {
                    dpMatrix[i][j] = true;
                    continue;
                }
                if(dpMatrix[i-1][j])
                {
                    if(p[j-2]=='.')
                    {
                        dpMatrix[i][j] = true;
                        continue;
                    }
                    if(p[j-2]==s[i-1])
                    {
                        dpMatrix[i][j] = true;
                        continue;
                    }
                }
                dpMatrix[i][j] = false;
                continue;
            }
            if (p[j - 1] == '.')
            {
                if (dpMatrix[i - 1][j - 1])
                    dpMatrix[i][j] = true;
                continue;
            }

            if (p[j - 1] != s[i - 1])
            {
                dpMatrix[i][j] = false;
                continue;
            }
            if (dpMatrix[i - 1][j - 1])
                dpMatrix[i][j] = true;
        }
    }
    return dpMatrix[sizeS - 1][sizeP - 1];
}
