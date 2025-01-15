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

    TrieNode() = default;

    explicit TrieNode(std::vector<std::string>& words) {
        for (auto& word: words) {
            auto node = this;
            for (auto c: word) {
                if (!node->children.contains(c))
                    node->children[c] = std::make_unique<TrieNode>();
                node = node->children[c].get();
            }
            node->isWord=true;
        }
    }

    std::unordered_map<char, std::unique_ptr<TrieNode> > children;
};


#endif //LEETCODE140WORDBREAKII_H
