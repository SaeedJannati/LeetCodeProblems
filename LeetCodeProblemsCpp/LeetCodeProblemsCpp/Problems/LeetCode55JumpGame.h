#pragma once
#include <vector>

#include "BaseProblem.h"

class LeetCode55JumpGame: BaseProblem
{
public:
    void Run() override;
private:
    bool canJump(std::vector<int>& nums);
    
};
