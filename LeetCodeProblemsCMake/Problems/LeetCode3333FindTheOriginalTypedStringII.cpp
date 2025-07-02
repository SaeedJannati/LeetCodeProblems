//
// Created by saeed on 7/2/25.
//

#include "LeetCode3333FindTheOriginalTypedStringII.h"

#include <vector>

#include "../Auxilary/Auxilaries.h"
using namespace std;

int GetCount(vector<int> &frequencyVector, vector<vector<int> > &memo, vector<vector<int> > &prefixMemo, int k,
             int modulo, int freqIndex, int wordLength) {
    long result{};
    long delta{};
    if (freqIndex == -1) {
        if (wordLength == 0)
            return 1;
        return 0;
    }
    if (wordLength < 0)
        return 0;
    if (memo[freqIndex][wordLength] != -1) {
        return memo[freqIndex][wordLength];
    }
    if (freqIndex > 0 && wordLength > 0)
        if (prefixMemo[freqIndex - 1][wordLength - 1] != 0) {
            result= prefixMemo[freqIndex - 1][wordLength - 1];
            if (wordLength > frequencyVector[freqIndex] + 1){
                       result-= prefixMemo[freqIndex - 1][
                           wordLength - frequencyVector[freqIndex] - 1];
            }
            return result;
        }
    for (int i = 1; i <= frequencyVector[freqIndex]; i++) {
        delta = GetCount(frequencyVector, memo, prefixMemo, k, modulo, freqIndex - 1, wordLength - i);
        delta %= modulo;
        result += delta;
        result %= modulo;
    }
    memo[freqIndex][wordLength] = result;
    if (freqIndex > 0 && wordLength > 0) {
        prefixMemo[freqIndex - 1][wordLength - 1] = result;
        if (wordLength > frequencyVector[freqIndex] + 1)
            prefixMemo[freqIndex - 1][wordLength - 1] += prefixMemo[freqIndex - 1][
                wordLength - frequencyVector[freqIndex] - 1];
        prefixMemo[freqIndex - 1][wordLength - 1] %= modulo;
    }
    return memo[freqIndex][wordLength];
}

int LeetCode3333FindTheOriginalTypedStringII::possibleStringCount(string word, int k) {
    int modulo = 1e9 + 7;
    int result = 0;
    int length = word.length();
    if (k > length) {
        return 0;
    }
    if (k == length) {
        return 1;
    }
    long totalCount{1};
    int previousChar{0};
    int streak{0};
    vector<int> frequencyVector{};
    for (auto letter: word) {
        if (letter == previousChar) {
            streak++;
            continue;
        }
        if (streak > 0) {
            frequencyVector.push_back(streak);
        }
        streak = 1;
        previousChar = letter;
    }
    frequencyVector.push_back(streak);
    length = frequencyVector.size();

    for (auto freq: frequencyVector) {
        totalCount *= freq;
        totalCount %= modulo;
    }
    if (length > k)
        return totalCount;
    vector<vector<int> > memo(length, vector<int>(k, -1));
    vector<vector<int> > prefixMemos(length, vector<int>(k, 0));
    long upTokLettersCount{};
    long delta{};
    for (int i = length; i < k; i++) {
        delta = GetCount(frequencyVector, memo, prefixMemos, k, modulo, length - 1, i);
        delta %= modulo;
        upTokLettersCount += delta;
        upTokLettersCount %= modulo;
    }
    result = totalCount - upTokLettersCount;
    if (result < 0)
        result += modulo;
    return result;
}

void LeetCode3333FindTheOriginalTypedStringII::Run() {
    string word = "aabbccdd";
    int k = 7;
    cout << possibleStringCount(word, k) << '\n';
}
