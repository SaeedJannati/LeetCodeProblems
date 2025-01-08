#pragma once
#include <string>
#include <vector>

#include "BaseProblem.h"

class LeetCode3042CountPrefixAndSuffixPairsI: BaseProblem
{
private:
    int countPrefixSuffixPairs(std::vector<std::string>& words);
public:
    void Run() override;
};
