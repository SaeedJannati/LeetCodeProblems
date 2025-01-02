//
// Created by saeed on 1/2/25.
//

#include "LeetCode2559CountVowelStringsInRanges.h"

#include <unordered_map>
#include <unordered_set>

#include "../Auxilary/Auxilaries.h"

std::vector<int> LeetCode2559CountVowelStringsInRanges::vowelStrings(std::vector<std::string> &words,
                                                                     std::vector<std::vector<int> > &queries) {
    int wordsSize= static_cast<int>(words.size());
    std::vector<int> prefixSum;
    prefixSum.reserve(wordsSize);
    prefixSum.push_back(hasVowelOnBothSides(words[0])?1:0);
    int sum=0;
    for (int i = 1; i < wordsSize; i++) {
        sum=prefixSum[i-1]+(hasVowelOnBothSides(words[i])?1:0);
        prefixSum.push_back(sum);
    }
    int queriesSize = static_cast<int>(queries.size());
    std::vector<int> result;
    result.reserve(queriesSize);
    int upperIndex = 0;
    int lowerAmount = 0;
    for (int i = 0; i < queriesSize; i++) {
        upperIndex = queries[i][1]>=wordsSize?wordsSize-1:queries[i][1];
        lowerAmount=queries[i][0]>0?prefixSum[queries[i][0]-1]:0;
        sum=prefixSum[upperIndex]-lowerAmount;
        result.push_back(sum);
    }
    return result;
}

bool LeetCode2559CountVowelStringsInRanges::hasVowelOnBothSides(std::string &s) {
    if (!isVowel(s[0]))
        return false;
    if (!isVowel(s.back()))
        return false;
    return true;
}
bool LeetCode2559CountVowelStringsInRanges::isVowel(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

void LeetCode2559CountVowelStringsInRanges::Run() {
    std::vector<std::string> words = {"aba", "bcb", "ece", "aa", "e"};
    std::vector<std::vector<int> > queries = {{0, 2}, {1, 4}, {1, 1}};
    auto result = vowelStrings(words, queries);
    Auxilaries::PrintVector<int>(result);
}
