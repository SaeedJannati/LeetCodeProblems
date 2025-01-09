//
// Created by saeed on 1/9/25.
//

#include "LeetCode2185CountingWordsWithAGivenPrefix.h"

#include <iostream>

void LeetCode2185CountingWordsWithAGivenPrefix::Run() {
    std::vector<std::string> words = {"pay", "attention", "practice", "attend"};
    std::string pref = "at";
    std::cout << prefixCount(words, pref);
}
#pragma region brute force which is faster ironically
int LeetCode2185CountingWordsWithAGivenPrefix::prefixCount(std::vector<std::string> &words, std::string pref) {
    int result = 0;
    int prefLength = static_cast<int>(pref.size());
    for (const auto &word: words) {
        if (word.substr(0, prefLength) == pref) {
            result += 1;
        }
    }
    return result;
}
#pragma endregion
#pragma region PrefixTree solution
// int LeetCode2185CountingWordsWithAGivenPrefix::prefixCount(std::vector<std::string> &words, std::string pref) {
//     const auto root = new PrefixTreeNode(words);
//     const int result = root->Search(pref);
//     delete root;
//     return result;
// }
#pragma endregion
