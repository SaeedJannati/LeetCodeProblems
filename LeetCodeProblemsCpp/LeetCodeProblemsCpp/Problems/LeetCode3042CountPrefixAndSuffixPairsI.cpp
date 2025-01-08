#include "LeetCode3042CountPrefixAndSuffixPairsI.h"

#include <algorithm>
#include <iostream>
#include <ostream>

int LeetCode3042CountPrefixAndSuffixPairsI::countPrefixSuffixPairs(std::vector<std::string>& words)
{
    int wordSize=words.size();
    int count=0;
    int largerWordSize=0;
    bool isMatch=false;
    for (int i = 0; i <wordSize ; i++)
    {
        for (int j = i + 1; j <wordSize; j++)
        {
            largerWordSize=words[j].length();
            isMatch=true;
            for (int k=0,e=words[i].length();k<e;k++)
            {
                if (words[i][k]!=words[j][k])
                {
                    isMatch=false;
                    break;
                }
                if (words[i][e-k-1]!=words[j][largerWordSize-k-1])
                {
                    isMatch=false;
                    break;
                }
            }
            if (isMatch)
                count++;
        }
        
    }
    return count;
}

void LeetCode3042CountPrefixAndSuffixPairsI::Run()
{
    std::vector<std::string> words={"a","aba","ababa","aa"};
    std::cout << countPrefixSuffixPairs(words) << std::endl;
}
