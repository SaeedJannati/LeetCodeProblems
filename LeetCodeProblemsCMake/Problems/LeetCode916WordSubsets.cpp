//
// Created by saeed on 1/10/25.
//

#include "LeetCode916WordSubsets.h"

#include <unordered_map>

#include "../Auxilary/Auxilaries.h"
using namespace std;

std::unordered_map<char, int> GetWordMap(const std::string &word);

bool IsSubset(std::unordered_map<char, int> &map, const std::unordered_map<char, int> &target);

std::unordered_map<char, int> GetAggregateMat(std::vector<std::string> &targetWords);

std::vector<std::string> LeetCode916WordSubsets::wordSubsets(std::vector<std::string> &words1,
                                                             std::vector<std::string> &words2) {
    std::vector<std::string> result;
    std::vector<std::unordered_map<char, int> > wordsMap;
    int words1Size = static_cast<int>(words1.size());
    wordsMap.reserve(words1Size);
    for (auto &word: words1) {
        wordsMap.emplace_back(GetWordMap(word));
    }
    std::unordered_map<char, int> targetMap = GetAggregateMat(words2);
    for (int i = 0; i < words1Size; i++) {
        if (!IsSubset(wordsMap[i], targetMap))
            continue;
        result.emplace_back(words1[i]);
    }
    return result;
}


std::unordered_map<char, int> GetAggregateMat(std::vector<std::string> &targetWords) {
    std::unordered_map<char, int> result;
    for (auto &word: targetWords) {
        auto map = GetWordMap(word);
        for (auto &pair: map) {
            if (!result.contains(pair.first)) {
                result.insert(pair);
                continue;
            }
            if (result[pair.first] < pair.second) {
                result[pair.first] = pair.second;
            }
        }
    }
    return result;
}

std::unordered_map<char, int> GetWordMap(const std::string &word) {
    std::unordered_map<char, int> map;
    for (const auto &c: word) {
        if (map.contains(c)) {
            map[c]++;
            continue;
        }
        map[c] = 1;
    }
    return map;
}

bool IsSubset(std::unordered_map<char, int> &map, const std::unordered_map<char, int> &target) {
    if (target.size() > map.size())
        return false;
    for (auto &pair: target) {
        if (!map.contains(pair.first))
            return false;
        if (map[pair.first] < pair.second)
            return false;
    }
    return true;
}

void LeetCode916WordSubsets::Run() {
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "o"};
    auto result = wordSubsets(words1, words2);
    Auxilaries::PrintVector(result);
}
