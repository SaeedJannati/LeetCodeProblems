//
// Created by saeed on 1/15/25.
//

#include "LeetCode140WordBreakII.h"


#include "../Auxilary/Auxilaries.h"


void Backtrack(std::string current, std::string &s, TrieNode *node, TrieNode *root
               , std::vector<std::string> &result, int index, int length) {
    if (index == length) {
        if (node->isWord)
            result.push_back(current);
        return;
    }
    std::string temp = current;
    if (node->isWord) {
        if (current.back() != ' ') {
            temp += " ";
            Backtrack(temp, s, root, root, result, index, length);
        }
    }
    temp = current;
    if (!node->children.contains(s[index]))
        return;
    auto child = node->children[s[index]].get();
    temp.push_back(s[index]);
    Backtrack(temp, s, child, root, result, index + 1, length);
}

std::vector<std::string> LeetCode140WordBreakII::wordBreak(std::string s, std::vector<std::string> &wordDict) {
    std::vector<std::string> result;
    const auto root = new TrieNode(wordDict);
    int length = static_cast<int>(s.length());
    std::string current{""};
    Backtrack(current, s, root, root, result, 0, length);
    return result;
}

void LeetCode140WordBreakII::Run() {
    std::string s = "pineapplepenapple";
    std::vector<std::string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    auto result = wordBreak(s, wordDict);
    Auxilaries::PrintVector(result);
}
