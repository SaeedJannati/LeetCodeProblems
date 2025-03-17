//
// Created by saeed on 3/17/25.
//

#include "LeetCode318MaximumProductOfWordLengths.h"

#include <iostream>
#include <ostream>
using namespace std;

int LeetCode318MaximumProductOfWordLengths::maxProduct(vector<string> &words) {
    int length = static_cast<int>(words.size());
    vector<int> wordsLetters(length, 0);
    for (int i = 0; i < length; i++) {
        for (auto c: words[i]) {
            wordsLetters[i] |= 1 << (c - 'a');
        }
    }
    int maxLength{};
    int currentLength{};
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if ((wordsLetters[i] & wordsLetters[j]) != 0)
                continue;
            currentLength = words[i].length() * words[j].length();
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
        }
    }
    return maxLength;
}

void LeetCode318MaximumProductOfWordLengths::Run() {
    vector<string> words{"a","aa","aaa","aaaa"};
    cout << maxProduct(words) << endl;
}
