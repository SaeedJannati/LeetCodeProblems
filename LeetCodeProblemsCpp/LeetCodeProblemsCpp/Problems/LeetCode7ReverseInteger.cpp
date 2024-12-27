#include "LeetCode7ReverseInteger.h"

#include <iostream>
#include <vector>

void LeetCode7ReverseInteger::Run()
{
    int input = -2147483648;
    int outPut = reverse(input);
    std::cout << outPut;
}

int LeetCode7ReverseInteger::reverse(int x)
{
    int32_t maxInt32 = x>0? std::numeric_limits<int32_t>::max():std::numeric_limits<int32_t>::min();
    auto maxFormated = GetFormatedNumber(maxInt32);
    auto xFormated = GetFormatedNumber(x);
    ReverseFormatedNumber(xFormated);
    if (IsGreaterThan(xFormated, maxFormated))
        return 0;
    int outPut = 0;
    bool hasNoneZeroBefore = false;
    int size=xFormated.size();
    for (int i = size-1; i >= 0; i--)
    {
        if (xFormated[i] == 0)
        {
            if (!hasNoneZeroBefore)
                continue;
        }
        else
        {
            hasNoneZeroBefore = true;
        }

        outPut += xFormated[i] * static_cast<int>(std::pow(10, i));
    }
    if(x<0)
        outPut=-outPut;
    return outPut;
}
void LeetCode7ReverseInteger::ReverseFormatedNumber(std::vector<unsigned char>& formatedNumber)
{
    unsigned char temp;
    int length=formatedNumber.size();
    for (int i=0;i<length/2;i++)
    {
        temp=formatedNumber[i];
        formatedNumber[i]=formatedNumber[length-i-1];
        formatedNumber[length-i-1]=temp;
    }
}
std::vector<unsigned char> LeetCode7ReverseInteger::GetFormatedNumber(int x)
{
    std::vector<unsigned char> output;
    int mod=0;
    while (x!=0)
    {
         mod=x%10;
        if(mod<0)
            mod=-mod;
        output.push_back(mod);
        x /= 10;
    }
    return output;
}

bool LeetCode7ReverseInteger::IsGreaterThan(std::vector<unsigned char> first, std::vector<unsigned char> second)
{
    if(first.size()<10)
        return false;
    for (int i = 9; i >= 0; i--)
    {
        if (first[i] > second[ i])
            return true;
        if (first[i] < second[i])
            return false;
    }
    return false;
}
