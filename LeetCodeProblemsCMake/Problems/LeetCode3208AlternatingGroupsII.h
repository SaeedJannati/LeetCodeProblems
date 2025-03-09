//
// Created by saeed on 3/9/25.
//

#ifndef LEETCODE3208ALTERNATINGGROUPSII_H
#define LEETCODE3208ALTERNATINGGROUPSII_H
#include <vector>

#include "BaseProblem.h"


class LeetCode3208AlternatingGroupsII: BaseProblem {
private:
    int numberOfAlternatingGroups(std::vector<int>& colors, int k);
    public:
    void Run() override;
};



#endif //LEETCODE3208ALTERNATINGGROUPSII_H
