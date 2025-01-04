//
// Created by saeed on 1/4/25.
//

#include "LeetCode1930UniqueLength3PalindromicSubsequences.h"

#include <iostream>
#include <vector>

int LeetCode1930UniqueLength3PalindromicSubsequences::countPalindromicSubsequence(std::string s) {
    std::unordered_map<char, std::vector<int> > map;
    int size = static_cast<int>(s.length());

    for (int i = 0; i < size; i++) {
        if (!map.contains(s[i])) {
            map.insert({s[i], std::vector<int>{i}});
            continue;
        }
        if (map[s[i]].size() ==1) {
            map[s[i]].push_back(i);
            continue;
        }
        map[s[i]][1] = i;
    }
    auto root = new TrieNode();
    char currentSubsequence[3];
    int result = 0;
    for (auto const pair: map) {
        size = static_cast<int>(pair.second.size());
        if (size == 1)
            continue;
        if (pair.second[1] - pair.second[0] == 1)
            continue;
        currentSubsequence[0] = pair.first;
        currentSubsequence[2] = pair.first;
        for (int i = pair.second[0]+1, e = pair.second[1]; i < e; i++) {
            currentSubsequence[1] = s[i];
            if (root->Add(currentSubsequence))
                result++;
        }
    }
    delete root;
    return result;
}

void LeetCode1930UniqueLength3PalindromicSubsequences::Run() {
std::string s = "bbcbaba";
    std::cout<<countPalindromicSubsequence(s);
}
