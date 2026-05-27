//
// Created by saeed on 5/27/26.
//

#include "LeetCode3121CountTheNumberOfSpecialCharactersII.h"

#include <unordered_map>
using namespace std;

int LeetCode3121CountTheNumberOfSpecialCharactersII::numberOfSpecialChars(string word) {
    unordered_map<char, int> charMaps;
    for (int i = 0, e = static_cast<int>(word.size()); i < e; i++) {
        if (word[i] > 'Z') {
            charMaps[word[i]] = i;
            continue;
        }
        if (charMaps.contains(word[i]))
            continue;
        charMaps[word[i]] = i;
    }
    int result{};
    for (int i = 'a'; i <= 'z'; i++) {
        if (!charMaps.contains(i))
            continue;
        if (!charMaps.contains(i - 'a' + 'A'))
            continue;
        if (charMaps[i] > charMaps[i - 'a' + 'A'])
            continue;
        ++result;
    }
    return result;
}
