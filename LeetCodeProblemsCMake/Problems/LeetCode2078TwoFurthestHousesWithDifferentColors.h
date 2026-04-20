//
// Created by Saeed Jannati on 4/20/2026 A.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE2078TWOFURTHESTHOUSESWITHDIFFERENTCOLORS_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE2078TWOFURTHESTHOUSESWITHDIFFERENTCOLORS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2078TwoFurthestHousesWithDifferentColors: BaseProblem {
private:
    int maxDistance(std::vector<int>& colors);
public:
    void Run() override;
};




#endif //LEETCODEPROBLEMSCMAKE_LEETCODE2078TWOFURTHESTHOUSESWITHDIFFERENTCOLORS_H
