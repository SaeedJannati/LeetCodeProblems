//
// Created by saeed on 3/17/25.
//

#ifndef LEETCODE318MAXIMUMPRODUCTOFWORDLENGTHS_H
#define LEETCODE318MAXIMUMPRODUCTOFWORDLENGTHS_H
#include <string>
#include <vector>

#include "BaseProblem.h"


class LeetCode318MaximumProductOfWordLengths : BaseProblem {
private:
    int maxProduct(std::vector<std::string> &words);
    public:
    void Run() override;
};


#endif //LEETCODE318MAXIMUMPRODUCTOFWORDLENGTHS_H
