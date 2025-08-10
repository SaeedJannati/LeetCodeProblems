#include "LeetCode869ReorderedPowerOf2.h"

#include <iostream>
#include <vector>
using namespace std;

bool backTrack(vector<int>& digits, vector<bool>& used, long num, int length, int currentLength)
{
    if (currentLength == length)
    {
       if ((num&(num-1))==0) 
        {
            return true;
        }
        return false;
    }
    int lastNum=-1;
    for (int i=0;i<length;i++)
    {
        if (used[i])
            continue;
        if (digits[i]==lastNum)
            continue;
        lastNum=digits[i];
        auto newNum=num*10+digits[i];
        used[i]=true;
        if (backTrack(digits, used, newNum, length, currentLength + 1))
        {
            used[i]=false;
            return true;
        }
        used[i]=false;
    }
    return false;
}

bool LeetCode869ReorderedPowerOf2::reorderedPowerOf2(int n)
{
    vector<int> digits{};
    while (n > 0)
    {
        digits.push_back(n % 10);
        n /= 10;
    }
    int length = static_cast<int>( digits.size());
    vector<bool> used(length, false);
    for (int i = 0; i < length; i++)
    {
        if (digits[i] == 0)
            continue;
        long num = digits[i];
        used[i] = true;
        if (backTrack(digits, used, num, length, 1))
        {
            return true;
        }
        used[i] = false;
    }
    return false;
}

void LeetCode869ReorderedPowerOf2::Run()
{
    int n=218;
    bool result = reorderedPowerOf2(n);
    cout << "Result: " << (result ? "true" : "false") << '\n';
}
