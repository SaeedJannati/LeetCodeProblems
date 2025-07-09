//
// Created by saeed on 6/4/25.
//

#include "LeetCode3403FindTheLexicographicallyLargestStringFromTheBoxI.h"

#include <iostream>
#include <ostream>
using namespace std;

bool isLexicographicallyLarger(string &source, string &candidate) {
    int sourceLength = source.length();
    int candidateLength = candidate.length();
    int counter = 0;
    while (counter < sourceLength || counter < candidateLength) {
        if (counter < sourceLength && counter < candidateLength) {
            if (source[counter] == candidate[counter]) {
                counter++;
                continue;
            }
            return source[counter] < candidate[counter];
        }
        if (counter < sourceLength) {
            return false;
        }
        return true;
    }
    return false;
}

string LeetCode3403FindTheLexicographicallyLargestStringFromTheBoxI::
answerString(string word, int numFriends) {
    if (numFriends == 1) {
        return word;
    }
    int wordLength = word.length();
    int length = wordLength - numFriends + 1;
    string answer = word.substr(0, length);
    string candidate{};
    for (int i = 1; i < wordLength; i++) {
        candidate = word.substr(i, min(length, wordLength - i));
        if (!isLexicographicallyLarger(answer, candidate))
            continue;
        answer = candidate;
    }
    return answer;
}

void LeetCode3403FindTheLexicographicallyLargestStringFromTheBoxI::Run() {
    string word = "nbjnc";
    int numFriends = 2;
    cout << answerString(word, numFriends) << endl;
}
