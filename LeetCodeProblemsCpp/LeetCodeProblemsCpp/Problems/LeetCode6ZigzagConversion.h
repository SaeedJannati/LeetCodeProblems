﻿#pragma once
#include <string>

#include "BaseProblem.h"

class LeetCode6ZigzagConversion: BaseProblem
{
public:
    void Run() override;
private:
    std::string convert(std::string s, int numRows);
};
