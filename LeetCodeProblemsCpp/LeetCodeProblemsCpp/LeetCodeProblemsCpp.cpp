#include <iostream>

#include "Problems/Auxilaries.h"
#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode1716CalculateMoneyInLeetcodeBank.h"
#include "Problems/LeetCode2197ReplaceNonCoprimeNumbersInArray.h"
#include "Problems/LeetCode2257CountUnguardedCellsInTheGrid.h"
#include "Problems/LeetCode3318FindXSumOfAllKLongSubarraysI.h"
#include "Problems/LeetCode3346MaximumFrequencyOfAnElementAfterPerformingOperationsI.h"
#include "Problems/LeetCode3381MaximumSubarraySumWithLengthDivisibleByK.h"
#include "Problems/LeetCode966VowelSpellchecker.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode3381MaximumSubarraySumWithLengthDivisibleByK();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "3381. Maximum Subarray Sum With Length Divisible by K";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[0,0],[1,1],[2,3]]";
    Auxilaries::ConvertToVector(input);
#pragma endregion
}



