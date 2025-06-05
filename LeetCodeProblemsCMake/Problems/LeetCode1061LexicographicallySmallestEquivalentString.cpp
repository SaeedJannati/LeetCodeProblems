//
// Created by saeed on 6/5/25.
//

#include "LeetCode1061LexicographicallySmallestEquivalentString.h"

#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

int Find(vector<int> &parents, int value) {
    if (parents[value] == value)
        return parents[value];
    parents[value] = Find(parents, parents[value]);
    return parents[value];
}

bool Union(vector<int> &parents, int first, int second) {
    auto firstParent = Find(parents, first);
    auto secondParent = Find(parents, second);
    if (firstParent == secondParent) {
        return false;
    }
    if (firstParent < secondParent) {
        parents[secondParent] = firstParent;
        Find(parents, second);
        return true;
    }
    parents[firstParent] = secondParent;
    Find(parents, firstParent);
    return true;
}

string LeetCode1061LexicographicallySmallestEquivalentString::smallestEquivalentString(string s1,
    string s2, string baseStr) {
    vector<int> parents(26, 0);
    iota(parents.begin(), parents.end(), 0);
    int wordLength = s1.length();
    for (int i = 0; i < wordLength; i++) {
        Union(parents, s1[i]-'a', s2[i]-'a');
    }
    string result = "";
    for (auto c: baseStr) {
        int index = Find(parents, c-'a');
        result += (index + 'a');
    }
    return result;
}
