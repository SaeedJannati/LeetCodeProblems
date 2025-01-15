//
// Created by saeed on 1/15/25.
//

#ifndef LEETCODE140WORDBREAKII_H
#define LEETCODE140WORDBREAKII_H
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "BaseProblem.h"


class LeetCode140WordBreakII : BaseProblem{
    private:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict);
    public:
    void Run() override;
};
class TrieNode {
public:
    bool isWord {false};

    TrieNode();
~TrieNode();
    explicit TrieNode(std::vector<std::string>& words);

    std::unordered_map<char, TrieNode* > children;
};


#endif //LEETCODE140WORDBREAKII_H
