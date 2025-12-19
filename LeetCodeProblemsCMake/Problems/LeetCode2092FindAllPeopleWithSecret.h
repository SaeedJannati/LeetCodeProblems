//
// Created by saeed on 12/19/25.
//

#ifndef LEETCODEPROBLEMSCMAKE_LEETCODE2092FINDALLPEOPLEWITHSECRET_H
#define LEETCODEPROBLEMSCMAKE_LEETCODE2092FINDALLPEOPLEWITHSECRET_H
#include <vector>

#include "BaseProblem.h"


class LeetCode2092FindAllPeopleWithSecret: BaseProblem {
private:
    std::vector<int> findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson);
    public:
    void Run() override;
};


#endif //LEETCODEPROBLEMSCMAKE_LEETCODE2092FINDALLPEOPLEWITHSECRET_H