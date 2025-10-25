#include "LeetCode1716CalculateMoneyInLeetcodeBank.h"

#include <iostream>

int LeetCode1716CalculateMoneyInLeetcodeBank::totalMoney(int n)
{
    auto res=   n/7*28;
    res+=(n/7-1)*(n/7)*7/2;
    res+=(n%7)*((n%7)+1)/2;
    res+=+(n/7>0)?(n/7)*(n%7):0;
    return res;
}

void LeetCode1716CalculateMoneyInLeetcodeBank::Run()
{
    const int n = 10;
    std::cout<< totalMoney(n)<<'\n';
}
