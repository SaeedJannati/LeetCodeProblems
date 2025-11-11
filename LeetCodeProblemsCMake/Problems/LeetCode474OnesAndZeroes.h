//
// Created by saeed on 11/11/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE474ONESANDZEROES_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE474ONESANDZEROES_H
#include <string>
#include <vector>

#include "BaseProblem.h"


class LeetCode474OnesAndZeroes: BaseProblem {
private:
    int findMaxForm(std::vector<std::string>& strs, int m, int n);
public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE474ONESANDZEROES_H