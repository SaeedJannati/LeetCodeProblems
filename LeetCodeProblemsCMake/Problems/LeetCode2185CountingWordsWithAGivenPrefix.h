//
// Created by saeed on 1/9/25.
//

#ifndef LEETCODE2185COUNTINGWORDSWITHAGIVENPREFIX_H
#define LEETCODE2185COUNTINGWORDSWITHAGIVENPREFIX_H
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "BaseProblem.h"

class PrefixTreeNode;

class LeetCode2185CountingWordsWithAGivenPrefix : BaseProblem {
public:
    void Run() override;

private:
    int prefixCount(std::vector<std::string> &words, std::string pref);
};


class PrefixTreeNode {
public:
    short wordCount = 0;

    PrefixTreeNode() {
    }

    PrefixTreeNode(std::vector<std::string> words) {
        for (auto word: words) {
            auto node = this;
            for (auto c: word) {
                if (!node->children.contains(c))
                    node->children[c] = std::make_unique<PrefixTreeNode>();
                node = node->children[c].get();
            }
            node->wordCount++;
        }
    }

    int Search(std::string &target) {
        auto node = this;
        for (auto c: target) {
            if (!node->children.contains(c))
                return 0;
            node = node->children[c].get();
        }
        return GetChildrenWordCount(node);
    }

    int GetChildrenWordCount(PrefixTreeNode *node) {
        int result = node->wordCount;
        for (const auto &c: node->children) {
            result += GetChildrenWordCount(c.second.get());
        }
        return result;
    }

    std::unordered_map<char, std::unique_ptr<PrefixTreeNode> > children;
};


#endif //LEETCODE2185COUNTINGWORDSWITHAGIVENPREFIX_H
