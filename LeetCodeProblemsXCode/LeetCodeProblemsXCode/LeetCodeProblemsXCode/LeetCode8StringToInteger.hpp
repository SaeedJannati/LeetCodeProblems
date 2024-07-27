//
//  LeetCode8StringToInteger.hpp
//  LeetCodeProblemsXCode
//
//  Created by Saeed Jannati on 5/6/1403 AP.
//

#ifndef LeetCode8StringToInteger_hpp
#define LeetCode8StringToInteger_hpp

#include <stdio.h>
#include <iostream>
#include "BaseProblem.hpp"

#endif /* LeetCode8StringToInteger_hpp */



class LeetCode8StringToInteger: BaseProblem
{
public:
    void Run() override;
private:
    int MyAtoi(std::string s);
};
