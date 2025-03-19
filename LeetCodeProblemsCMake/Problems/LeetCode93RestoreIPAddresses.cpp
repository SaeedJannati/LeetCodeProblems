//
// Created by saeed on 3/19/25.
//

#include "LeetCode93RestoreIPAddresses.h"

#include "../Auxilary/Auxilaries.h"
using namespace std;

void Backtrack(string &s, vector<string> &result, int index, string &current, int dotCount, int length) {
    if (index == length) {
        if (dotCount != 3)
            return;
        result.push_back(current);
        return;
    }
    if (dotCount > 3)
        return;
    string addedToCurrent{};
    int newDotCount = dotCount;
    addedToCurrent += s[index];
    if (index < length - 1) {
        addedToCurrent += ".";
        newDotCount++;
    }
    current += addedToCurrent;
    if (newDotCount <= 3)
        Backtrack(s, result, index + 1, current, newDotCount, length);
    current.erase(current.length() - addedToCurrent.length());
    newDotCount = dotCount;
    addedToCurrent.erase();
    if (index > length - 2)
        return;
    if (s[index] == '0')
        return;
    addedToCurrent += s.substr(index, 2);;
    if (index < length - 2) {
        addedToCurrent += ".";
        newDotCount++;
    }
    current += addedToCurrent;
    if (newDotCount <= 3)
        Backtrack(s, result, index + 2, current, newDotCount, length);
    current.erase(current.length() - addedToCurrent.length());
    newDotCount = dotCount;
    addedToCurrent.erase();

    if (index > length - 3)
        return;
    if (s[index] > '2')
        return;
    if (s[index] == '2') {
        if (s[index + 1] > '5')
            return;
        if (s[index + 1] == '5' && s[index + 2] > '5')
            return;
    }
    addedToCurrent += s.substr(index, 3);
    if (index < length - 3) {
        addedToCurrent += ".";
        newDotCount++;
    }
    current += addedToCurrent;
    if (newDotCount <= 3)
        Backtrack(s, result, index + 3, current, newDotCount, length);
    current.erase(current.length() - addedToCurrent.length());
}

vector<string> LeetCode93RestoreIPAddresses::restoreIpAddresses(string s) {
    vector<string> result{};
    int length = static_cast<int>(s.length());
    if (length > 12)
        return {};
    string current{};
    Backtrack(s, result, 0, current, 0, length);
    return result;
}

void LeetCode93RestoreIPAddresses::Run() {
    string s{"172162541"};
    Auxilaries::PrintVector(restoreIpAddresses(s));
}
