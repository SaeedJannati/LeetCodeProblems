#pragma once
#include <string>
#include <unordered_map>
#include <vector>

#include "BaseProblem.h"

class LeetCode1233RemoveSubFoldersFromTheFilesystem: BaseProblem
{
  
private:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder);
public:
    void Run() override;
    class TrieNode
    {
    public:
        bool isEndOfPath = false;
        std::string folderName{};
        std::unordered_map<std::string, TrieNode*> children{};
    };
};
