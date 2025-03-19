//
// Created by saeed on 3/19/25.
//

#ifndef LEETCODE93RESTOREIPADDRESSES_H
#define LEETCODE93RESTOREIPADDRESSES_H
#include <string>
#include <vector>

#include "BaseProblem.h"


class LeetCode93RestoreIPAddresses: BaseProblem {
    private:
    std::vector<std::string> restoreIpAddresses(std::string s);
    public:
    void Run() override;
};



#endif //LEETCODE93RESTOREIPADDRESSES_H
