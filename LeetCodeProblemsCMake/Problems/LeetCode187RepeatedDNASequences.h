//
// Created by saeed on 6/2/25.
//

#ifndef LEETCODE187REPEATEDDNASEQUENCES_H
#define LEETCODE187REPEATEDDNASEQUENCES_H
#include <string>
#include <vector>

#include "BaseProblem.h"


class LeetCode187RepeatedDNASequences: BaseProblem {
    std::vector<std::string> findRepeatedDnaSequences(std::string s);
    public:
    void Run() override;
};



#endif //LEETCODE187REPEATEDDNASEQUENCES_H
