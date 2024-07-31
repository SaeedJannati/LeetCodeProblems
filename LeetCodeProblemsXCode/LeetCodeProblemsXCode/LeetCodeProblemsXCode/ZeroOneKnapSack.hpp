//
//  ZeroOneKnapSack.hpp
//  LeetCodeProblemsXCode
//
//  Created by Saeed Jannati on 5/10/1403 AP.
//

#ifndef ZeroOneKnapSack_hpp
#define ZeroOneKnapSack_hpp

#include <stdio.h>
#include <iostream>
#include "BaseProblem.hpp"

#endif /* ZeroOneKnapSack_hpp */

class ZeroOneKnapSack: BaseProblem
{
public:
    void Run()override;
private:
    int knapSack(int W, int wt[], int val[], int n);
        
};
