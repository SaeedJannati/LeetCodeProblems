//
// Created by saeed on 10/13/25.
//

#include "LeetCode2273FindResultantArrayAfterRemovingAnagrams.h"

#include <unordered_map>
using namespace std;
unordered_map<char,int> getWordMap(string &word) {
unordered_map<char,int> map{};
    for (auto c:word) {
        ++map[c];
    }
    return map;
}
bool compareMaps(unordered_map<char,int> &first, unordered_map<char,int> &second) {
    if (first.size()!=second.size())
        return false;
    for (auto & pair: first) {
        if (!second.contains(pair.first))
            return false;
        if (second[pair.first] != pair.second)
            return false;
    }
    return true;
}
vector<string> LeetCode2273FindResultantArrayAfterRemovingAnagrams::removeAnagrams(vector<string> &words) {
    pair<string,unordered_map<char,int>> previous{};
    int length = static_cast<int>(words.size());
    previous.first = words[length-1];
    previous.second = getWordMap(previous.first);
    for (int i=length-2;i>=0;i--) {
        auto currentMap=getWordMap(words[i]);
        if (!compareMaps(currentMap, previous.second)) {
            previous.second = currentMap;
            previous.first = words[i];
            continue;
        }
        words.erase(words.begin()+i+1);
    }
    return words;
}
