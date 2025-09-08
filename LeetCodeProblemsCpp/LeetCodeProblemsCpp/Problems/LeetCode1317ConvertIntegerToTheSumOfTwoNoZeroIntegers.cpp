#include "LeetCode1317ConvertIntegerToTheSumOfTwoNoZeroIntegers.h"

#include <string>
using namespace std;

vector<int> LeetCode1317ConvertIntegerToTheSumOfTwoNoZeroIntegers::getNoZeroIntegers(int n)
{
    vector<int> result{};
    for (int i = 0; i <= n / 2; i++)
    {
        if (to_string(i).find('0') == string::npos && to_string(n - i).find('0') == string::npos)
            return {i, n - i};
    }
    return {};
}
