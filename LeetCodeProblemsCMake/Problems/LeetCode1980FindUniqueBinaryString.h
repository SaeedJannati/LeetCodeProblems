//
// Created by saeed on 2/20/25.
//

#ifndef LEETCODE1980FINDUNIQUEBINARYSTRING_H
#define LEETCODE1980FINDUNIQUEBINARYSTRING_H
#include <string>
#include <vector>

#include "BaseProblem.h"


class LeetCode1980FindUniqueBinaryString : BaseProblem {
private:
    std::string findDifferentBinaryString(std::vector<std::string>& nums);
public:
    void Run() override;
};



#endif //LEETCODE1980FINDUNIQUEBINARYSTRING_H
