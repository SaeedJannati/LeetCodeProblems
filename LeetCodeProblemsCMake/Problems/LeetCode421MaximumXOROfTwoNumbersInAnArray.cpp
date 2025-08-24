//
// Created by saeed on 8/24/25.
//

#include "LeetCode421MaximumXOROfTwoNumbersInAnArray.h"

#include <iostream>
#include <ostream>


using namespace std;

void AddToTrie(TrieNode *node, int value) {
    int desired = (value >> node->powOfTwo) & 1;
    if (!node->children[desired]) {
        node->children[desired] = new TrieNode();
        node->children[desired]->powOfTwo = node->powOfTwo - 1;
    }
    TrieNode* next = node->children[desired];

    if (next->powOfTwo >= 0) {
        AddToTrie(next, value);
    }
}

int GetMaxXor(TrieNode *node, int value) {
    if (!node || node->powOfTwo < 0) return 0;

    int bit = (value >> node->powOfTwo) & 1;
    int opposite = bit ^ 1;

    if (node->children[opposite]) {
        return (1 << node->powOfTwo) | GetMaxXor(node->children[opposite], value);
    }
    return GetMaxXor(node->children[bit], value);
}

int LeetCode421MaximumXOROfTwoNumbersInAnArray::findMaximumXOR(vector<int> &nums) {
    if (nums.size() <= 1)
        return 0;
    int maxNum = nums[0];
    for (auto num: nums) {
        maxNum = max(maxNum, num);
    }
    int maxPowOfTwo = 31 - __builtin_clz(maxNum);
    if (maxPowOfTwo == 0) {
        return 0;
    }
    TrieNode *root = new TrieNode();
    root->powOfTwo = maxPowOfTwo;
    root->children[0] = root->children[1] = nullptr;
    for (auto num: nums) {
        AddToTrie(root, num);
    }
    int result{};

    for (auto num: nums) {
        result = max(GetMaxXor(root, num), result);
    }
    return result;
}

void LeetCode421MaximumXOROfTwoNumbersInAnArray::Run() {
    vector<int> nums{3, 10, 5, 25, 2, 8};

    cout << findMaximumXOR(nums) << endl;
}
