//
// Created by saeed on 7/2/25.
//

#include "LeetCode3333FindTheOriginalTypedStringII.h"

#include <vector>

#include "../Auxilary/Auxilaries.h"
using namespace std;
//count[i,j]=  sigma(l=>(1,f(i)),count[i-1,j-l]*l)
int GetCount(vector<int> &frequencyVector,int k, int modulo, int freqIndex, int wordLength) {
    long result{};
    long delta{};
    if (freqIndex == -1 && wordLength == 0) {
        return 1;
    }
    for (int i = 1; i <= frequencyVector[freqIndex]; i++) {
        delta = i * GetCount(frequencyVector, modulo,k, freqIndex - 1, wordLength - i);
        delta %= modulo;
        result += delta;
        result %= modulo;
    }
    return result;
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
    long upTokLettersCount{};
    long delta{};
    for (int i = length; i <= k; i++) {
        delta = GetCount(frequencyVector,k, modulo, length-1, i);
        delta %= modulo;
        upTokLettersCount += delta;
        upTokLettersCount %= modulo;
    }
    result= totalCount-upTokLettersCount;
    if (result < 0)
        result+= modulo;
    return  result;
}

void LeetCode3333FindTheOriginalTypedStringII::Run() {
    string word = "aabbccdd";
    int k = 7;
   cout<< possibleStringCount(word, k)<<'\n';
}
