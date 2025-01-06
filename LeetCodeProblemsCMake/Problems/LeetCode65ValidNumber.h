//
// Created by saeed on 1/6/25.
//

#ifndef LEETCODE65VALIDNUMBER_H
#define LEETCODE65VALIDNUMBER_H
#include <string>

#include "BaseProblem.h"


class LeetCode65ValidNumber: BaseProblem {
private:
    bool isNumber(std::string s);
    public:
    void Run() override;
};



#endif //LEETCODE65VALIDNUMBER_H
