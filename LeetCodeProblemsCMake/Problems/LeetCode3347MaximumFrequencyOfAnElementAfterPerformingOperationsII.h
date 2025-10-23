//
// Created by saeed on 10/23/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE3347MAXIMUMFREQUENCYOFANELEMENTAFTERPERFORMINGOPERATIONSII_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE3347MAXIMUMFREQUENCYOFANELEMENTAFTERPERFORMINGOPERATIONSII_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3347MaximumFrequencyOfAnElementAfterPerformingOperationsII:BaseProblem {
private:
    int maxFrequency(std::vector<int>& nums, int k, int numOperations);
public:
     void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE3347MAXIMUMFREQUENCYOFANELEMENTAFTERPERFORMINGOPERATIONSII_H