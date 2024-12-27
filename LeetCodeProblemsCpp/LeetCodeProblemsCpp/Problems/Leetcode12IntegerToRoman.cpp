#include "Leetcode12IntegerToRoman.h"

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

void Leetcode12IntegerToRoman::Run()
{
    const int input = 3749;
    const std::string roman = intToRoman(input);
    std::cout << roman << '\n';
}

std::string Leetcode12IntegerToRoman::intToRoman(int num)
{
    std::string roman;
    int counter(0);
    int currentDigit = 0;
    int currentAmount = 0;
    std::unordered_map<int, std::string> romanToIntMap{
        {1, "I"},
        {5, "V"},
        {10, "X"},
        {50, "L"},
        {100, "C"},
        {500, "D"},
        {1000, "M"}
    };
    std::vector<int> numsOrdered{1, 5, 10, 50, 100, 500, 1000};
    std::vector<std::string> numsTranslated{};
    int numsSize = static_cast<int>(numsOrdered.size());
    std::string currentDigitTranslating;
    int deltaAmount(0);
    int powerOfTen(0);
    while (num > 0)
    {
        currentDigit = num % 10;
        powerOfTen=static_cast<int>(std::pow(10, counter));
        currentAmount = currentDigit *powerOfTen ;
        if (currentAmount < 1000)
        {
            if (currentDigit == 4 || currentDigit == 9)
            {
                currentAmount = (currentDigit + 1) * powerOfTen;
                currentDigitTranslating=romanToIntMap[powerOfTen];
                currentDigitTranslating+=romanToIntMap[currentAmount];
                numsTranslated.push_back(currentDigitTranslating);
                currentAmount=0;
            }
        }
        currentDigitTranslating="";
        while (currentAmount>0)
        {
            deltaAmount=GetClosestLesserNum(currentAmount,numsOrdered,numsSize);
            currentDigitTranslating+=romanToIntMap[deltaAmount];
            currentAmount-=deltaAmount;
        }
        numsTranslated.push_back(currentDigitTranslating);
        num /= 10;
        counter++;
    }
    for (int i=static_cast<int> (numsTranslated.size())-1;i>=0;i--)
    {
        roman+=numsTranslated[i];
    }
        
    return roman;
}

int Leetcode12IntegerToRoman::GetClosestLesserNum(int num, std::vector<int>& nums, int numsSize)
{
    int lowerEdge(0);
    int higherEdge(numsSize - 1);
    int currentMid(0);
    while (true)
    {
        currentMid = (lowerEdge + higherEdge) / 2;
        if (currentMid == lowerEdge)
        {
            if (num >= nums[higherEdge])
                return nums[higherEdge];
            return nums[lowerEdge];
        }
        if (num == nums[currentMid])
            return nums[currentMid];
        if (num > nums[currentMid])
        {
            lowerEdge = currentMid;
            continue;
        }
        higherEdge = currentMid;
    }
}
