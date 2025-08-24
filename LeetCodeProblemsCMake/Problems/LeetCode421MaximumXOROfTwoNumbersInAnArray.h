//
// Created by saeed on 8/24/25.
//

#ifndef LEETCODE421MAXIMUMXOROFTWONUMBERSINANARRAY_H
#define LEETCODE421MAXIMUMXOROFTWONUMBERSINANARRAY_H
#include <unordered_map>
#include <vector>

#include "BaseProblem.h"

class TrieNode {
public:
    char powOfTwo;
    TrieNode* children[2]{};
};

class LeetCode421MaximumXOROfTwoNumbersInAnArray : BaseProblem{
private:
    int findMaximumXOR(std::vector<int> &nums);
public:
    void Run() override;
};


#endif //LEETCODE421MAXIMUMXOROFTWONUMBERSINANARRAY_H
