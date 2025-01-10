//
// Created by saeed on 1/10/25.
//

#ifndef LEETCODE1404NUMBEROFSTEPSTOREDUCEANUMBERINBINARYREPRESENTATIONTOONE_H
#define LEETCODE1404NUMBEROFSTEPSTOREDUCEANUMBERINBINARYREPRESENTATIONTOONE_H
#include <string>

#include "BaseProblem.h"


class LeetCode1404NumberOfStepsToReduceANumberInBinaryRepresentationToOne : BaseProblem {
private:
    int numSteps(std::string s);

public:
    void Run() override;
};


#endif //LEETCODE1404NUMBEROFSTEPSTOREDUCEANUMBERINBINARYREPRESENTATIONTOONE_H
