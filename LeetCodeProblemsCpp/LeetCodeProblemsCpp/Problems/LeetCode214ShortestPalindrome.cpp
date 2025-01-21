#include "LeetCode214ShortestPalindrome.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

std::string LeetCode214ShortestPalindrome::shortestPalindrome(std::string s)
{
    int length=s.length();
    if (length<=1)
        return s;
    auto reverse=s;
    std::ranges::reverse(reverse);
    auto combined=s+'.'+reverse;
    int len=static_cast<int>( combined.length());
    std::vector<int> lps(len,0);
    for (int i=1;i<len;i++)
    {
        int j=lps[i-1];
        while (j>0 && s[j]!=combined[i])
        {
            j=lps[j-1];
        }
        if (s[j]==combined[i])
            j++;
        lps[i]=j;
    }
    int longestPrefix=lps.back();
    reverse=s.substr(longestPrefix);
    std::ranges::reverse(reverse);
    return reverse+s;
}

void LeetCode214ShortestPalindrome::Run()
{
    auto s="aacecaaa";
    std::cout<<shortestPalindrome(s)<<std::endl;
}
