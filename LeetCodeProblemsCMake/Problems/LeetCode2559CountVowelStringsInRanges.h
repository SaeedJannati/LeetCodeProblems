//
// Created by saeed on 1/2/25.
//

#ifndef LEETCODE2559COUNTVOWELSTRINGSINRANGES_H
#define LEETCODE2559COUNTVOWELSTRINGSINRANGES_H
#include <string>
#include <vector>

#include "BaseProblem.h"


class LeetCode2559CountVowelStringsInRanges : BaseProblem {
public:
    std::vector<int> vowelStrings(std::vector<std::string> &words, std::vector<std::vector<int> > &queries);

    void Run() override;

private:
    bool isVowel(char c);
    bool hasVowelOnBothSides(std::string& s);
};


#endif //LEETCODE2559COUNTVOWELSTRINGSINRANGES_H
