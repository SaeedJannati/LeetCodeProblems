//
//  LeetCode13RomanToInteger.cpp
//  LeetCodeProblemsXCode
//
//  Created by Saeed Jannati on 5/13/1403 AP.
//

#include "LeetCode13RomanToInteger.hpp"

void LeetCode13RomanToInteger::Run()
{
    std::string input="MCMXCIV";
    const auto outPut=romanToInt(input);
    std::cout<<outPut<<'\n';
}

int LeetCode13RomanToInteger::romanToInt(std::string s)
{
    
    std::map<char,int> charValues{
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    const auto size=static_cast<int>(s.size());
    int totalAmount(0);
    
    for (int i=0; i<size; i++) {
        if(i<size-1)
        {
            if(charValues[s[i+1]]>charValues[s[i]])
            {
                totalAmount-=charValues[s[i]];
                continue;
            }
        }
        totalAmount+=charValues[s[i]];
    }
    
    return totalAmount;
}


