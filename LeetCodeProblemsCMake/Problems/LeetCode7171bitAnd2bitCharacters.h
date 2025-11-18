//
// Created by saeed on 11/18/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE7171BITAND2BITCHARACTERS_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE7171BITAND2BITCHARACTERS_H
#include <vector>

#include "BaseProblem.h"


class LeetCode7171bitAnd2bitCharacters: BaseProblem {
private:
    bool isOneBitCharacter(std::vector<int>& bits);
public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE7171BITAND2BITCHARACTERS_H