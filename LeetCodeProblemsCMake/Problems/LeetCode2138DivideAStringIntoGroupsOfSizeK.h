//
// Created by saeed on 1/2/25.
//

#ifndef LEETCODE2138DIVIDEASTRINGINTOGROUPSOFSIZEK_H
#define LEETCODE2138DIVIDEASTRINGINTOGROUPSOFSIZEK_H
#include <string>
#include <vector>

#include "BaseProblem.h"


class LeetCode2138DivideAStringIntoGroupsOfSizeK : BaseProblem {
public:
    std::vector<std::string> divideString(std::string s, int k, char fill);

    void Run() override;
};


#endif //LEETCODE2138DIVIDEASTRINGINTOGROUPSOFSIZEK_H
