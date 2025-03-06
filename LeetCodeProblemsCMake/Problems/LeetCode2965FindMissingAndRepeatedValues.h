//
// Created by saeed on 3/6/25.
//

#ifndef LEETCODE2965FINDMISSINGANDREPEATEDVALUES_H
#define LEETCODE2965FINDMISSINGANDREPEATEDVALUES_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2965FindMissingAndRepeatedValues: BaseProblem {
    private:
    std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid);
    public:
    void Run() override;
};



#endif //LEETCODE2965FINDMISSINGANDREPEATEDVALUES_H
