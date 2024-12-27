#include "Leetcode50PowXN.h"

#include <iostream>
#include <ostream>

void Leetcode50PowXN::Run()
{
    double x=-3;
    int n=-5;
    std::cout << myPow(x,n) << std::endl;
}

double Leetcode50PowXN::myPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (x == 1.0)
        return 1.0;
    if (x == -1.0)
        return n % 2 == 0 ? 1.0 : -1.0;
    double base = n > 0 ? x : 1 / x;
    unsigned pow=n>0 ? n : -n;
    double outPut=base;
    for (int i = 0; i <pow; i++ )
        outPut*=base;
    return  outPut;

}
