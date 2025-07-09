//
// Created by saeed on 6/6/25.
//

#include "LeetCode2434UsingARobotToPrintTheLexicographicallySmallestString.h"

#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

string LeetCode2434UsingARobotToPrintTheLexicographicallySmallestString::robotWithString(string s) {
    string outPut{};
    vector<int> charOccurances(26, 0);
    int length = s.length();
    char smallestRemain = 'z' + 1;
    for (int i = 0; i < length; i++) {
        charOccurances[s[i] - 'a']++;
        if (s[i] < smallestRemain) {
            smallestRemain = s[i];
        }
    }
    stack<char> toPrint{};
    for (int i = 0; i < length; i++) {
        while (!toPrint.empty() && toPrint.top() <= smallestRemain) {
            outPut.push_back(toPrint.top());
            toPrint.pop();
        }
        if (s[i] <= smallestRemain) {
            outPut.push_back(s[i]);
            charOccurances[smallestRemain-'a']--;
            if (charOccurances[s[i] - 'a'] == 0) {
                for (int j=smallestRemain-'a'; j<26; j++) {
                    if (charOccurances[j] != 0) {
                        smallestRemain = j+'a';
                        break;
                    }
                }
            }
            continue;
        }
        toPrint.push(s[i]);
        charOccurances[s[i] - 'a']--;
    }
    while (!toPrint.empty()) {
        outPut.push_back(toPrint.top());
        toPrint.pop();
    }
    return outPut;
}
