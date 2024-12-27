#include "LeetCode9PalindromeNumber.h"

#include <iostream>
#include <string>


void LeetCode9PalindromeNumber::Run()
{
    const int input=-121;
    bool outPut= isPalindrome(input);
    std::cout<<outPut;
}
bool LeetCode9PalindromeNumber::isPalindrome(int x)
{
    if(x<0)
        return false;
    if(x<10)
        return true;
    std::string inputString=std::to_string(x);
    int size=inputString.size();
    for (int i=0,e=size/2;i<e;i++)
    {
        if(inputString[i]!=inputString[size-1-i])
            return false;
    }
    return true;
}

