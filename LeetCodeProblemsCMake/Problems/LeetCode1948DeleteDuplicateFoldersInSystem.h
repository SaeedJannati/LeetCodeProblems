//
// Created by saeed on 7/20/25.
//

#ifndef LEETCODE1948DELETEDUPLICATEFOLDERSINSYSTEM_H
#define LEETCODE1948DELETEDUPLICATEFOLDERSINSYSTEM_H
#include <algorithm>
#include <iostream>
#include <ostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <bits/ranges_algo.h>

#include "BaseProblem.h"


class LeetCode1948DeleteDuplicateFoldersInSystem : BaseProblem {
public:
    class TrieNode {
    public:
        bool isEnd{false};
        std::string hash{};
        bool isDeleted{false};
        std::string folderName{};
        std::unordered_map<std::string, TrieNode *> children{};
    };

    void AddToTrie(TrieNode *root, std::vector<std::string> path) {
        TrieNode *curr = root;
        for (auto &p: path) {
            if (!curr->children.contains(p)) {
                auto newNode = new TrieNode();
                newNode->folderName = p;
                newNode->isEnd = false;
                newNode->children = {};
                curr->children[p] = newNode;
            }
            curr = curr->children[p];
        }
        curr->isEnd = true;
    }

    std::string GetNodeHash(TrieNode* node) {
        if (node->children.empty()) {
            node->hash = "";
            return node->hash;
        }

        std::vector<std::string> childSerials;
        for (auto& [name, child] : node->children) {
            std::string childHash = GetNodeHash(child);
            childSerials.push_back("(" + name + childHash + ")");
        }

        std::ranges::sort(childSerials);

        std::string combined;
        for (auto& s : childSerials) {
            combined += s;
        }

        node->hash = combined;
        return node->hash;
    }


    void DfsExtractThePaths(TrieNode *node, std::vector<std::string> &currentPath,
                            std::vector<std::vector<std::string> > &result) {
        if (node->isDeleted)
            return;
        bool addedToPath = false;
        if (!node->folderName.empty()) {
            currentPath.push_back(node->folderName);
            addedToPath = true;
        }
        if (node->isEnd) {
            result.push_back(currentPath);
        }
        for (auto &p: node->children) {
            DfsExtractThePaths(p.second, currentPath, result);
        }
        if (addedToPath) {
            currentPath.pop_back();
        }
    }

    std::vector<std::vector<std::string> > deleteDuplicateFolder(std::vector<std::vector<std::string> > &paths) {
        TrieNode *root = new TrieNode();
        for (auto &path: paths) {
            AddToTrie(root, path);
        }
        GetNodeHash(root);
        std::queue<TrieNode *> nodesToCheck{};
        nodesToCheck.push(root);
        std::unordered_map<std::string, TrieNode *> nodesToKeep{};
        while (nodesToCheck.size() > 0) {
            auto node = nodesToCheck.front();
            nodesToCheck.pop();
            auto hash = node->hash;
            if (node->hash.empty())
                continue;
            if (!node->folderName.empty()) {
                if (nodesToKeep.contains(hash)) {
                    node->isDeleted = true;
                    nodesToKeep[hash]->isDeleted = true;
                    continue;
                }
                nodesToKeep[hash] = node;
            }
            for (auto &p: node->children) {
                nodesToCheck.push(p.second);
            }
        }
        std::vector<std::vector<std::string> > result{};
        std::vector<std::string> currentPath{};
        DfsExtractThePaths(root, currentPath, result);
        return result;
    }

    void Run() override {
        std::vector<std::vector<std::string> > paths = {
            {"a"}, {"c"}, {"a", "b"}, {"c", "b"}, {"a", "b", "x"}, {"a", "b", "x", "y"}, {"w"}, {"w", "y"}
        };
        auto result = deleteDuplicateFolder(paths);
        for (auto &p: result) {
            std::cout << '{';
            for (auto &folder: p) {
                std::cout << folder << ',';
            }
            std::cout << "},";
        }
        std::cout << '\n';
    }
};


#endif //LEETCODE1948DELETEDUPLICATEFOLDERSINSYSTEM_H
