//
// Created by saeed on 1/3/25.
//

#ifndef LEETCODE184SUM_H
#define LEETCODE184SUM_H
#include <unordered_map>
#include <vector>

#include "BaseProblem.h"

class IntTrieNode;
class LeetCode184Sum: BaseProblem {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);
void Run() override;

};
class IntTrieNode {
    public:
    bool Add(std::vector<int>& nums) {
        auto node = this;
        bool addedOne=false;
        for (auto num : nums) {
            if (!node->children.contains(num)) {
                node->children[num] = new IntTrieNode();
                addedOne = true;
            }
            node = node->children[num];
        }
        return addedOne;
    }

    std::pmr::unordered_map<int, IntTrieNode*> children;
};



#endif //LEETCODE184SUM_H
