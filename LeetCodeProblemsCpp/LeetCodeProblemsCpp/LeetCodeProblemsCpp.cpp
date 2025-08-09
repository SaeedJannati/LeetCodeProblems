#include <iostream>

#include "Problems/Auxilaries.h"
#include "Problems/LeetCode1233RemoveSubFoldersFromTheFilesystem.h"
#include "Problems/LeetCode2106MaximumFruitsHarvestedAfterAtMostKSteps.h"
#include "Problems/LeetCode2210CountHillsAndValleysInAnArray.h"
#include "Problems/LeetCode231PowerOfTwo.h"
#include "Problems/LeetCode2411SmallestSubarraysWithMaximumBitwiseOR.h"
#include "Problems/LeetCode3479FruitsIntoBasketsIII.h"
#include "Problems/LeetCode907SumOfSubarrayMinimums.h"
#include "Problems/ScriptNamePrinter.h"


int main(int argc, char* argv[])
{
    const auto problem = new LeetCode231PowerOfTwo();
    problem->Run();
    delete problem;
#pragma  region  print script name
    std::cout<<'\n';
    const std::string scriptName = "231. Power of Two";
    ScriptNamePrinter::PrintScriptName(scriptName);
#pragma endregion
#pragma region convert to vector
    std::string input="[[0,7],[7,4],[9,10],[12,6],[14,8],[16,5],[17,8],[19,4],[20,1],[21,3],[24,3],[25,3],[26,1],[28,10],[30,9],[31,6],[32,1],[37,5],[40,9]]";
    Auxilaries::ConvertToVector(input);
#pragma endregion
}



