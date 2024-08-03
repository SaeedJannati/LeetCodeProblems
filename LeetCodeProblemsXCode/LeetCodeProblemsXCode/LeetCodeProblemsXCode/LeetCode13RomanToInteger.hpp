//
//  LeetCode13RomanToInteger.hpp
//  LeetCodeProblemsXCode
//
//  Created by Saeed Jannati on 5/13/1403 AP.
//

#ifndef LeetCode13RomanToInteger_hpp
#define LeetCode13RomanToInteger_hpp

#include <stdio.h>
#include "BaseProblem.hpp"
#include <iostream>
#include <map>
#endif /* LeetCode13RomanToInteger_hpp */

class LeetCode13RomanToInteger: BaseProblem
{
public:
    void Run() override;
private:
    int romanToInt(std::string s);
};

