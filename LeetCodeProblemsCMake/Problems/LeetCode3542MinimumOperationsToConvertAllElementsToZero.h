//
// Created by saeed on 11/10/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE3542MINIMUMOPERATIONSTOCONVERTALLELEMENTSTOZERO_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE3542MINIMUMOPERATIONSTOCONVERTALLELEMENTSTOZERO_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3542MinimumOperationsToConvertAllElementsToZero: BaseProblem {
private:
    int minOperations(std::vector<int>& nums);
public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE3542MINIMUMOPERATIONSTOCONVERTALLELEMENTSTOZERO_H