#include "LeetCode3541FindMostFrequentVowelAndConsonant.h"

#include <unordered_map>
#include <unordered_set>
using namespace std;

int LeetCode3541FindMostFrequentVowelAndConsonant::maxFreqSum(string s)
{
    int frequencies[26]{0};
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int maxVowelFreq = 0;
    int maxConsonantFreq = 0;
    int currentFreq{0};
    bool isVowel = false;
    
    for (auto c : s)
    {
        isVowel = vowels.contains(c);
        currentFreq= ++frequencies[c - 'a'];
        if (isVowel)
        {
            maxVowelFreq = max(maxVowelFreq, currentFreq);
            continue;
        }
        maxConsonantFreq = max(maxConsonantFreq, currentFreq);
    }
    return maxVowelFreq + maxConsonantFreq;
}
