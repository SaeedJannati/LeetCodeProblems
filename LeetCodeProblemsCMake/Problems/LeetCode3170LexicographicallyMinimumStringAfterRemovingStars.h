//
// Created by saeed on 6/7/25.
//

#ifndef LEETCODE3170LEXICOGRAPHICALLYMINIMUMSTRINGAFTERREMOVINGSTARS_H
#define LEETCODE3170LEXICOGRAPHICALLYMINIMUMSTRINGAFTERREMOVINGSTARS_H
#include <string>

#include "BaseProblem.h"


class LeetCode3170LexicographicallyMinimumStringAfterRemovingStars: BaseProblem {
    private:
    std::string clearStars(std::string s);
    public:
    void Run() override;
};



#endif //LEETCODE3170LEXICOGRAPHICALLYMINIMUMSTRINGAFTERREMOVINGSTARS_H
