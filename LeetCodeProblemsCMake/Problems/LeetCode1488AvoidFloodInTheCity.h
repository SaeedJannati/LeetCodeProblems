//
// Created by saeed on 10/7/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE1488AVOIDFLOODINTHECITY_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE1488AVOIDFLOODINTHECITY_H
#include <vector>

#include "BaseProblem.h"


class LeetCode1488AvoidFloodInTheCity : BaseProblem{
private:
    std::vector<int> avoidFlood(std::vector<int>& rains);
public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE1488AVOIDFLOODINTHECITY_H