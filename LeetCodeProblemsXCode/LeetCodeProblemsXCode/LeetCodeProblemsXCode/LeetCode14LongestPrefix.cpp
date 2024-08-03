//
//  LeetCode14LongestPrefix.cpp
//  LeetCodeProblemsXCode
//
//  Created by Saeed Jannati on 5/13/1403 AP.
//

#include "LeetCode14LongestPrefix.hpp"

void LeetCode14LongestPrefix::Run()
{
    
    std::vector<std::string> input;
    input.assign({"dog","racecar","car"} );
    const auto outPut=longestCommonPrefix(input);
    std::cout<<outPut<<'\n';
}

std::string  LeetCode14LongestPrefix::longestCommonPrefix(std::vector<std::string> &strs)
{
    std::string outPut("");
    int counter=0;
    int inputCount=static_cast<int>(strs.size());
    char currentChar;
    bool shouldContinue=true;
    bool shouldAdd=false;
    while (shouldContinue) {
        for (int i=0; i<inputCount; i++) {
            shouldAdd=true;
            if(counter>=strs[i].size())
            {
                shouldContinue=false;
                shouldAdd=false;
                break;
            }
            
            if(i==0)
                currentChar=strs[i][counter];
            else if(strs[i][counter] != currentChar)
            {
                shouldContinue=false;
                shouldAdd=false;
                break;
            }
            
        }
        if(shouldAdd)
            outPut+=currentChar;
        counter++;
    }
    return outPut;
}
