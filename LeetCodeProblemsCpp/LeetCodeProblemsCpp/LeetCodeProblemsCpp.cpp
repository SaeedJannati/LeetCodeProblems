#include <iostream>

#include "Problems/LeetCode1422MaximumScoreAfterSplittingAString.h"
#include "Problems/LeetCode2116CheckIfAParenthesesStringCanBeValid.h"
#include "Problems/LeetCode2381ShiftingLettersII.h"
#include "Problems/LeetCode3042CountPrefixAndSuffixPairsI.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode2116CheckIfAParenthesesStringCanBeValid();
    problem->Run();
    delete problem;
}
