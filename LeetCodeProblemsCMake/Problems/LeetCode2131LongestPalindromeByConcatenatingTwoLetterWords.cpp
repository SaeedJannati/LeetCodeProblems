//
// Created by saeed on 5/31/25.
//

#include "LeetCode2131LongestPalindromeByConcatenatingTwoLetterWords.h"

#include <unordered_map>
using namespace std;

int LeetCode2131LongestPalindromeByConcatenatingTwoLetterWords::longestPalindrome(vector<string> &words) {
    unordered_map<char, unordered_map<char, int> > countMap{};
    unordered_map<char, unordered_map<char, int> > reverseCountMap{};
    unordered_map<char, int> sameLetterMap{};
    for (auto &word: words) {
        if (word[0] == word[1]) {
            if (!sameLetterMap.contains(word[0])) {
                sameLetterMap[word[0]] = 0;
            }
            sameLetterMap[word[0]]++;
            continue;
        }
        if (!countMap.contains(word[0])) {
            countMap[word[0]] = {};
        }
        if (!countMap[word[0]].contains(word[1])) {
            countMap[word[0]][word[1]] = 0;
        }
        countMap[word[0]][word[1]]++;
        if (!reverseCountMap.contains(word[1])) {
            reverseCountMap[word[1]] = {};
        }
        if (!reverseCountMap[word[1]].contains(word[0])) {
            reverseCountMap[word[1]][word[0]] = 0;
        }
        reverseCountMap[word[1]][word[0]]++;
    }
    int pairsCountPicked{};
    for (auto &pair: countMap) {
        for (auto &secondPair: pair.second) {
            if (reverseCountMap.contains(pair.first)) {
                if (reverseCountMap[pair.first].contains(secondPair.first)) {
                    pairsCountPicked += std::min(reverseCountMap[pair.first][secondPair.first], secondPair.second);
                }
            }
        }
    }
    bool hasAddedSingleMiddle = false;
    for (auto &pair: sameLetterMap) {
        pairsCountPicked += (pair.second / 2) * 2;
        if (pair.second % 2 == 1) {
            if (!hasAddedSingleMiddle) {
                hasAddedSingleMiddle = true;
                pairsCountPicked++;
            }
        }
    }
    return pairsCountPicked * 2;
}
