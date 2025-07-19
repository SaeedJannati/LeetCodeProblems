#include "LeetCode1233RemoveSubFoldersFromTheFilesystem.h"

#include <iostream>
#include <ostream>

#include "Auxilaries.h"
using namespace std;

vector<string> GetFolders(string& folder)
{
    vector<string> result{};
    string buffer{};
    for (const char c : folder)
    {
        if (c == '/')
        {
            if (!buffer.empty())
            {
                result.emplace_back(buffer);
                buffer.clear();
            }
            continue;
        }

        buffer += c;
    }
    if (!buffer.empty())
    {
        result.emplace_back(buffer);
        buffer.clear();
    }
    return result;
}

void AddToTrie(LeetCode1233RemoveSubFoldersFromTheFilesystem::TrieNode* root, vector<string>& folderPath)
{
    auto node = root;
    for (auto& name : folderPath)
    {
        if (node->children.contains(name))
        {
            node = node->children[name];
            continue;
        }
        auto newNode = new LeetCode1233RemoveSubFoldersFromTheFilesystem::TrieNode();
        newNode->folderName = name;
        newNode->children = {};
        node->children[name] = newNode;
        node = newNode;
    }
    node->isEndOfPath = true;
}

void AddToResult(LeetCode1233RemoveSubFoldersFromTheFilesystem::TrieNode* node, string currentPath, vector<string>& result)
{
    if (!node->folderName.empty())
        currentPath += '/' + node->folderName;
    if (node->isEndOfPath)
    {
        result.emplace_back(currentPath);
        return;
    }

    for (auto& child : node->children)
    {
        AddToResult(child.second, currentPath, result);
    }
}

vector<string> LeetCode1233RemoveSubFoldersFromTheFilesystem::removeSubfolders(vector<string>& folder)
{
    auto root = new TrieNode();
    for (string& ff : folder)
    {
        vector<string> foldersList = GetFolders(ff);
        AddToTrie(root, foldersList);
    }
    vector<string> result{};
    AddToResult(root, "", result);
    return result;
}

void LeetCode1233RemoveSubFoldersFromTheFilesystem::Run()
{
    vector<string> folder = {"/a/b/c","/a/b/ca","/a/b/d"};
    auto result = removeSubfolders(folder);
    for (auto& res : result)
    {
        cout << res << ',';
    }
    cout << endl;
}
