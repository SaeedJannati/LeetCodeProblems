//
// Created by Saeed Jannati on 4/15/2026 A.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE2515SHORTESTDISTANCETOTARGETSTRINGINACIRCULARARRAY_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE2515SHORTESTDISTANCETOTARGETSTRINGINACIRCULARARRAY_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2515ShortestDistanceToTargetStringInACircularArray : BaseProblem {
private:
    int closestTarget(std::vector<std::string>& words, std::string target, int startIndex);
public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE2515SHORTESTDISTANCETOTARGETSTRINGINACIRCULARARRAY_H