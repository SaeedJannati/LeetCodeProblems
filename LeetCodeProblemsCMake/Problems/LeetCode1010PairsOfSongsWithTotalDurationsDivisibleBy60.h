//
// Created by Saeed Jannati on 5/5/2026 A.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE1010PAIRSOFSONGSWITHTOTALDURATIONSDIVISIBLEBY60_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE1010PAIRSOFSONGSWITHTOTALDURATIONSDIVISIBLEBY60_H
#include <vector>

#include "BaseProblem.h"


class LeetCode1010PairsOfSongsWithTotalDurationsDivisibleBy60:BaseProblem {
private:
    int numPairsDivisibleBy60(std::vector<int> &time);
public:
    void Run() override;

};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE1010PAIRSOFSONGSWITHTOTALDURATIONSDIVISIBLEBY60_H
