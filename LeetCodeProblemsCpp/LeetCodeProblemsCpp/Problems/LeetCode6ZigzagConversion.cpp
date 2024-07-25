#include "LeetCode6ZigzagConversion.h"

#include <iostream>
#include <vector>

void LeetCode6ZigzagConversion::Run()
{
    std::string input = "PAYPALISHIRING";
    int numRows = 3;
    const auto outPut = convert(input, numRows);
    std::cout << outPut;
}

std::string LeetCode6ZigzagConversion::convert(std::string s, int numRows)
{
    const int length = s.length();
    std::string outPut("");
    std::vector<std::string> orderedString(numRows, std::string(""));
    int modOfIndex = 0;
    const int rowPlusZigzagLength = numRows + (numRows > 2 ? numRows - 2 : 0);
    for (int i = 0; i < length; i++)
    {
        modOfIndex = i % rowPlusZigzagLength;
        if (modOfIndex >= numRows)
            modOfIndex = numRows - (modOfIndex - numRows + 2);
        orderedString[modOfIndex] += s[i];
    }
    for (auto i = orderedString.begin(); i < orderedString.end(); ++i)
        outPut += *i;
    return  outPut;
}
