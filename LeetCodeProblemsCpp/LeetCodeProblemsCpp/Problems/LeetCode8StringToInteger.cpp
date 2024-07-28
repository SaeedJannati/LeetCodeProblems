#include "LeetCode8StringToInteger.h"

#include <iostream>
#include <vector>

void LeetCode8StringToInteger::Run()
{
    auto input = "  +  413";
    int outPut = myAtoi(input);
    std::cout << outPut;
}

int LeetCode8StringToInteger::myAtoi(std::string s)
{
    bool hasReachedNoneZero = false;
    bool hasReachedNumberbefore = false;
    std::vector<unsigned char> extractedNumbers;
    bool capturedSign = false;
    bool isPositive = true;
    for (int i = 0, length = static_cast<int>(s.length()); i < length; i++)
    {
        if (!hasReachedNumberbefore)
            switch (s[i])
            {
            case ' ':
                if(capturedSign)
                    return ConvertExtractedNumbers(extractedNumbers, isPositive);
                continue;
            case '-':
                if (capturedSign)
                    return ConvertExtractedNumbers(extractedNumbers, isPositive);
                capturedSign = true;
                isPositive = false;
                continue;
            case '+':
                if (capturedSign)
                    return ConvertExtractedNumbers(extractedNumbers, isPositive);
                capturedSign = true;
                isPositive = true;
                continue;
            }
        if (s[i] < '0' || s[i] > '9')
            return ConvertExtractedNumbers(extractedNumbers, isPositive);
        hasReachedNumberbefore = true;
        if (s[i] > '0' && s[i] <= '9')
            hasReachedNoneZero = true;
        if (s[i] == '0' && !hasReachedNoneZero)
            continue;
        extractedNumbers.push_back(s[i] - '0');
    }
    return ConvertExtractedNumbers(extractedNumbers, isPositive);
}

int LeetCode8StringToInteger::ConvertExtractedNumbers(std::vector<unsigned char>& extractedNumbers, bool isPositive)
{
    int outPut = 0;
    const int size = static_cast<int>(extractedNumbers.size());
    if (size == 0)
        return outPut;
    ReverseFormatedNumber(extractedNumbers);
    int32_t maxInt32 = isPositive ? std::numeric_limits<int32_t>::max() : std::numeric_limits<int32_t>::min();
    auto maxFormated = GetFormatedNumber(maxInt32);
    if (IsGreaterThan(extractedNumbers, maxFormated))
        return maxInt32;
    for (int i = size - 1; i >= 0; i--)
    {
        outPut +=(isPositive?+1:-1)* extractedNumbers[i] * static_cast<int>(std::pow(10, i));
    }
    return outPut;
}

void LeetCode8StringToInteger::ReverseFormatedNumber(std::vector<unsigned char>& formatedNumber)
{
    unsigned char temp;
    int length =static_cast<int>(formatedNumber.size());
    for (int i = 0; i < length / 2; i++)
    {
        temp = formatedNumber[i];
        formatedNumber[i] = formatedNumber[length - i - 1];
        formatedNumber[length - i - 1] = temp;
    }
}

bool LeetCode8StringToInteger::IsGreaterThan(std::vector<unsigned char> first, std::vector<unsigned char> second)
{
    if (first.size() < 10)
        return false;
    if(first.size()>10)
        return true;
    for (int i = 9; i >= 0; i--)
    {
        if (first[i] > second[i])
            return true;
        if (first[i] < second[i])
            return false;
    }
    return false;
}

std::vector<unsigned char> LeetCode8StringToInteger::GetFormatedNumber(int x)
{
    std::vector<unsigned char> output;
    int mod = 0;
    while (x != 0)
    {
        mod = x % 10;
        if (mod < 0)
            mod = -mod;
        output.push_back(mod);
        x /= 10;
    }
    return output;
}
