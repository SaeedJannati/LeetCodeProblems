//
// Created by saeed on 3/20/25.
//

#include "LeetCode95UniqueBinarySearchTreesII.h"

#include <unordered_set>

#include "../Auxilary/Auxilaries.h"
#include "../Auxilary/TreeNode.h"
using namespace std;
vector<TreeNode *> CreateTrees(int begin, int end) {
    auto result = vector<TreeNode *>{};
    if (begin >end) {
        result.push_back(nullptr);
        return result;
    }
    for (int i=begin;i<=end;i++) {
        auto leftNodes=CreateTrees(begin,i-1);
        auto rightNodes=CreateTrees(i+1,end);
        for (auto& leftNode:leftNodes) {
            for (auto& rightNode:rightNodes) {
                auto node=new TreeNode(i,leftNode,rightNode);
                result.push_back(node);
            }
        }
    }
    return result;
}

vector<TreeNode *> LeetCode95UniqueBinarySearchTreesII::generateTrees(int n) {
    vector<TreeNode *> trees{};
    vector<bool> visited(n + 1, false);
    unordered_set<int> usedNodes{};

    return CreateTrees(1,n);
}

void LeetCode95UniqueBinarySearchTreesII::Run() {
    int n = 3;
    vector<TreeNode *> trees = generateTrees(n);
    cout << "count:" << trees.size() << endl;
    for (auto &tree: trees) {
        cout << "root: " << tree->val << ",inorder:";
        cout << "{";
        TreeNode::PrintInOrder(tree);
        cout << "},preOdedr:";
        cout << "{";
        TreeNode::PrintPreOrder(tree);
        cout << "}  ";
    }
    cout << '\n';
}
