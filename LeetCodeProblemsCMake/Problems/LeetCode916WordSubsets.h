//
// Created by saeed on 1/10/25.
//

#ifndef LEETCODE916WORDSUBSETS_H
#define LEETCODE916WORDSUBSETS_H
#include <string>
#include <vector>

#include "BaseProblem.h"


class LeetCode916WordSubsets : BaseProblem{
private:
    std::vector<std::string> wordSubsets(std::vector<std::string>& words1, std::vector<std::string>& words2);
    public:
    void Run() override;
};



#endif //LEETCODE916WORDSUBSETS_H
