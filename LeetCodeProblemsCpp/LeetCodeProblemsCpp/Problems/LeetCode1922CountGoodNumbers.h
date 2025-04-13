#pragma once
#include <iostream>

#include "BaseProblem.h"

class LeetCode1922CountGoodNumbers: BaseProblem
{
private:
    const int MOD = 1e9 + 7;

    long long pow(long long a, long long b)
    {
        long long power = 1;
        long long current=a;
        long long result=1;
        while (power<=b)
        {
            if (b&power)
            {
                result *= current;
                result %= MOD;
            }
            current *= current;
            current %= MOD;
            power <<= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n)
    {
        long long powFour = n / 2;
        long long powFive = n - n / 2;
        long long result = pow(4, powFour);
        result %= MOD;
        result *= (pow(5, powFive) % MOD);
        result %= MOD;
        return result;
    }
    public:
    void Run() override
    {
        int n=50;
        std::cout<<countGoodNumbers(n)<<'\n';
    }
};
