//
//  LeetCode14LongestPrefix.hpp
//  LeetCodeProblemsXCode
//
//  Created by Saeed Jannati on 5/13/1403 AP.
//

#ifndef LeetCode14LongestPrefix_hpp
#define LeetCode14LongestPrefix_hpp

#include <stdio.h>
#include <iostream>
#include "BaseProblem.hpp"
#include <vector>
#endif /* LeetCode14LongestPrefix_hpp */
class LeetCode14LongestPrefix: BaseProblem
{
public:
    void Run() override;
private:
    std::string longestCommonPrefix(std::vector<std::string>& strs);
};
