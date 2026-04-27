//
// Created by Saeed Jannati on 4/27/2026 A.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE1391CHECKIFTHEREISAVALIDPATHINAGRID_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE1391CHECKIFTHEREISAVALIDPATHINAGRID_H
#include <vector>

#include "BaseProblem.h"


class LeetCode1391CheckIfThereIsAValidPathInAGrid: BaseProblem {
private:
    bool hasValidPath(std::vector<std::vector<int>>& grid);
public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE1391CHECKIFTHEREISAVALIDPATHINAGRID_H