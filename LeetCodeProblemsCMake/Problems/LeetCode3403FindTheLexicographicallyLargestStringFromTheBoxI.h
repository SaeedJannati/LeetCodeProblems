//
// Created by saeed on 6/4/25.
//

#ifndef LEETCODE3403FINDTHELEXICOGRAPHICALLYLARGESTSTRINGFROMTHEBOXI_H
#define LEETCODE3403FINDTHELEXICOGRAPHICALLYLARGESTSTRINGFROMTHEBOXI_H
#include <string>

#include "BaseProblem.h"


class LeetCode3403FindTheLexicographicallyLargestStringFromTheBoxI: BaseProblem {
    private:
    std::string answerString(std::string word, int numFriends);
    public:
    void Run() override;
};



#endif //LEETCODE3403FINDTHELEXICOGRAPHICALLYLARGESTSTRINGFROMTHEBOXI_H
