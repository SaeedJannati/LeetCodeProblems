#include "LeetCode2011FinalValueOfVariableAfterPerformingOperations.h"

int LeetCode2011FinalValueOfVariableAfterPerformingOperations::finalValueAfterOperations(std::vector<std::string>& operations)
{
    int result{};
    for (auto & operation : operations)
    {
        for (auto c:operation)
        {
            if (c == '+')
            {
                result++;
                break;
            }
            if (c == '-')
            {
                result--;
                break;
            }
        }
    }
    return result;
}
