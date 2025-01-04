//
// Created by saeed on 1/4/25.
//

#ifndef LEETCODE1930UNIQUELENGTH3PALINDROMICSUBSEQUENCES_H
#define LEETCODE1930UNIQUELENGTH3PALINDROMICSUBSEQUENCES_H
#include <string>
#include <unordered_map>

#include "BaseProblem.h"
class TrieNode;
class LeetCode1930UniqueLength3PalindromicSubsequences: BaseProblem {
private:
    int countPalindromicSubsequence(std::string s);
public:
void Run() override;
};

class TrieNode {
    public:
    std::unordered_map<char, TrieNode*> children;
    bool Add(const char* subsequence) {
        auto node=this;
        bool addedAny=false;
        for (int i=0;i<3;i++) {
            if (!node->children.contains(subsequence[i])) {
                node->children[subsequence[i]]=new TrieNode();
                addedAny=true;
            }
            node=node->children[subsequence[i]];
        }
        return addedAny;
    }

};

#endif //LEETCODE1930UNIQUELENGTH3PALINDROMICSUBSEQUENCES_H
