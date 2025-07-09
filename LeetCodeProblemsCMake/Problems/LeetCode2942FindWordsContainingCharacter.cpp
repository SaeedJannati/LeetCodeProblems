//
// Created by saeed on 5/24/25.
//

#include "LeetCode2942FindWordsContainingCharacter.h"
using namespace std;

vector<int> LeetCode2942FindWordsContainingCharacter::findWordsContaining(vector<string> &words, char x) {
    vector<int> result{};
    int length=static_cast<int>(words.size());
    for(int i=0;i<length;i++) {
        for (auto c:words[i]) {
            if (c == x) {
                result.push_back(i);
                break;
            }
        }
    }
    return result;
}
